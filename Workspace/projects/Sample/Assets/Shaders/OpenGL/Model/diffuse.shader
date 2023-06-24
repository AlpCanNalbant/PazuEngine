@Vertex
in vec3 vertPos;
in vec3 vertNorm;
in vec2 vertUv;
in vec4 vertColor;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 model;
//out vec3 norm;
out vec2 uv;
//out vec4 color;

void main()
{
	gl_Position = proj * view * model * vec4(vertPos, 1.f);
	// norm = vertNorm;
	uv = vertUv;
	// color = vertColor;
}

@Pixel
out vec4 fragColor;
// in vec3 norm;
in vec2 uv;
// in vec4 color;
uniform sampler2D texture0;

void main()
{
	fragColor = texture(texture0, uv);
	// fragColor = color;
}
