#version 330

layout(location = 0) in vec3 position;
layout(location = 3) in vec2 texCoord;

uniform mat4 transform;

out vec2 texcoord;

void main()
{

	texcoord = texCoord;
  gl_Position = transform * vec4(position, 1.0);

}