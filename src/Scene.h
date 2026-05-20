#ifndef HELLO_WINDOW_SCENE_H
#define HELLO_WINDOW_SCENE_H
#include <memory>

#include "Object.h"
#include "Light.h"
#include "LightManager.h"

using namespace glm;
using namespace std;

class Scene {
    vec3 backgroundColor;
    vec3 lightColor;
    vector<unique_ptr<Object>> objects;
    LightManager lightManager;
public:
    Scene(const vec3 backgroundColor) : backgroundColor(backgroundColor)
    {

    }

    template<typename T, typename... Args>
    void addObject(Args&&... args)
    {
        auto obj = std::make_unique<T>(std::forward<Args>(args)...);
        objects.push_back(std::move(obj));
    }

    void draw(Shader& shader) const
    {
        glClearColor(backgroundColor.x, backgroundColor.y, backgroundColor.z, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        lightManager.lightObjects(shader);

        for (const unique_ptr<Object>& o : objects)
        {
            o->draw(shader);
        }
    }

    void addLight(Light light)
    {
        lightManager.addLight(light);
    }

    void drawLightSources(Shader& lightShader) const 
    {
        lightManager.drawSources(lightShader);
    }

    void processInput(GLFWwindow* window, float dt)
    {
        lightManager.processInput(window, dt);
    }
};



#endif //HELLO_WINDOW_SCENE_H
