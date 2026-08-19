#ifndef TRACKBALL_HH
#define TRACKBALL_HH

#include <algorithm>
#include <cmath>
#include <stdexcept>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>



namespace fcg
{

    class Trackball
    {
    public:
        int width = 0;  // window width in pixels
        int height = 0; // window height in pixels

        // Center of rotation is C = (0, 0, -d) in view coordinates.
        // d must be positive.
        float d = 1.0f;

        // tan(theta / 2), where theta is the vertical field of view angle.
        float tan_theta_2 = 1.0f;

        // Frustum aspect ratio: width / height.
        float aspect = 1.0f;

    private:
        glm::quat current_rotation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);
        glm::quat drag_rotation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);
        glm::vec3 last_point {}; // unit vector on virtual trackball, in view-oriented local coordinates
        bool moving = false;

    public:
        Trackball () = default;

        Trackball (int w, int h, float distance, float tangent_half_aperture)
        {
            set_window_size (w, h);
            set_view (distance, tangent_half_aperture);
        }

        void set_window_size(int w, int h)
        {
            width = w;
            height = h;
            aspect = ((float) w) / (float) h;
        }

        void set_view (float distance, float tangent_half_aperture)
        {
            // distance and tangent_half_aperture should be positive
            if (distance <= 0.0f)
                distance = 0.0000001;
            if (tangent_half_aperture <= 0.0f)
                tangent_half_aperture = 0.0000001;
            d = distance;
            tan_theta_2 = tangent_half_aperture;
        }

        glm::vec3 center_of_rotation () const
        {
            return glm::vec3 (0.0f, 0.0f, -d);
        }

        void reset ()
        {
            current_rotation = glm::quat (1.0f, 0.0f, 0.0f, 0.0f);
            drag_rotation = glm::quat (1.0f, 0.0f, 0.0f, 0.0f);
            last_point = glm::vec3 (0.0f);
            moving = false;
        }

        void start (float x, float y)
        {
            last_point = project_on_trackball (x, y);
            drag_rotation = glm::quat (1.0f, 0.0f, 0.0f, 0.0f);
            moving = true;
        }

        void stop ()
        {
            moving = false;
        }

        // The old implementation accepted an extra od argument. It is kept only
        // for source compatibility; the trackball depth is now the member d.
        bool move (float x, float y)
        {
            if (!moving)
                return false;

            const glm::vec3 current_point = project_on_trackball (x, y);
            const glm::vec3 axis = glm::cross (last_point, current_point);
            const float axis_len = glm::length (axis);

            if (axis_len > 1e-6f)
                {
                    const float dot = std::clamp (glm::dot (last_point, current_point), -1.0f, 1.0f);
                    const float angle = std::atan2 (axis_len, dot);

                    // Minus sign preserves the behavior of the original implementation.
                    drag_rotation = glm::angleAxis (angle, axis / axis_len);
                    current_rotation = drag_rotation * current_rotation;
                }

            last_point = current_point;
            return true;
        }

        // Rotation around the origin.
        // To be composed with a translation to the center of rotation for pivoting.
        glm::mat4 rotation_matrix() const
        {
            return glm::toMat4(current_rotation);
        }

        // Rotation around C = (0,0,-d), in view coordinates.
        // For GLM column-vector convention, apply this to points already expressed
        // in the same view coordinate frame as the pivot.
        glm::mat4 pivot_matrix() const
        {
            const glm::vec3 c = center_of_rotation();
            return glm::translate(glm::mat4(1.0f), c) * rotation_matrix() * glm::translate(glm::mat4(1.0f), -c);
        }

        // Synonym with a more descriptive name.
        glm::mat4 transformation_matrix () const
        {
            return pivot_matrix ();
        }

        // Mouse position unprojected onto the plane z = -d in view coordinates.
        glm::vec3 mouse_on_center_plane (float x, float y) const
        {
            const float x_ndc = 2.0f * x / static_cast<float> (width) - 1.0f;
            const float y_ndc = 1.0f - 2.0f * y / static_cast<float> (height);

            const float y_view = y_ndc * d * tan_theta_2;
            const float x_view = x_ndc * d * tan_theta_2 * aspect;

            return glm::vec3 (x_view, y_view, -d);
        }

        glm::vec3 project_on_trackball (float x, float y) const
        {
            const glm::vec3 p = mouse_on_center_plane (x, y);
            const glm::vec3 c = center_of_rotation ();

            // Coordinates in the tangent plane through the center of rotation.
            const glm::vec2 q = glm::vec2 (p.x - c.x, p.y - c.y);

            // Natural radius: the smaller half-size of the frustum section at z=-d.
            // This makes the virtual sphere fit the window's shorter dimension.
            const float radius = trackball_radius ();
            const float rho = glm::length (q);

            // Project on the trackball sphere or hyperbolic sheet, depending on the distance from the center.
            // The two alternatives are smoothly connected at rho = radius * sqrt(1/2), where the sphere's surface normal is at 45 degrees.
            float z_trackball;
            if (rho <= radius * 0.7071067811865475f) // radius * sqrt(1/2)
                {
                    // Sphere near the center.
                    z_trackball = std::sqrt(radius * radius - rho * rho);
                }
            else
                {
                    // Hyperbolic sheet outside, Shoemake-style, for smooth behavior.
                    z_trackball = (radius * radius) / (2.0f * rho);
                }

            return glm::normalize(glm::vec3(q.x, q.y, z_trackball));
        }

        float trackball_radius() const
        {
            const float half_height = d * tan_theta_2;
            const float half_width = half_height * aspect;
            return std::min (half_width, half_height);
        }
    };

}

#endif
