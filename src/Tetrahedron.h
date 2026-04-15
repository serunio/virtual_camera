#ifndef HELLO_WINDOW_TETRAHEDRON_H
#define HELLO_WINDOW_TETRAHEDRON_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Mesh.h"
#include "Object.h"

using namespace glm;
using namespace std;

class Tetrahedron : public Object {
    const Mesh mesh;
    mat4 model{};

public:
    Tetrahedron(const vec3 dimensions, const vec3 position) : mesh(createVertices(dimensions), createIndices(), 12, GL_LINES)
    {
        model = translate(mat4(1.0f), position);
    }

    ~Tetrahedron() override = default;

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
            0, 0, 0,
            x, 0, 0,
            x/2, 0, z,

            x/2, y, z/3
        };
    }

    static vector<unsigned int> createIndices()
    {
        return  {
            0, 1, 1, 2, 2, 0,
            0, 3, 1, 3, 2, 3
        };
    }
};



#endif //HELLO_WINDOW_TETRAHEDRON_H
