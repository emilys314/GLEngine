#version 330 core

struct Light {
	vec3 lightColor;
	vec3 lightDirection;
};

in vec2 TexCoord;
in vec3 FragPos;
in vec3 Normal;

out vec4 color;

uniform sampler2D ourTexture;
uniform vec3 ambientColor;
uniform Light light;
uniform vec3 viewPos;

float specularStrength = 0.5f;

void main()
{
	vec3 ambient = ambientColor * vec3(texture(ourTexture, TexCoord));

	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(-light.lightDirection);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff* light.lightColor;

	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 16);
	vec3 specular = specularStrength * spec * light.lightColor;  

    color = vec4(ambient + diffuse + specular, 1.0f);
}