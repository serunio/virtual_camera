#ifndef HELLO_WINDOW_OBJECT_H
#define HELLO_WINDOW_OBJECT_H

#include "config.h"

#include "Mesh.h"

using namespace glm;
using namespace std;

class Object {

public:
    virtual const Mesh& getMesh() const = 0;
    virtual mat4 getModel() const = 0;

    virtual ~Object() = default;
    void draw(Shader& shader) const
    {
        shader.setMat4("model", getModel());
        getMesh().draw();
    }
};



#endif //HELLO_WINDOW_OBJECT_H
