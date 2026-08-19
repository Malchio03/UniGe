#version 410 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 col;
uniform float phi_deg, theta_deg;
out vec3 interpolated_color;

void main()
{
    vec4 p;
    float s;
    float c;

    // prepare rotation matrices
    s = sin (phi_deg * 3.1415 / 180.0);
    c = cos (phi_deg * 3.1415 / 180.0);	
    mat4 ry = mat4(
                     c, 0.0,  -s, 0.0, // 1st column
                   0.0, 1.0, 0.0, 0.0, // 2nd column
                     s, 0.0,   c, 0.0, // 3rd column
                   0.0, 0.0, 0.0, 1.0
                   );

    s = sin (theta_deg * 3.1415 / 180.0);
    c = cos (theta_deg * 3.1415 / 180.0);
    mat4 rx = mat4(
                   1.0, 0.0, 0.0, 0.0, // 1st column
                   0.0,   c,   s, 0.0, // 2nd column
                   0.0,  -s,   c, 0.0, // 3rd column
                   0.0, 0.0, 0.0, 1.0
                   );

    // prepare translation matrix
    mat4 tz = mat4(
                   1.0, 0.0, 0.0, 0.0, // 1st column
                   0.0, 1.0, 0.0, 0.0, // 2nd column
                   0.0, 0.0, 1.0, 0.0, // 3rd column
                   0.0, 0.0,-2.0, 1.0
                   );

    // prepare projection matrix
    float fd = 2.0;              // focal distance
    float fcp = 3.0;             // distance far clip plane
    float ncp = 1.0;             // distance near clip plane
    float a = (fcp + ncp) / (ncp - fcp);       // coefficient 3rd col
    float b = 2.0 * fcp * ncp / (ncp - fcp);   // coefficient 4th col

    /*** NOTE *******************************************************
     **  We use fd directly as coefficient in the first two lines. **
     **  It works because our scene is in a unitary cube.          **
     **  If the image plane is centered about the view axis, with  **
     **  width 2r and height 2t in view space, the coefficients    **
     **  containing fd must be scaled accordingly.                 **
     ****************************************************************/
    mat4 pr = mat4(
                    fd, 0.0, 0.0,  0.0,    // 1st column
                   0.0,  fd, 0.0,  0.0,    // 2nd column
                   0.0, 0.0,   a, -1.0,    // 3rd column
                   0.0, 0.0,   b,  0.0     // 4th column
                   );

    // apply vp matrix
    p = vec4 (pos, 1.0);
    gl_Position = pr * tz * rx * ry * p;
    interpolated_color = col;
}
