#ifndef HELLO_WINDOW_RENDERER_H
#define HELLO_WINDOW_RENDERER_H
#include "Camera.h"
#include "Scene.h"
#include "Shader.h"


class Renderer {
private:
    Shader shader;
    Shader lightShader;
public:

    Renderer() : shader("../shaders/vertex.glsl", "../shaders/fragment.glsl"), lightShader("../shaders/vertex.glsl", "../shaders/fragmentlight.glsl")
    {

    }

    void render(const Camera& camera, const Scene& scene)
    {
        shader.use();
        shader.setMat4("view", camera.getView());
        shader.setMat4("projection", camera.getProjection());
        shader.setVec3("viewPos", camera.getPosition());

        scene.draw(shader);

        lightShader.use();
        lightShader.setMat4("view", camera.getView());
        lightShader.setMat4("projection", camera.getProjection());
        lightShader.setVec3("viewPos", camera.getPosition());

        scene.drawLightSources(lightShader);
    }
};



#endif //HELLO_WINDOW_RENDERER_H
