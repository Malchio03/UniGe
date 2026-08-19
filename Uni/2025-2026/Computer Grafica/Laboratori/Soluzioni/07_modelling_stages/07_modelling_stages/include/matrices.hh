#ifndef MATRICES_HH
#define MATRICES_HH

#include <glm/mat4x4.hpp>
#include <glm/trigonometric.hpp>
#include <glm/vec3.hpp>



namespace fcg
{

    // IDENTITIES
    glm::mat4 identity ()
    {
        return glm::mat4(
                         1, 0, 0, 0,
                         0, 1, 0, 0,
                         0, 0, 1, 0,
                         0, 0, 0, 1
                         );
    }

    glm::mat3 identity3 ()
    {
        return glm::mat3(
                         1, 0, 0,
                         0, 1, 0,
                         0, 0, 1
                         );
    }


    // ROTATE

    glm::mat4 rotation_x (float a)
    {
        float s = glm::sin (glm::radians (a));
        float c = glm::cos (glm::radians (a));
        return glm::mat4(
                         1, 0, 0, 0,
                         0, c, s, 0,
                         0,-s, c, 0,
                         0, 0, 0, 1
                         );
    }

    glm::mat4 rotation_y (float a)
    {
        float s = glm::sin (glm::radians (a));
        float c = glm::cos (glm::radians (a));
        return glm::mat4(
                         c, 0,-s, 0,
                         0, 1, 0, 0,
                         s, 0, c, 0,
                         0, 0, 0, 1
                         );
    }

    glm::mat4 rotation_z (float a)
    {
        float s = glm::sin (glm::radians (a));
        float c = glm::cos (glm::radians (a));
        return glm::mat4(
                         c, s, 0, 0,
                         -s, c, 0, 0,
                         s, 0, 1, 0,
                         0, 0, 0, 1
                         );
    }


    // TRANSLATE

    glm::mat4 translation (float dx, float dy, float dz)
    {
        return glm::mat4(
                         1,   0,  0,  0,
                         0,   1,  0,  0,
                         0,   0,  1,  0,
                         dx, dy, dz,  1
                         );
    }
    glm::mat4 translation (glm::vec3 d)
    {
        return translation (d.x, d.y, d.z);
    }


    // SCALE

    glm::mat4 scaling (float sx, float sy, float sz)
    {
        return glm::mat4(
                         sx, 0,  0,  0,
                         0, sy,  0,  0,
                         0,  0, sz,  0,
                         0,  0,  0,  1
                         );
    }
    glm::mat4 scaling (glm::vec3 s)
    {
        return scaling (s.x, s.y, s.z);
    }
    glm::mat4 scaling (float s)
    {
        return scaling (s, s, s);
    }

}

#endif
