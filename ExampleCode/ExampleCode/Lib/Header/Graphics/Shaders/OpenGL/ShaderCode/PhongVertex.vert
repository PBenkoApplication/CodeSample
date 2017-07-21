#version 330

in vec3 position;
in vec3 normal;
in vec3 color;

uniform mat4 transform;

out vec3 normal0;
out vec4 color0;

void main()
{
  normal0 = normal;
  color0 = vec4(color, 1);  
  gl_Position = transform * vec4(position, 1.0);
}




























//in vec3 position;
//in vec3 color;
//in vec3 normal;

//uniform mat4 transform;
//uniform vec3 lightColor;
//uniform vec3 lightDirection;
//uniform float lightIntensity;
//uniform mat4 worldMatrix;
//out vec4 color0;

//void main()
//{


//  vec4 col = vec4(color, 1);

//  vec3 norm = normalize(worldMatrix* vec4(normal, 0)).xyz;

//  float diffuseFactor = dot(norm, -lightDirection);

//  vec4 diffuseColor = vec4(0, 0, 0, 0);


//  if (diffuseFactor > 0)
//  {
//	  diffuseColor = vec4(lightColor, 1.0) * lightIntensity * diffuseFactor;
//  }



//  color0 = col * diffuseColor;
//  gl_Position = transform * vec4(position, 1.0);


//}