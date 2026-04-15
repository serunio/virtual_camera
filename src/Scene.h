//
// Created by kub on 15.04.2026.
//

#ifndef HELLO_WINDOW_SCENE_H
#define HELLO_WINDOW_SCENE_H
#include <memory>

#include "Object.h"

using namespace glm;
using namespace std;

class Scene {
    vec4 backgroundColor;
    vector<unique_ptr<Object>> objects;
public:
    Scene(const vec4 backgroundColor) : backgroundColor(backgroundColor)
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
        glClearColor(backgroundColor.x, backgroundColor.y, backgroundColor.z, backgroundColor.w);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        for (const unique_ptr<Object>& o : objects)
        {
            o->draw(shader);
        }
    }
};



#endif //HELLO_WINDOW_SCENE_H
