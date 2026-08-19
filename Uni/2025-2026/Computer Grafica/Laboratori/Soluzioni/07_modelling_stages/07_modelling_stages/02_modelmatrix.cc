#define GLAD_GL_IMPLEMENTATION
#include "glad/gl.h"
#include <SFML/Window.hpp>
#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/component_wise.hpp>

#include <iostream>
#include <cstdlib>

#include "include/matrices.hh"
#include "include/mesh.hh"
#include "include/hotshaders.hh"
#include "include/trackball.hh"



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
    glm::vec3 light_direct_pos_relative = {2.0, 2.0, 0.0}; // xyz (relative to camera position)
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
    // xyz, camera position (fixed in world coordinates)
    glm::vec3 camera_pos = {0.0, 0.0, 0.0};
    GLint camera_pos_loc;
    // The Trackball contains the object rotation relative to the fixed camera position
    fcg::Trackball trackball;
    // object distance, relative to the fixed camera position
    float od;

public:
    Camera (fcg::Shaders& shaders)
    {
        locations (shaders);
        lens_normal ();
        set_window_size (Setup::window_width, Setup::window_height);
        view_projection ();
    }

    void locations (fcg::Shaders& shaders)
    {
        camera_pos_loc = glGetUniformLocation (shaders.program, "camera_pos");
    }

    void set_window_size (int w, int h)
    {
        trackball.set_window_size (w, h);
        ar = ((float) w) / (float) h;
        trackball.set_view (od, 1.0f / (fd * ar));
        view_projection ();
    }

    void start_rotate (float x, float y)
    {
        trackball.start (x, y);
    }

    void stop_rotate ()
    {
        trackball.stop ();
    }

    bool rotate (float x, float y)
    {
        bool moved = trackball.move (x, y);
        if (moved)
            view_projection ();
        return moved;
    }

    void zoom (float dy)
    {
        float ratio = fd / 100.0;
        fd += dy * ratio;
        if (fd < 0.1)
            fd = 0.1;
        trackball.set_view (od, 1.0f / (fd * ar));
        view_projection ();
    }

    void distance (float dy)
    {
        float ratio = od / 100.0;
        od -= dy * ratio; // note: we go in the opposite direction of zoooming
        if (od < 0.5)
            od = 0.5;
        trackball.set_view (od, 1.0f / (fd * ar));
        view_projection ();
    }

    void lens_tele ()
    {
        fd = tele_fd;
        od = tele_fd;
        trackball.set_view (od, 1.0f / (fd * ar));
        view_projection ();
    }

    void lens_normal ()
    {
        fd = normal_fd;
        od = normal_fd;
        trackball.set_view (od, 1.0f / (fd * ar));
        view_projection ();
    }

    void lens_wide ()
    {
        fd = wide_fd;
        od = wide_fd;
        trackball.set_view (od, 1.0f / (fd * ar));
        view_projection ();
    }

    void view_projection ()
    {
        float ncp = od - 4.0; // distance near clip plane
        if (ncp < 0.0001)
            ncp = 0.0001;
        float fcp = od + 4.0; // distance far clip plane

        // rotation matrix from trackball
        glm::mat4 r = trackball.rotation_matrix ();

        // prepare translation matrix
        glm::mat4 tz = fcg::translation (0.0, 0.0, -od);

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
        v = tz * r;
        vp = pr * v;
        inv_v = glm::inverse (v);

        glm::vec4 cp4 = {0.0, 0.0, 0.0, 1.0};
        cp4 = inv_v * cp4;
        glm::vec3 cp3 = {cp4.x, cp4.y, cp4.z};
        glUniform3fv(camera_pos_loc, 1, &cp3[0]);
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
    GPUMesh mesh;
    glm::mat4 mesh_mm;

private:
    GLint model_loc;
    GLint vp_loc;
    GLint tr_inv_model_loc;

public:
    Scene (std::string meshfile, fcg::Shaders& shaders) : camera (shaders), lights (shaders), mesh (meshfile) {
        locations (shaders);
        update_all ();
        mesh_mm = mesh.to_unit_extent;
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

        // glm::mat4 s = fcg::scaling (0.5); // uniform scaling (smaller mesh)
        glm::mat4 s = fcg::scaling (1.0, 1.0, 0.2); // flattened mesh!
        glm::mat4 rx90 = fcg::rotation_x (90); // rotate horizontally
        glm::mat4 tr1 = fcg::translation (0, -0.8, 0); // put it lower
        glm::mat4 full_mm = tr1 * rx90 * s * mesh_mm; // full model matrix

        glUniformMatrix4fv(model_loc, 1, GL_FALSE, &full_mm[0][0]);
        glUniformMatrix4fv(vp_loc, 1, GL_FALSE, &camera.vp[0][0]);

        glm::mat3 tr_inv_model = glm::transpose (glm::inverse (glm::mat3 (full_mm)));
        // what happens with a wrong matrix for normals? try it out
        //glm::mat3 tr_inv_model = glm::mat3 (full_mm);
        //glm::mat3 tr_inv_model = fcg::identity3 ();
        glUniformMatrix3fv (tr_inv_model_loc, 1, GL_FALSE, &tr_inv_model[0][0]);

        mesh.draw ();
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
        scene.lights.send_position_relative (scene.camera.inv_v);
        return;
    case sf::Keyboard::Scancode::T:
        scene.camera.lens_tele ();
        scene.lights.send_position_relative (scene.camera.inv_v);
        return;
    case sf::Keyboard::Scancode::W:
        scene.camera.lens_wide ();
        scene.lights.send_position_relative (scene.camera.inv_v);
        return;
    default:
        return;
    }
}

void handle (const sf::Event::MouseMoved& mouse_moved, Scene& scene)
{
    float x = mouse_moved.position.x;
    float y = mouse_moved.position.y;

    static float prev_y = 0;
    float dy = y - prev_y; 
    prev_y = y;

    if (scene.camera.rotate (x, y))
        scene.lights.send_position_relative (scene.camera.inv_v);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl)) {
        scene.camera.zoom (dy);
        scene.lights.send_position_relative (scene.camera.inv_v);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LAlt)) {
        scene.camera.distance (dy);
        scene.lights.send_position_relative (scene.camera.inv_v);
    }
}

void handle (const sf::Event::MouseButtonPressed& mouse_pressed, Camera& camera)
{
    if (mouse_pressed.button == sf::Mouse::Button::Left) {
        float x = mouse_pressed.position.x;
        float y = mouse_pressed.position.y;
        camera.start_rotate (x, y);
    }
}

void handle (const sf::Event::MouseButtonReleased& mouse_released, Camera& camera)
{
    if (mouse_released.button == sf::Mouse::Button::Left) {
        camera.stop_rotate ();
    }
}



//////////
// Main //
//////////

int main (int argc, char* argv[])
{
    // mandatory command line argument: mesh file to open
    std::string meshfile = "";
    if (argc > 1)
        meshfile = argv[1];
    else {
        std::cout << "Usage: "<<argv[0]<< " meshfile\n";
        exit (1);
    }


    //// Startup ////

    Setup setup;
    sf::Window& window = *setup.window;

    fcg::Shaders shaders ("shader_flat.vert", "shader_flat.frag");
    shaders.use ();

    Scene scene (meshfile, shaders);

    glEnable (GL_CULL_FACE);
    glCullFace (GL_BACK);

    glEnable (GL_DEPTH_TEST);


    //// Main Loop ////

    bool running = true;
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
            else if (const auto* mouse_pressed = event->getIf<sf::Event::MouseButtonPressed> ())
                handle (*mouse_pressed, scene.camera);
            else if (const auto* mouse_released = event->getIf<sf::Event::MouseButtonReleased> ())
                handle (*mouse_released, scene.camera);
            else if (const auto* mouse_moved = event->getIf<sf::Event::MouseMoved> ())
                handle (*mouse_moved, scene);
        }

        scene.draw ();
        window.display ();
    }

    return 0;
}
