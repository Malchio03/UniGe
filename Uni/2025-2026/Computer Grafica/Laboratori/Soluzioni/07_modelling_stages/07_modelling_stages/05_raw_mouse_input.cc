#define GLAD_GL_IMPLEMENTATION
#include "glad/gl.h"
#include <SFML/Window.hpp>
#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/component_wise.hpp>

#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

#include "include/matrices.hh"
#include "include/mesh.hh"
#include "include/hotshaders.hh"
#include "include/trackball.hh"
#include "include/rawmouse.hh"



/////////////////////////////
// Window and OpenGL setup //
/////////////////////////////

class Setup
{
public:
    static const int window_width = 800;
    static const int window_height = 800;

    sf::Window* window;

    Setup ()
    {
        sf::ContextSettings settings;
        settings.depthBits = 32;
        settings.stencilBits = 8;
        settings.antiAliasingLevel = 4;
        settings.attributeFlags = sf::ContextSettings::Attribute::Core;
        settings.majorVersion = 4;
        settings.minorVersion = 1;

        window = new sf::Window (
                                 sf::VideoMode({window_width, window_height}),
                                 "SFML + OpenGL",
                                 sf::Style::Default,
                                 sf::State::Windowed,
                                 settings
                                 );
        window->setVerticalSyncEnabled (true);

        if (!window->setActive (true)) {
            std::cerr << "Failure: error during SFML OpenGL Activation." << std::endl;
            exit (1);
        }
        sf::ContextSettings gotten = window->getSettings ();

        std::cout << "depth bits: " << gotten.depthBits << std::endl;
        std::cout << "stencil bits: " << gotten.stencilBits << std::endl;
        std::cout << "antialiasing level: " << gotten.antiAliasingLevel << std::endl;
        std::cout << "SFML GL version: " << gotten.majorVersion << "." << gotten.minorVersion << std::endl;

        int version = gladLoadGL (sf::Context::getFunction);
        if (!version) {
            std::cerr << "Failure: error during glad loading." << std::endl;
            exit (1);
        }
        std::cout << "GLAD GL version: " << GLAD_VERSION_MAJOR(version) << "." << GLAD_VERSION_MINOR(version) << std::endl;
    }

    ~Setup ()
    {
        delete window;
    }
};



////////////////////
// Camera + World //
////////////////////

class Lights
{
public:
    glm::vec3 light_direct_pos_relative = {1.0, 1.0, 1.0}; // xyz (relative to camera position)
    glm::vec3 light_direct_pos = {0.0, 0.0, 0.0};   // xyz (absolute, in world coordinates)
    glm::vec3 light_direct_val = {1.0, 1.0, 1.0};   // rgb
    glm::vec3 light_ambient_val = {0.1, 0.1, 0.1};  // rgb
    glm::vec3 material_diffuse = {0.8, 0.7, 0.6};   // rgb
    glm::vec3 material_ambient = {0.5, 0.5, 0.8};   // rgb
    glm::vec3 material_specular = {1.0, 1.0, 1.0};  // rgb
    float material_shininess = 1000.0; // scalar

private:
    // lights and materials
    GLint light_direct_pos_loc;   // xyz
    GLint light_direct_val_loc;   // rgb
    GLint light_ambient_val_loc;  // rgb
    GLint material_diffuse_loc;   // rgb
    GLint material_ambient_loc;   // rgb
    GLint material_specular_loc;  // rgb
    GLint material_shininess_loc; // scalar

public:
    Lights (fcg::Shaders& shaders)
    {
        locations (shaders);
    }

    void locations (fcg::Shaders& shaders)
    {
        light_direct_pos_loc = glGetUniformLocation (shaders.program, "light.direct_pos");
        light_direct_val_loc = glGetUniformLocation (shaders.program, "light.direct_val");
        light_ambient_val_loc = glGetUniformLocation (shaders.program, "light.ambient_val");
        material_diffuse_loc = glGetUniformLocation (shaders.program, "material.diffuse");
        material_ambient_loc = glGetUniformLocation (shaders.program, "material.ambient");
        material_specular_loc = glGetUniformLocation (shaders.program, "material.specular");
        material_shininess_loc = glGetUniformLocation (shaders.program, "material.shininess");
    }

    void send_parameters ()
    {
        glUniform3fv (light_direct_val_loc, 1, &light_direct_val[0]);
        glUniform3fv (light_ambient_val_loc, 1, &light_ambient_val[0]);
        glUniform3fv (material_diffuse_loc, 1, &material_diffuse[0]);
        glUniform3fv (material_ambient_loc, 1, &material_ambient[0]);
        glUniform3fv (material_specular_loc, 1, &material_specular[0]);
        glUniform1fv (material_shininess_loc, 1, &material_shininess);
    }

    void send_position_relative (const glm::mat4& inverse_view_matrix)
    {
        glm::vec4 p = glm::vec4 (light_direct_pos_relative, 1.0);
        p = inverse_view_matrix * p;
        light_direct_pos = {p.x, p.y, p.z};
        send_position ();
    }

    void send_position ()
    {
        glUniform3fv (light_direct_pos_loc, 1, &light_direct_pos[0]);
    }
};


class Camera
{
public:
    glm::mat4 v;
    glm::mat4 inv_v;
    glm::mat4 vp;

private:

    /** Intrinsic camera parameters **/
    const float normal_fd = 50.0 / 18.0; 
    const float tele_fd =  400.0 / 18.0;
    const float wide_fd = 24 / 18.0;
    float fd; // focal distance
    float ar; // aspect ratio

    /** Extrinsic camera parameters **/
    // xyz, starting point of dynamic camera position
    glm::vec3 camera_pos = {0.0, 0.0, 2}; // xyz
    GLint camera_pos_loc; // xyz
    // Angles defining the in-place camera rotation
    float phi_deg = 0.0;
    float theta_deg = 0.0;

    /** Camera movement **/
    const float zoom_speed = 1.0;
    const float dolly_speed = 1.0;
    bool dolly_on = false;
    bool zoom_on = false;
    bool forward = false;
    bool pan_tilt_on = false;

public:
    Camera (fcg::Shaders& shaders)
    {
        locations (shaders);
        lens_wide ();
        set_window_size (Setup::window_width, Setup::window_height);
        view_projection ();
    }

    void locations (fcg::Shaders& shaders)
    {
        camera_pos_loc = glGetUniformLocation (shaders.program, "camera_pos");
    }

    void set_window_size (int w, int h)
    {
        ar = ((float) w) / (float) h;
        view_projection ();
    }

    bool pan_tilt_toggle ()
    {
        return pan_tilt_on = !pan_tilt_on;
    }

    void pan_tilt (float dx, float dy)
    {
        if (!pan_tilt_on)
            return;

        phi_deg += dx * 0.1;
        theta_deg += dy * 0.1;
        theta_deg = theta_deg > 90.0? 90.0 : theta_deg;
        theta_deg = theta_deg < -90.0? -90.0 : theta_deg;
        view_projection ();
    }

    void dolly_start (bool fw)
    {
        forward = fw;
        dolly_on = true;
    }

    void dolly_stop ()
    {
        dolly_on = false;
    }

    void dolly (float delta)
    {
        if (!dolly_on)
            return;

        float ds = forward? -dolly_speed : dolly_speed;
        float r = delta * ds;

        // // 2D movement on the xz plane, with y=0
        // float phi_rad = glm::radians (phi_deg);
        // float ps = glm::sin (phi_rad);
        // float pc = glm::cos (phi_rad);
        // camera_pos.x += r * -ps;
        // camera_pos.z += r * pc;

        // 3D movement
        float phi_rad = glm::radians (phi_deg);
        float ps = glm::sin (phi_rad);
        float pc = glm::cos (phi_rad);
        float theta_rad = glm::radians (theta_deg);
        float ts = glm::sin (theta_rad);
        float tc = glm::cos (theta_rad);
        camera_pos.x += r * tc * -ps;
        camera_pos.z += r * tc * pc;
        camera_pos.y += r * ts;

        view_projection ();
    }

    void zoom_start (bool fw)
    {
        forward = fw;
        zoom_on = true;
    }

    void zoom_stop ()
    {
        zoom_on = false;
    }

    // zoom
    void zoom (float delta)
    {
        if (!zoom_on)
            return;

        float zs = forward? zoom_speed : -zoom_speed;
        fd += delta * zs;
        if (fd < 0.1)
            fd = 0.1;
        view_projection ();
    }

    void lens_tele ()
    {
        fd = tele_fd;
        view_projection ();
    }

    void lens_normal ()
    {
        fd = normal_fd;
        view_projection ();
    }

    void lens_wide ()
    {
        fd = wide_fd;
        view_projection ();
    }

    void view_projection ()
    {
        const glm::vec3 cp = camera_pos;
        float od = glm::distance ({0.0, 0.0, 0.0}, cp);
        float ncp = od - 4.0; // distance near clip plane
        if (ncp < 0.0001)
            ncp = 0.0001;
        float fcp = od + 4.0; // distance far clip plane

        // prepare rotations and translation matrices
        glm::mat4 ry = fcg::rotation_y (phi_deg);
        glm::mat4 rx = fcg::rotation_x (theta_deg);
        glm::mat4 t = fcg::translation (-cp.x, -cp.y, -cp.z);

        // prepare projection matrix
        float a = (fcp + ncp) / (ncp - fcp);       // coefficient 3rd col
        float b = 2.0 * fcp * ncp / (ncp - fcp);   // coefficient 4th col

        glm::mat4 pr = glm::mat4(
                                 fd,  0.0,     0.0,  0.0,    // 1st column
                                 0.0, fd * ar, 0.0,  0.0,    // 2nd column
                                 0.0, 0.0,       a, -1.0,    // 3rd column
                                 0.0, 0.0,       b,  0.0     // 4th column
                                 );

        // Compute VP matrix and update it
        v = rx * ry * t;
        vp = pr * v;
        inv_v = glm::inverse (v);

        glUniform3fv(camera_pos_loc, 1, &cp[0]);
    }
};



class GPUMesh
{
public:
    glm::vec3 min_bounds;
    glm::vec3 max_bounds;
    glm::vec3 center;
    glm::vec3 extent;
    float span;
    glm::mat4 to_unit_extent; // normalization model matrix
    glm::vec3 unit_center;
    glm::vec3 unit_extent;
    float unit_span;

private:
    std::vector<float> points = {};
    std::vector<unsigned int> indices = {};

    GLuint vbo;
    GLuint ebo;
    GLuint vao;
    bool initialized = false;

public:
    GPUMesh (std::string filename){ load (filename); }

    ~GPUMesh () { clean (); }

    void load (std::string filename)
    {
        fcg::Mesh mesh (filename);
        mesh.pack4gpu (points, indices);
        send_arrays_2a3f ();

        min_bounds = mesh.min_bounds;
        max_bounds = mesh.max_bounds;
        center = (min_bounds + max_bounds) * 0.5f;
        span = glm::distance (max_bounds, min_bounds);
        extent = max_bounds - min_bounds;

        std::cout <<"MESH: "<< filename << "\n";
        std::cout <<"(original) center, extent, span:" << "\n";
        std::cout << center.x <<" "<< center.y <<" "<< center.z << "\n";
        std::cout << extent.x <<" "<< extent.y <<" "<< extent.z << "\n";
        std::cout << span << "\n";

        to_unit_extent =
            fcg::scaling (1.0 / glm::compMax (extent)) *
            fcg::translation (-center);

        unit_center = {0.0, 0.0, 0.0};
        unit_span = glm::distance (extent, {0.0, 0.0, 0.0});
        unit_extent = extent / glm::compMax (extent);

        std::cout <<"(unit normalized) center, extent, span:" << "\n";
        std::cout << unit_center.x <<" "<< unit_center.y <<" "<< unit_center.z << "\n";
        std::cout << unit_extent.x <<" "<< unit_extent.y <<" "<< unit_extent.z << "\n";
        std::cout << unit_span << "\n\n";

        initialized = true;
    }

    void clean ()
    {
        if (initialized) {
            glDeleteVertexArrays (1, &vao);
            glDeleteBuffers (1, &vbo);
        }
    }

    void draw ()
    {
        glBindVertexArray (vao);
        glDrawElements(GL_TRIANGLES, indices.size (), GL_UNSIGNED_INT, 0);
    }

protected:
    // send to the gpu the mesh arrays:
    // - the mesh vertices, 2 attributes, 3 floats each
    // - the mesh indices
    void send_arrays_2a3f ()
    {
        // we want just one buffer, and we retrieve the name OpenGL assigns to it.
        glGenBuffers (1, &vbo);
        // bind it as the current VBO
        glBindBuffer (GL_ARRAY_BUFFER, vbo);
        // transfer data from CPU RAM to GPU RAM.
        glBufferData (GL_ARRAY_BUFFER,
                      points.size () * sizeof (float),
                      points.data (),
                      GL_STATIC_DRAW);

        // we want just one buffer container, and we retrieve the name OpenGL assigns to it.
        glGenVertexArrays (1, &vao);
        // bind it as the current vao.
        glBindVertexArray (vao);

        // Attribute 0: position (x, y, z)
        glVertexAttribPointer (0,
                               3,
                               GL_FLOAT,
                               GL_FALSE,
                               6 * sizeof(float),
                               (void*)0);
        glEnableVertexAttribArray (0);

        // Attribute 1: 3 generic floats (u, v, w)
        glVertexAttribPointer (1,
                               3,
                               GL_FLOAT,
                               GL_FALSE,
                               6 * sizeof(float),
                               (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray (1);

        glGenBuffers(1, &ebo); 
        // MUST be bound after the VAO's binding!
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                     indices.size () * sizeof (unsigned int),
                     indices.data (),
                     GL_STATIC_DRAW);
    }
};


class Scene
{
public:
    Camera camera;
    Lights lights;

    GPUMesh cube;
    GPUMesh sphere;
    GPUMesh teapot;
    GPUMesh dragon;
    GPUMesh bunny;

private:
    GLint model_loc;
    GLint vp_loc;
    GLint tr_inv_model_loc;

public:
    Scene (std::string dirname, fcg::Shaders& shaders) :
        camera (shaders), lights (shaders),
        cube (dirname + "cube.off"),
        sphere (dirname + "sphere.off"),
        teapot (dirname + "teapot.off"),
        dragon (dirname + "dragon.off"),
        bunny (dirname + "bunny.off")
    {
        locations (shaders);
        update_all ();
    }

    void locations (fcg::Shaders& shaders)
    {
        camera.locations (shaders);
        lights.locations (shaders);

        model_loc = glGetUniformLocation (shaders.program, "model");
        vp_loc = glGetUniformLocation (shaders.program, "vp");
        tr_inv_model_loc = glGetUniformLocation (shaders.program, "tr_inv_model");
    }

    void update_all ()
    {
        camera.view_projection ();
        lights.send_parameters ();
        lights.send_position_relative (camera.inv_v);
    }

    void draw ()
    {
        // clear the buffers
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // the view-projection matrix is the same for all the scene
        glUniformMatrix4fv(vp_loc, 1, GL_FALSE, &camera.vp[0][0]);

        //draw_cube (fcg::identity ());

        glm::mat4 root = fcg::identity ();
        float floor = draw_half_room (root);

        glm::mat4 table_1_scale = fcg::scaling (0.6, 0.2, 0.6); // larger
        glm::mat4 table_1_position = fcg::translation (-0.55, 0.05 + floor, -0.55);
        glm::mat4 table_1_mm = table_1_position * table_1_scale * root;
        draw_table_with_objects (table_1_mm);

        glm::mat4 table_2_scale = fcg::scaling (0.5, 0.5, 0.5);
        glm::mat4 table_2_position = fcg::translation (-0.55, 0.125+floor, 0.55);
        glm::mat4 table_2_mm = table_2_position * table_2_scale * root;
        draw_table_with_objects (table_2_mm);

        glm::mat4 table_3_scale = fcg::scaling (0.3, 0.8, 0.3); // taller
        glm::mat4 table_3_position = fcg::translation (0.55, 0.2+floor, 0.55);
        glm::mat4 table_3_mm = table_3_position * table_3_scale * root;
        draw_table_with_objects (table_3_mm);

        glm::mat4 table_4_scale = fcg::scaling (0.5, 0.5, 0.5);
        glm::mat4 table_4_position = fcg::translation (0.55, 0.125+floor, -0.55);
        glm::mat4 table_4_mm = table_4_position * table_4_scale * root;
        draw_table_with_objects (table_4_mm);
    }

private:
    void draw_cube (glm::mat4 parent_mm)
    {
        glm::mat4 mm;
        glm::mat3 ti_mm;
        mm = parent_mm * cube.to_unit_extent;
        ti_mm = glm::transpose (glm::inverse (glm::mat3 (mm)));
        glUniformMatrix4fv(model_loc, 1, GL_FALSE, &mm[0][0]);
        glUniformMatrix3fv (tr_inv_model_loc, 1, GL_FALSE, &ti_mm[0][0]);
        cube.draw ();
    }

    void draw_sphere (glm::mat4 parent_mm)
    {
        glm::mat4 mm;
        glm::mat3 ti_mm;
        mm = parent_mm * sphere.to_unit_extent;
        ti_mm = glm::transpose (glm::inverse (glm::mat3 (mm)));
        glUniformMatrix4fv(model_loc, 1, GL_FALSE, &mm[0][0]);
        glUniformMatrix3fv (tr_inv_model_loc, 1, GL_FALSE, &ti_mm[0][0]);
        sphere.draw ();
    }

    void draw_teapot (glm::mat4 parent_mm)
    {
        glm::mat4 mm;
        glm::mat3 ti_mm;
        mm = parent_mm * teapot.to_unit_extent;
        ti_mm = glm::transpose (glm::inverse (glm::mat3 (mm)));
        glUniformMatrix4fv(model_loc, 1, GL_FALSE, &mm[0][0]);
        glUniformMatrix3fv (tr_inv_model_loc, 1, GL_FALSE, &ti_mm[0][0]);
        teapot.draw ();
    }

    void draw_dragon (glm::mat4 parent_mm)
    {
        glm::mat4 mm;
        glm::mat3 ti_mm;
        mm = parent_mm * dragon.to_unit_extent;
        ti_mm = glm::transpose (glm::inverse (glm::mat3 (mm)));
        glUniformMatrix4fv(model_loc, 1, GL_FALSE, &mm[0][0]);
        glUniformMatrix3fv (tr_inv_model_loc, 1, GL_FALSE, &ti_mm[0][0]);
        dragon.draw ();
    }

    void draw_bunny (glm::mat4 parent_mm)
    {
        glm::mat4 mm;
        glm::mat3 ti_mm;
        mm = parent_mm * bunny.to_unit_extent;
        ti_mm = glm::transpose (glm::inverse (glm::mat3 (mm)));
        glUniformMatrix4fv(model_loc, 1, GL_FALSE, &mm[0][0]);
        glUniformMatrix3fv (tr_inv_model_loc, 1, GL_FALSE, &ti_mm[0][0]);
        bunny.draw ();
    }

    // A floor with two walls, drawn in the unitary cube
    // It's half of a cube, but with faces that have a depth
    // returns floor level in world coordinates
    float draw_half_room (glm::mat4 parent_mm)
    {
        glm::mat4 scale, translate, mm;
        float depth = 0.04;
        float h_depth = depth * 0.5;
        float height = cube.extent.y * 0.8;
        float h_height = height * 0.5;

        //half_room_modeling = fcg::scaling (1.4, 0.45, 1.4);

        // draw floor
        scale = fcg::scaling (2.0, depth, 2.0); // flatten the cube!
        translate = fcg::translation (0, -h_height - h_depth, 0); // lower it down
        mm = parent_mm * translate * scale;
        draw_cube (mm);

        // draw back wall
        scale = fcg::scaling (2.0, height, depth); // flatten the cube!
        translate = fcg::translation (0, 0, -1.0 - h_depth); // push it away
        mm = parent_mm * translate * scale;
        draw_cube (mm);

        // draw side wall
        scale = fcg::scaling (depth, height, 2.0); // flatten the cube!
        translate = fcg::translation (-1.0 - h_depth, 0, 0); // push it to the left
        mm = parent_mm * translate * scale;
        draw_cube (mm);

        return -h_height;
    }

    float draw_table (glm::mat4 parent_mm)
    {
        glm::mat4 scale, translate, mm;
        float depth = 0.02;
        float h_depth = depth * 0.5;
        float height = cube.extent.y * 0.5;
        float h_height = height * 0.5;

        // draw table
        scale = fcg::scaling (1.0, depth, 1.0);
        translate = fcg::translation (0, h_height + h_depth, 0);
        mm = parent_mm * translate * scale;
        draw_cube (mm);

        // draw legs
        scale = fcg::scaling (depth, height, depth);
        translate = fcg::translation (-cube.extent.x * 0.5, 0, -cube.extent.z * 0.5);
        mm = parent_mm * translate * scale;
        draw_cube (mm);
        translate = fcg::translation (cube.extent.x * 0.5, 0, -cube.extent.z * 0.5);
        mm = parent_mm * translate * scale;
        draw_cube (mm);
        translate = fcg::translation (-cube.extent.x * 0.5, 0, cube.extent.z * 0.5);
        mm = parent_mm * translate * scale;
        draw_cube (mm);
        translate = fcg::translation (cube.extent.x * 0.5, 0, cube.extent.z * 0.5);
        mm = parent_mm * translate * scale;
        draw_cube (mm);

        return h_height + depth;
    }

    void draw_table_with_objects (glm::mat4 parent_mm)
    {
        glm::mat4 scale, translate, mm;

        float h = draw_table (parent_mm);
        float os = 0.3;
        float d = 0.25;

        scale = fcg::scaling (os);
        translate = fcg::translation (-d, h + (0.5 * os), -d);
        mm = parent_mm * translate * scale;
        draw_sphere (mm);

        scale = fcg::scaling (os);
        translate = fcg::translation (-d, h + (0.5 * os), d);
        mm = parent_mm * translate * scale;
        draw_bunny (mm);

        scale = fcg::scaling (os);
        translate = fcg::translation (d, h + (0.5 * os), -d);
        mm = parent_mm * translate * scale;
        draw_teapot (mm);

        scale = fcg::scaling (os);
        translate = fcg::translation (d, h + (0.5 * os), d);
        mm = parent_mm * translate * scale;
        draw_dragon (mm);
    }
};




////////////////////
// SFML Callbacks //
////////////////////

void handle (const sf::Event::Resized& resized, Camera& camera)
{
    glViewport (0, 0, resized.size.x, resized.size.y);
    camera.set_window_size (resized.size.x, resized.size.y);
}

void handle (const sf::Event::KeyPressed& key, fcg::Shaders& shaders, Scene& scene)
{
    switch (key.scancode) {
    case sf::Keyboard::Scancode::Escape:
        exit (0);
    case sf::Keyboard::Scancode::G:
        shaders.reload ("shader_gouraud.vert", "shader_gouraud.frag");
        shaders.use ();
        scene.locations (shaders);
        scene.update_all ();
        return;
    case sf::Keyboard::Scancode::P:
        shaders.reload ("shader_phong.vert", "shader_phong.frag");
        shaders.use ();
        scene.locations (shaders);
        scene.update_all ();
        return;
    case sf::Keyboard::Scancode::F:
        shaders.reload ("shader_flat.vert", "shader_flat.frag");
        shaders.use ();
        scene.locations (shaders);
        scene.update_all ();
        return;
    case sf::Keyboard::Scancode::C:
        shaders.reload ("shader_normals.vert", "shader_normals.frag");
        shaders.use ();
        scene.locations (shaders);
        scene.update_all ();
        return;
    case sf::Keyboard::Scancode::N:
        scene.camera.lens_normal ();
        return;
    case sf::Keyboard::Scancode::T:
        scene.camera.lens_tele ();
        return;
    case sf::Keyboard::Scancode::W:
        scene.camera.lens_wide ();
        return;
    case sf::Keyboard::Scancode::Space:
        scene.camera.dolly_start (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LAlt));
        return;
    case sf::Keyboard::Scancode::Equal:
        scene.camera.zoom_start (true);
        return;
    case sf::Keyboard::Scancode::Hyphen:
        scene.camera.zoom_start (false);
        return;
    default:
        return;
    }
}

void handle (const sf::Event::KeyReleased& key, fcg::Shaders& shaders, Scene& scene)
{
    switch (key.scancode) {
    case sf::Keyboard::Scancode::Space:
        scene.camera.dolly_stop ();
        return;
    case sf::Keyboard::Scancode::Equal:
        scene.camera.zoom_stop ();
        return;
    case sf::Keyboard::Scancode::Hyphen:
        scene.camera.zoom_stop ();
        return;
    default:
        return;
    }
}

void handle (sf::Vector2f delta, Camera& camera)
{
    camera.pan_tilt (delta.x, delta.y);
}

void handle (const sf::Event::MouseButtonPressed& mouse_pressed, Camera& camera, sf::Window& window)
{
    if (mouse_pressed.button == sf::Mouse::Button::Left) {
        bool pan_tilt_on = camera.pan_tilt_toggle ();
        window.setMouseCursorGrabbed (pan_tilt_on);
        window.setMouseCursorVisible (!pan_tilt_on);
    }
}




//////////
// Main //
//////////

int main (int argc, char* argv[])
{
    // mandatory command line argument: dirname where meshes are found
    std::string dirname = "";
    if (argc != 2) {
        std::cout << "Usage: "<<argv[0]<< " dirname\n";
        exit (1);
    }
    dirname = argv[1];
    if (dirname.empty() || dirname.back() != '/')
        dirname.push_back('/');


    //// Startup ////

    Setup setup;
    sf::Window& window = *setup.window;

    fcg::Shaders shaders ("shader_flat.vert", "shader_flat.frag");
    shaders.use ();

    Scene scene (dirname, shaders);

    glEnable (GL_CULL_FACE);
    glCullFace (GL_BACK);

    glEnable (GL_DEPTH_TEST);


    //// Main Loop ////

    sf::Clock clock;
    bool running = true;
    fcg::RawMouse raw_mouse;
    while (running)
    {
        while (const std::optional event = window.pollEvent ())
        {
            if (event->is<sf::Event::Closed> ())
                running = false;
            else if (const auto* resized = event->getIf<sf::Event::Resized> ())
                handle (*resized, scene.camera);
            else if (const auto* key_pressed = event->getIf<sf::Event::KeyPressed> ())
                handle (*key_pressed, shaders, scene);
            else if (const auto* key_released = event->getIf<sf::Event::KeyReleased> ())
                handle (*key_released, shaders, scene);
            else if (const auto* mouse_pressed = event->getIf<sf::Event::MouseButtonPressed> ())
                handle (*mouse_pressed, scene.camera, window);
            else if (const auto* mouse_moved_raw = event->getIf<sf::Event::MouseMovedRaw> ())
                raw_mouse.event (*mouse_moved_raw);
        }
        handle (raw_mouse.delta (), scene.camera);

        float elapsed = clock.restart().asSeconds();
        scene.camera.zoom (elapsed);
        scene.camera.dolly (elapsed);
        scene.lights.send_position_relative (scene.camera.inv_v);

        scene.draw ();
        window.display ();
    }

    return 0;
}
