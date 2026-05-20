#ifndef HELLO_WINDOW_LIGHT
#define HELLO_WINDOW_LIGHT

#include "config.h"
#include "Shader.h"
#include "Camera.h"
#include "Mesh.h"

using namespace glm;
using namespace std;

class Light {
    vec3 position;
    vec3 color;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    Mesh mesh;
    mat4 model{};
    bool isOn = true;
    bool isActive = false;
public:
    
    Light(vec3 position, vec3 color, float ambient, float diffuse, float specular)
        : position(position),
          color(color),
          ambient(vec3(ambient)),
          diffuse(vec3(diffuse)),
          specular(vec3(specular)),
          mesh(
              std::vector<float>{
                  -1, -1, 0,
                   1, -1, 0,
                   1,  1, 0,
                  -1,  1, 0,
              },
              std::vector<unsigned int>{
                  0, 1, 2,
                  0, 3, 2,
              },
              6,
              GL_TRIANGLES
          )
    {
        model = translate(mat4(1.0f), position);
    }

    void draw(Shader& shader) const
    {
        if (isActive)
            shader.setBool("isActive", true);
        else
            shader.setBool("isActive", false);
        shader.setBool("Sphere", true);
        shader.setMat4("model", model);
        shader.setVec3("Color", isOn ? color : vec3(0,0,0));
        
        mesh.draw();
        shader.setBool("Sphere", false);
    }

    vec3 getColor() const
    {
        return color;
    }
    vec3 getPos() const
    {
        return position;
    }
    vec3 getAmbient() const
    {
        return ambient * color;
    }
    vec3 getDiffuse() const
    {
        return diffuse * color;
    }
    vec3 getSpecular() const
    {
        return specular * color;
    }

    void changeColor(vec3 colorChange)
    {
        color += colorChange;
        color = glm::clamp(color, 0.0f, 1.0f);
    }
    void changePos(vec3 posChange)
    {
        position += posChange;
        model = translate(mat4(1.0f), position);
    }
    void setActive(bool value) 
    {
        isActive = value;
    }
    bool getStatus() const
    {
        return isOn;
    }
    void switchOn()
    {
        isOn = true;
    }
    void switchOff()
    {
        isOn = false;
    }
};

#endif