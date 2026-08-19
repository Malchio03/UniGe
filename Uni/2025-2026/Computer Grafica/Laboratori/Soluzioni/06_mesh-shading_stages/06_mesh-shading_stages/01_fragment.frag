#version 410 core

in vec3 interpolated_normal;
out vec4 fragment_color;

void main()
{
    // return the interpolated color for the fragment
    //fragment_color = vec4 (interpolated_color, 1.0);
    fragment_color = vec4 (interpolated_normal * 0.5 + 0.5, 1.0);
}
