#version 410 core

//const vec3 GREEN = vec3(0.1, 0.8, 0.0);
uniform vec3 input_color;
out vec4 frag_color;

void main()
{
    //frag_color = vec4 (GREEN, 1.0);
    frag_color = vec4 (input_color, 1.0);
}
