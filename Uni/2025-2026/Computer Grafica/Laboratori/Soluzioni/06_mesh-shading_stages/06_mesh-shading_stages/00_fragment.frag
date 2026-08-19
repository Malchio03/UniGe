#version 410 core

in vec3 interpolated_color;
out vec4 fragment_color;

void main()
{
    // return the interpolated color for the fragment
    fragment_color = vec4 (interpolated_color, 1.0);
}
