#version 450 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoord;

out vec2 TexCoord;
out vec3 Normal;
out vec3 fragPos;

uniform mat4 transform;


void main()
{
    gl_Position =transform*vec4(aPos, 1.0);
    TexCoord = aTexCoord;
    Normal=aNormal;
    fragPos=aPos;
}