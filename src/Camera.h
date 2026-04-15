#ifndef HELLO_WINDOW_CAMERA_H
#define HELLO_WINDOW_CAMERA_H

#include "config.h"
#include "Cube.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;
using namespace std;

class Camera {
private:
    float fov = 55.0f;
    float yaw = 0.0f;
    float pitch = 0.0f;
    vec3 cameraPos = vec3(0.5f, 0.0f, 5.0f);
    vec3 cameraFront = vec3(0.0f, 0.0f, -1.0f);
    vec3 up = vec3(0.0f, 1.0f, 0.0f);
public:
    void processInput(GLFWwindow* window, const float dt)
    {
        const float cameraSpeed = dt * 2.5f;
        const float rotateAngle = dt * 50.0f;
        if(glfwGetKey(window, GLFW_KEY_X))
            fov += 1.5f;
        if(glfwGetKey(window, GLFW_KEY_Z))
            fov -= 1.5f;
        fov = clamp(fov, 1.0f, 179.0f);
        if(glfwGetKey(window, GLFW_KEY_W))
            cameraPos += cameraSpeed * normalize(vec3(cameraFront.x, 0, cameraFront.z));
        if(glfwGetKey(window, GLFW_KEY_S))
            cameraPos -= cameraSpeed * normalize(vec3(cameraFront.x, 0, cameraFront.z));
        if(glfwGetKey(window, GLFW_KEY_A))
            cameraPos -= normalize(cross(cameraFront, up)) * cameraSpeed;
        if(glfwGetKey(window, GLFW_KEY_D))
            cameraPos += normalize(cross(cameraFront, up)) * cameraSpeed;
        if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT))
            cameraPos -= up * cameraSpeed;
        if(glfwGetKey(window, GLFW_KEY_SPACE))
            cameraPos += up * cameraSpeed;

        if (glfwGetKey(window, GLFW_KEY_RIGHT))
            yaw -= rotateAngle;
        if (glfwGetKey(window, GLFW_KEY_LEFT))
            yaw += rotateAngle;
        if (glfwGetKey(window, GLFW_KEY_UP))
            pitch += rotateAngle;
        if (glfwGetKey(window, GLFW_KEY_DOWN))
            pitch -= rotateAngle;

        pitch = clamp(pitch, -89.0f, 89.0f);
        mat3 yawRot = mat3(rotate(mat4(1.0f), radians(yaw), up));
        cameraFront = normalize(yawRot * vec3(0.0f, 0.0f, -1.0f));

        mat3 pitchRot = mat3(rotate(mat4(1.0f), radians(pitch), normalize(cross(cameraFront, up))));
        cameraFront = normalize(pitchRot * cameraFront);
    }

    Camera()
    = default;

    mat4 getView() const
    {
        return lookAt(cameraPos, cameraPos + cameraFront, up);
    }

    mat4 getProjection() const
    {
        return perspective(radians(fov), 16.0f / 9.0f, 0.0f, 100.0f);
    }
};



#endif //HELLO_WINDOW_CAMERA_H
