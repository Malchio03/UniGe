#version 410 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 col;
uniform mat4 vp;

out vec3 interpolated_color;

void main()
{
    vec4 p;
    p = vec4 (pos, 1.0);
    gl_Position = vp * p;
    interpolated_color = col;
}
