#include<stdio.h>
#include<stdlib.h>

#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

#include <glm/ext/vector_uint3.hpp>
#include <glm/vec3.hpp> 
#include <glm/geometric.hpp> 


class Mesh {
private:
    std::vector<glm::vec3> vertices;
    std::vector<glm::uvec3> triangles;

public:
    Mesh(const std::string& filename) {
        std::ifstream file (filename);
 
        if (!file.is_open ()) {
            fprintf (stderr, "Error: Failed to open file: %s\n", filename.c_str ());
            exit (1);
        }

        std::string line;

        // Read OFF header
        std::getline (file, line);
        if (line != "OFF") {
            fprintf (stderr, "Error: Invalid OFF file: missing OFF header\n");
            exit (1);
        }

        // Skip comments and empty lines
        while (std::getline (file, line)) {
            if (line.empty () || line[0] == '#') {
                continue;
            }
            break;
        }

        // Parse header: vnum fnum ednum
        std::istringstream headerStream (line);
        unsigned int vnum, fnum, ednum;
        if (!(headerStream >> vnum >> fnum >> ednum)) {
            fprintf (stderr, "Error: Invalid OFF header format\n");
            exit (1);
        }

        vertices.reserve (vnum);
        triangles.reserve (fnum);

        // Read vertices
        for (unsigned int i = 0; i < vnum; ++i) {
            float x, y, z;
            if (!(file >> x >> y >> z)) {
                fprintf (stderr, "Error: Failed to read vertex data at index %u\n", i);
                exit (1);
            }
            vertices.emplace_back (x, y, z);
        }

        // Read faces
        for (unsigned int i = 0; i < fnum; ++i) {
            unsigned int vcount;

            if (!(file >> vcount)) {
                fprintf (stderr, "Error: Failed to read face count at face %u\n", i);
                exit (1);
            }

            if (vcount == 3) {
                glm::uvec3 triangle;

                if (!(file >> triangle[0] >> triangle[1] >> triangle[2])) {
                    fprintf (stderr, "Error: Failed to read triangle indices at face %u\n", i);
                    exit (1);
                }
                triangles.push_back (triangle);
            }
            else {
                fprintf (stderr, "Error: Face %u is not a triangle\n", i);
                exit (1);
            }
        }

        file.close();

        rescale ();
    }

    void pack4gpu (std::vector<float>& points, std::vector<unsigned int>& indices)
    {
        points = {};
        // fill up flat points
        for (auto v : vertices) {
            // coords
            points.push_back (v.x);
            points.push_back (v.y);
            points.push_back (v.z);
            // color
            points.push_back (0.8);
            points.push_back (0.6);
            points.push_back (0.2);
        }

        indices = {};
        // fill up flat triangles
        for (auto t : triangles)
            for (unsigned i = 0; i < 3; i++)
                indices.push_back (t[i]);

    }


private:

    void rescale ()
    {
        if (vertices.empty ())
            return;

        // Find bounding box
        glm::vec3 min_bounds = vertices[0];
        glm::vec3 max_bounds = vertices[0];

        for (const auto& vertex : vertices) {
            // glm/glsl min and max work component-wise
            min_bounds = glm::min (min_bounds, vertex);
            max_bounds = glm::max (max_bounds, vertex);
        }

        // Calculate centers and extents along x, y, and z
        glm::vec3 centers = (min_bounds + max_bounds) * 0.5f;
        // glm::vec3 extents = (max_bounds - min_bounds) * 0.5f;

        // Find the maximum extent to preserve proportions
        //float max_extent = std::max ({extents.x, extents.y, extents.z});
        float max_extent = glm::distance (max_bounds, min_bounds) * 0.5;

        // Normalize vertices: translate to center, then scale uniformly
        for (auto& vertex : vertices) {
            vertex = (vertex - centers) / max_extent;
        }
    }
};
