#version 410 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 col;
out vec3 interpolated_color;

void main()
{
    gl_Position = vec4 (pos, 1.0);
    interpolated_color = col;
}
