#version 330

layout(location = 0) in vec3 position;
layout(location = 2) in vec3 color;

uniform mat4 transform;
out vec4 col;

void main()
{

	col = vec4(color, 1.0); 
  gl_Position = transform * vec4(position, 1.0);

}