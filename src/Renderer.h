#ifndef HELLO_WINDOW_RENDERER_H
#define HELLO_WINDOW_RENDERER_H
#include "Camera.h"
#include "Scene.h"
#include "Shader.h"


class Renderer {
private:
    Shader shader;
public:

    Renderer() : shader("shaders/vertex.glsl", "shaders/fragment.glsl")
    {

    }

    void render(const Camera& camera, const Scene& scene)
    {
        shader.use();

        shader.setMat4("view", camera.getView());
        shader.setMat4("projection", camera.getProjection());

        scene.draw(shader);
    }
};



#endif //HELLO_WINDOW_RENDERER_H
