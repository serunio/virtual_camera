#include "App.h"
#include "Camera.h"
#include "config.h"
#include "Cube.h"
#include "Tetrahedron.h"
#include "Sphere.h"
#include "Renderer.h"
#include "Scene.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);


int main()
{
    App app{};
    Scene scene(vec3(0.2f, 0.2f, 0.2f));

    scene.addLight(Light(vec3(0,1,0), vec3(1,1,0.9f), 0.2f, 0.5f, 1.0f));
    scene.addLight(Light(vec3(-1,1,-0.7), vec3(1,0,0), 0.2f, 0.5f, 1.0f));
    scene.addLight(Light(vec3(1,1,-0.7), vec3(0,1,0), 0.2f, 0.5f, 1.0f));
    scene.addLight(Light(vec3(0,1,1), vec3(0,0,1), 0.2f, 0.5f, 1.0f));

    Material plastic_y;
    plastic_y.ambient = vec3(0.329412,	0.223529,	0.027451) / 0.2f ;
    plastic_y.diffuse = vec3(0.780392,	0.568627,	0.113725) / 0.5f;
    plastic_y.specular = vec3(0.992157,	0.941176,	0.807843);
    plastic_y.shininess = 1 << 7;

    Material glass_g;
    glass_g.ambient = vec3(0.0215f, 0.1745f, 0.0215f);
    glass_g.diffuse = vec3(0.07568f, 0.61424f, 0.07568f);
    glass_g.specular = vec3(0.633f, 0.727811f, 0.633f);
    glass_g.shininess = 1 << 4;

    Material rock;
    rock.ambient = vec3(0.05375f, 0.05f, 0.06625f) / 0.2f;
    rock.diffuse = vec3(0.18275f, 0.17f, 0.22525f) / 0.5f;
    rock.specular = vec3(0.332741f, 0.328634f, 0.346435f);
    rock.shininess = 1 << 2;

    Material silver;
    silver.ambient = vec3(0.19225f,	0.19225f,	0.19225f) ;
    silver.diffuse = vec3(0.50754f,	0.50754f,	0.50754f) / 0.5f;
    silver.specular = vec3(0.508273f,	0.508273f,	0.508273f);
    silver.shininess = 1 << 2;

    Material gold;
    gold.ambient = vec3(0.24725f,	0.1995f,	0.0745f) ;
    gold.diffuse = vec3(0.75164f,	0.60648f,	0.22648f) / 0.5f;
    gold.specular = vec3(0.628281f,	0.555802f,	0.366065f);
    gold.shininess = 1 << 1;

    Material rubber;
    rubber.ambient = vec3(0.5,	0.0,	0.0);
    rubber.diffuse = vec3(0.5,	0.4,	0.4) / 0.5f;
    rubber.specular = vec3(0.7,	0.04,	0.04) / 2.0f;
    rubber.shininess = 1;

    Material ceramic;
    ceramic.ambient = vec3(0.5,	0.48,	0.35) / 0.3f;
    ceramic.diffuse = vec3(0.5,	0.48,	0.45) / 0.4f;
    ceramic.specular = vec3(0.9,	0.9,	0.9) / 2.0f;
    ceramic.shininess = 1 << 6;

    

    scene.addObject<Sphere>(vec3(0.5f, 0.5f, 0.5f), vec3(-3.0f, -1.0f, 0.0f), plastic_y);
    scene.addObject<Sphere>(vec3(0.5f, 0.5f, 0.5f), vec3(-2.0f, -1.0f, 0.0f), glass_g);
    scene.addObject<Sphere>(vec3(0.5f, 0.5f, 0.5f), vec3(-1.0f, -1.0f, 0.0f), rock);
    scene.addObject<Sphere>(vec3(0.5f, 0.5f, 0.5f), vec3(0.0f, -1.0f, 0.0f), silver);
    scene.addObject<Sphere>(vec3(0.5f, 0.5f, 0.5f), vec3(1.0f, -1.0f, 0.0f), gold);
    scene.addObject<Sphere>(vec3(0.5f, 0.5f, 0.5f), vec3(2.0f, -1.0f, 0.0f), rubber);
    scene.addObject<Sphere>(vec3(0.5f, 0.5f, 0.5f), vec3(3.0f, -1.0f, 0.0f), ceramic);


    app.run(scene);

    return 0;
}