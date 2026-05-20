#ifndef HELLO_WINDOW_CUBE_H
#define HELLO_WINDOW_CUBE_H

#include "config.h"

#include "Mesh.h"
#include "Object.h"

using namespace glm;
using namespace std;

class Cube : public Object{
    const Mesh mesh;
    mat4 model{};

public:

    Cube(const vec3 dimensions, const vec3 position, const vec3 color) : mesh(createVertices(dimensions), createTriangleIndices(), 36, GL_TRIANGLES)
    {
        model = translate(mat4(1.0f), position);
        // this->color = color;
    }

    Cube(const vec3 dimensions, const vec3 position) : mesh(createVertices(dimensions), createTriangleIndices(), 36, GL_TRIANGLES)
    {
        model = translate(mat4(1.0f), position);
        // color = vec3(0,0,0);
    }

    ~Cube() override = default;

    const Mesh& getMesh() const override
    {
        return mesh;
    }
    mat4 getModel() const override
    {
        return model;
    }

private:

    static vector<float> createVertices(const vec3 dimensions)
    {
        const float x = dimensions.x;
        const float y = dimensions.y;
        const float z = dimensions.z;

        return {
            //position //color
            0, 0, 0,
            x, 0, 0,
            x, 0, z,
            0, 0, z,

            0, y, 0,
            x, y, 0,
            x, y, z,
            0, y, z,
        };
    }

    static vector<unsigned int> createLineIndices()
    {
       return  {
            0, 1, 1, 2, 2, 3, 3, 0,
            4, 5, 5, 6, 6, 7, 7, 4,
            0, 4, 1, 5, 2, 6, 3, 7 //24
        };
    }
    static vector<unsigned int> createTriangleIndices()
    {
       return  {
            0, 1, 2, 0, 3, 2,
            0, 4, 1, 4, 5, 1,
            1, 5, 2, 5, 6, 2,
            2, 6, 3, 6, 7, 3,
            3, 7, 0, 7, 4, 0,
            4, 5, 6, 4, 7, 6 //36
        };
    }
};


#endif //HELLO_WINDOW_CUBE_H
