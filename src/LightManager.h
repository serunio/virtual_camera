#ifndef HELLO_WINDOW_LIGHT_MANAGER
#define HELLO_WINDOW_LIGHT_MANAGER

#include "config.h"
#include "Shader.h"
#include "Camera.h"
#include "Mesh.h"
#include "Light.h"

using namespace glm;
using namespace std;

class LightManager {
    vector<Light> lights;
    int activeLight = 0;
public:
    
    LightManager() 
    {

    }

    void addLight(Light light)
    {
        lights.push_back(light);
    }

    void lightObjects(Shader& shader) const
    {
        int i = 0;
        for(Light l : lights)
        {
            if(l.getStatus())
            {
                string base = "lights[" +  to_string(i++) + "]";
                shader.setVec3(base + ".color", l.getColor());
                shader.setVec3(base + ".position", l.getPos());
                shader.setVec3(base + ".ambient", l.getAmbient());
                shader.setVec3(base + ".diffuse", l.getDiffuse());
                shader.setVec3(base + ".specular", l.getSpecular());
            }   
        }
        
        shader.setInt("LightCount", i);
    }

    void drawSources(Shader& shader) const
    {
        for (const Light l : lights)
        {
            l.draw(shader);
        }
    }

    void processInput(GLFWwindow* window, float dt)
    {
        float lightSpeed = 2.0f * dt;

        for (Light& l : lights)
        {
            l.setActive(false);
        }

        lights[activeLight].setActive(true);

        for (int i = 0; i <= 9; i++)
        {
            if (glfwGetKey(window, GLFW_KEY_0 + i) && i < lights.size())
            {
                activeLight = i;
            }   
        }

        if (glfwGetKey(window, GLFW_KEY_I))
            lights[activeLight].changePos(vec3(0, 0, -lightSpeed));

        if (glfwGetKey(window, GLFW_KEY_K))
            lights[activeLight].changePos(vec3(0, 0, lightSpeed));

        if (glfwGetKey(window, GLFW_KEY_J))
            lights[activeLight].changePos(vec3(-lightSpeed, 0, 0));

        if (glfwGetKey(window, GLFW_KEY_L))
            lights[activeLight].changePos(vec3(lightSpeed, 0, 0));

        if (glfwGetKey(window, GLFW_KEY_U))
            lights[activeLight].changePos(vec3(0,lightSpeed, 0));

        if (glfwGetKey(window, GLFW_KEY_H))
            lights[activeLight].changePos(vec3(0,-lightSpeed, 0));
        
        if (glfwGetKey(window, GLFW_KEY_R) && glfwGetKey(window, GLFW_KEY_O))
            lights[activeLight].changeColor(vec3(-lightSpeed, 0, 0));

        if (glfwGetKey(window, GLFW_KEY_R) && glfwGetKey(window, GLFW_KEY_P))
            lights[activeLight].changeColor(vec3(lightSpeed, 0, 0));
        
        if (glfwGetKey(window, GLFW_KEY_G) && glfwGetKey(window, GLFW_KEY_O))
            lights[activeLight].changeColor(vec3(0, -lightSpeed, 0));

        if (glfwGetKey(window, GLFW_KEY_G) && glfwGetKey(window, GLFW_KEY_P))
            lights[activeLight].changeColor(vec3(0, lightSpeed, 0));

        if (glfwGetKey(window, GLFW_KEY_B) && glfwGetKey(window, GLFW_KEY_O))
            lights[activeLight].changeColor(vec3(0, 0, -lightSpeed));

        if (glfwGetKey(window, GLFW_KEY_B) && glfwGetKey(window, GLFW_KEY_P))
            lights[activeLight].changeColor(vec3(0, 0, lightSpeed));
        
        if (glfwGetKey(window, GLFW_KEY_M))
            lights[activeLight].switchOn();

        if (glfwGetKey(window, GLFW_KEY_N))
        lights[activeLight].switchOff();
    }
};

#endif