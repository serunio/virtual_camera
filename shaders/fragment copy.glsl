#version 460 core

out vec4 FragColor;

// uniform vec3 Color;
uniform vec3 viewPos;

uniform bool Sphere = false;

const int MAX_LIGHTS = 10;
uniform int LightCount;

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
}; 
  
uniform Material material;

struct Light {
    vec3 position;
    vec3 color;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Light lights[MAX_LIGHTS];  

in vec3 Pos;

in vec2 LocalPos;
flat in vec3 SphereCenter;

flat in vec3 CameraRight;
flat in vec3 CameraUp;
flat in vec3 CameraForward;

in vec3 FragPos;
in vec3 Normal;

void main()
{
    vec3 result = vec3(0);
    vec3 norm;
    vec3 fragPos;
    

    if (Sphere)
    {
        float radius = 0.4;

        float r2 = dot(LocalPos, LocalPos);

        if (r2 > radius * radius)
            discard;

        float z =
            sqrt(radius * radius - r2);


        vec3 surfacePos = 
            CameraRight * LocalPos.x +
            CameraUp * LocalPos.y +
            CameraForward * z;

        norm = normalize(surfacePos);

        fragPos = SphereCenter + surfacePos;

        
    }
    else
    {
        norm = normalize(Normal);
        fragPos = FragPos;
    }
    vec3 R = normalize(SphereCenter - fragPos);
    if(LightCount > 0)
    {
        for (int i = 0; i < LightCount; i++)
        {

            // ambient
            vec3 ambient = lights[i].ambient * material.ambient;
            
            // diffuse 
            vec3 lightDir = normalize(lights[i].position - fragPos);
            float diff = max(dot(norm, lightDir), 0.0);
            vec3 diffuse = lights[i].diffuse * (diff * material.diffuse);
            
            // specular
            vec3 viewDir = normalize(viewPos - fragPos);
            vec3 reflectDir = reflect(-lightDir, norm);  
            float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
            vec3 specular = lights[i].specular * (spec * material.specular);  

            if(diff == 0)
            {
                diffuse = vec3(0);
                specular = vec3(0);
            }
                
            result += ambient + diffuse + specular;
        }
    }
    
    FragColor = vec4(result, 1.0);
}