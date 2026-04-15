#include "App.h"
#include "Camera.h"
#include "config.h"
#include "Cube.h"
#include "Tetrahedron.h"
#include "Renderer.h"
#include "Scene.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);


int main()
{
    App app{};
    Scene scene(vec4(0.1f, 0.2f, 0.2f, 1.0f));

    scene.addObject<Cube>(vec3(1.0f, 2.0f, 1.0f), vec3(1.0f, -1.0f, 1.0f));
    scene.addObject<Cube>(vec3(1.0f, 1.5f, 1.0f), vec3(-1.0f, -1.0f, 1.0f));
    scene.addObject<Tetrahedron>(vec3(1.0f, 0.865f, 0.865f), vec3(-1.0f, -1.0f, -1.0f));
    scene.addObject<Cube>(vec3(1.0f, 0.5f, 1.0f), vec3(1.0f, -1.0f, -1.0f));

    app.run(scene);

    return 0;
}