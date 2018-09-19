#version 330 core
layout (location = 0) in vec2 position;

out vec2 TexCoord;

uniform mat4 modelMatrix;


void main()
{
    gl_Position = modelMatrix * vec4(position, 0.0 , 1.0);
	TexCoord = vec2((position.x+0.5), 1- (position.y+0.5));
}