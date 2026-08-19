#version 410 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 normal;

uniform mat4 model;
uniform mat4 vp;
uniform mat3 tr_inv_model; // transpose (inverse (model_matrix))

out vec3 interpolated_normal;

void main()
{
    vec4 p = model * vec4 (pos, 1.0); // world space
    gl_Position = vp * p;
    interpolated_normal = normalize (tr_inv_model * normal);

}
