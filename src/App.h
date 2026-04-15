#ifndef HELLO_WINDOW_APP_H
#define HELLO_WINDOW_APP_H
#include "Camera.h"
#include "Renderer.h"
#include "config.h"
#include "Scene.h"


class App {
private:
    Camera camera;
    Renderer* renderer;
    GLFWwindow* window;

    static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

    void processInput() const
    {
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }
public:
    App()
    {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(800, 600, "Virtual Camera", NULL, NULL);
        if (window == NULL)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
        }
        glfwMakeContextCurrent(window);
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
        }

        camera = Camera();
        renderer = new Renderer();
    }

    void run(const Scene& scene)
    {
        float dt = 0.0f;
        float lastFrame = 0.0f;
        float t = 0.0f;;
        while (!glfwWindowShouldClose(window))
        {
            t = glfwGetTime();
            dt = t - lastFrame;
            lastFrame = t;

            processInput();
            camera.processInput(window, dt);



            renderer->render(camera, scene);

            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        glfwTerminate();
    }
};



#endif //HELLO_WINDOW_APP_H
