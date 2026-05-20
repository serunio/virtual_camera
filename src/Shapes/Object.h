#ifndef HELLO_WINDOW_OBJECT_H
#define HELLO_WINDOW_OBJECT_H

#include "config.h"

#include "Mesh.h"
#include "Material.h"

using namespace glm;
using namespace std;

class Object {

public:
    virtual const Mesh& getMesh() const = 0;
    virtual mat4 getModel() const = 0;

    virtual ~Object() = default;
    void draw(Shader& shader) const
    {
        if (isSphere)
        {
            shader.setBool("Sphere", true);
        }

        shader.setMat4("model", getModel());
        // shader.setVec3("Color", color);
        shader.setVec3("material.ambient", material.ambient);
        shader.setVec3("material.diffuse", material.diffuse);
        shader.setVec3("material.specular", material.specular);
        shader.setFloat("material.shininess", material.shininess);
        
        getMesh().draw();
        shader.setBool("Sphere", false);
    }
protected:
    // vec3 color;
    bool isSphere = false;
    Material material;
};



#endif //HELLO_WINDOW_OBJECT_H
