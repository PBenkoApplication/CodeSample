#version 330

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec3 color;
layout(location = 3) in vec2 texCoord;
layout(location = 4) in vec3 tangent;
layout(location = 5) in vec3 binormal;

uniform mat4 transform;
uniform mat4 invTransWorldMat;
uniform mat4 worldMatrix;

out vec4 col;
out vec4 posWS;
out vec3 normalWS;
out vec3 tangentWS;
out vec3 binormalWS;
out vec2 texcoord;
void main()
{

	col = vec4(color, 1.0); 	  
	
	posWS = worldMatrix * vec4(position,1.0);
	normalWS = normalize(mat3(invTransWorldMat) * normal);
	tangentWS = normalize(mat3(invTransWorldMat) * tangent);
	binormalWS = normalize(mat3(invTransWorldMat) * binormal);
	texcoord = texCoord;
  gl_Position = transform * vec4(position, 1.0);
 
}