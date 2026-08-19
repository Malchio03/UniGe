#version 410 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 normal;
uniform mat4 vp;

out vec3 interpolated_normal;

void main()
{
    vec4 p;
    p = vec4 (pos, 1.0);
    gl_Position = vp * p;
    interpolated_normal = normal;
}
