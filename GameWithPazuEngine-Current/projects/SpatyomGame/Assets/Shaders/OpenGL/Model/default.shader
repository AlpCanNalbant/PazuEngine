@Vertex
in vec3 vertPos;
in vec3 vertNorm;
in vec2 vertUv;
in vec4 vertColor;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 model;
out vec4 color;

void main()
{
	gl_Position = proj * view * model * vec4(vertPos, 1.f);
	color = vertColor;
}

@Pixel
out vec4 fragColor;
in vec4 color;

void main()
{
	fragColor = color;
}
