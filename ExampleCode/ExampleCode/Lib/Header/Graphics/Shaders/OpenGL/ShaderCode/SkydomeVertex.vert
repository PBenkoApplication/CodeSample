#version 330

layout(location = 0) in vec3 position;
layout(location = 2) in vec3 color;
layout(location = 3) in vec2 texCoord;
uniform mat4 transform;
uniform mat4 worldMatrix;
out vec4 col;
out vec4 posWS;
out vec2 texcoord;
void main()
{
    col = vec4(color, 1.0);
    posWS = worldMatrix * vec4(position,1.0);
    texcoord = texCoord;
    gl_Position = transform * vec4(position, 1.0);
}

