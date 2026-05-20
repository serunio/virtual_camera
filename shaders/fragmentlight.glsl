#version 460 core

in vec2 LocalPos;
out vec4 FragColor;

uniform vec3 Color;
uniform bool isActive = false;

void main()
{
    float r2 = dot(LocalPos, LocalPos);
    float radius = 0.1;
    if (isActive && r2 < radius * radius * 2 && r2 > radius * radius)
        FragColor = vec4(0.5);
    else if (r2 > radius * radius)
        discard;
    else
        FragColor = vec4(Color, 1.0);
}