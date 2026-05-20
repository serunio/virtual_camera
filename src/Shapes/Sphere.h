#ifndef HELLO_WINDOW_SPHERE_H
#define HELLO_WINDOW_SPHERE_H

#include "config.h"

#include "Mesh.h"
#include "Object.h"
#include "Material.h"

using namespace glm;
using namespace std;

class Sphere : public Object{
    const Mesh mesh;
    mat4 model{};

public:

    Sphere(const vec3 dimensions, const vec3 position, const Material material) : mesh(createVertices(dimensions), createTriangleIndices(), 6, GL_TRIANGLES)
    {
        model = translate(mat4(1.0f), position);
        this->material = material;
        isSphere = true;
    }

    ~Sphere() override = default;

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
            //position
            -x, -y, 0,
            x, -y, 0,
            x, y, 0,
            -x, y, 0,
        };
    }

    static vector<unsigned int> createTriangleIndices()
    {
       return  {
            0, 1, 2, 0, 3, 2,
        };
    }
};


#endif //HELLO_WINDOW_SPHERE_H
