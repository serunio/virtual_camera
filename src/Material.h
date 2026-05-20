#ifndef HELLO_WINDOW_MATERIAL
#define HELLO_WINDOW_MATERIAL

#include "config.h"

using namespace glm;

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

#endif