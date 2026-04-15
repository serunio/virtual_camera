#version 460 core
out vec4 FragColor;
in vec2 TexCoord;
in vec4 Color;
uniform sampler2D Texture1;
uniform sampler2D Texture2;
uniform float offsetX;
uniform float offsetY;



void main() 
{
    FragColor = Color;
}