#version 410 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 normal;

uniform mat4 model;
uniform mat4 vp;
uniform mat3 tr_inv_model; // transpose (inverse (model_matrix))

uniform vec3 camera_pos;

struct Light {
    vec3 direct_pos;
    vec3 direct_val;
    vec3 ambient_val;
};
uniform Light light;

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};
uniform Material material;

out vec3 interpolated_color;

void main()
{
    vec4 p = model * vec4 (pos, 1.0); // world space
    vec3 world_pos  = p.xyz;

    gl_Position = vp * p;

    vec3 nor = normalize (tr_inv_model * normal);

    // Ambient
    vec3 ambient = material.ambient * light.ambient_val;

    // Diffuse
    vec3 light_dir = normalize (light.direct_pos - world_pos);
    float diff = max (dot (nor, light_dir), 0.0);
    vec3 diffuse = material.diffuse * diff * light.direct_val;

    // Specular
    vec3 view_dir    = normalize (camera_pos - world_pos);
    vec3 reflect_dir = reflect (-light_dir, nor);
    float spec = pow (max (dot (view_dir, reflect_dir), 0.0), material.shininess);
    vec3 specular = material.specular * spec * light.direct_val;

    interpolated_color = ambient + diffuse + specular;
}
