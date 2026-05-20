#version 460 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform bool Sphere = false;

out vec3 Pos;

out vec2 LocalPos;
out vec3 SphereCenter;

out vec3 CameraRight;
out vec3 CameraUp;
out vec3 CameraForward;

out vec3 FragPos;
out vec3 Normal;

void main()
{
    if (Sphere)
    {
        vec3 worldPos = vec3(model[3]);

        vec3 cameraRight = vec3(view[0][0], view[1][0], view[2][0]);
        vec3 cameraUp    = vec3(view[0][1], view[1][1], view[2][1]);

        vec3 cameraForward = vec3(view[0][2], view[1][2], view[2][2]);

        vec3 billboardPos =
            worldPos +
            cameraRight * aPos.x +
            cameraUp * aPos.y;

        gl_Position =
            projection *
            view *
            vec4(billboardPos, 1.0);

        LocalPos = aPos.xy;

        SphereCenter = worldPos;

        CameraRight = cameraRight;
        CameraUp = cameraUp;
        CameraForward = cameraForward;

        FragPos = billboardPos;
        Normal = vec3(0.0);
    }
    else
    {
        vec4 world =
            model *
            vec4(aPos, 1.0);

        gl_Position =
            projection *
            view *
            world;

        FragPos = world.xyz;

        Normal =
            mat3(transpose(inverse(model))) *
            normalize(aPos);

        LocalPos = vec2(0.0);

        SphereCenter = vec3(0.0);

        CameraRight = vec3(0.0);
        CameraUp = vec3(0.0);
        CameraForward = vec3(0.0);
    }

    Pos = aPos;
}