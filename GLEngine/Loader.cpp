#define _CRT_SECURE_NO_DEPRECATE
#include "Loader.h"

RawModel Loader::objToRawModel(const char * path)
{
	std::vector< GLuint > vertexIndices, uvIndices, normalIndices;
	std::vector< glm::vec3 > temp_vertices;
	std::vector< glm::vec2 > temp_uvs;
	std::vector< glm::vec3 > temp_normals;


	FILE * file = fopen(path, "r");
	if (file == NULL) {
		printf("Impossible to open the file !\n");
	}
	while (1) {

		char lineHeader[128];
		// read the first word of the line
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
			break; // EOF = End Of File. Quit the loop.

				   // else : parse lineHeader
		if (strcmp(lineHeader, "v") == 0) {
			glm::vec3 vertex;
			fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
			temp_vertices.push_back(vertex);
		}
		else if (strcmp(lineHeader, "vt") == 0) {
			glm::vec2 uv;
			fscanf(file, "%f %f\n", &uv.x, &uv.y);
			temp_uvs.push_back(uv);
		}
		else if (strcmp(lineHeader, "vn") == 0) {
			glm::vec3 normal;
			fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
			temp_normals.push_back(normal);
		}
		else if (strcmp(lineHeader, "f") == 0) {
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
			if (matches != 9) {
				printf("File can't be read by parser : ( Try exporting with other options\n");
			}
			vertexIndices.push_back(vertexIndex[0]-1);
			vertexIndices.push_back(vertexIndex[1]-1);
			vertexIndices.push_back(vertexIndex[2]-1);
			uvIndices.push_back(uvIndex[0]-1);
			uvIndices.push_back(uvIndex[1]-1);
			uvIndices.push_back(uvIndex[2]-1);
			normalIndices.push_back(normalIndex[0]-1);
			normalIndices.push_back(normalIndex[1]-1);
			normalIndices.push_back(normalIndex[2]-1);
		}
	}
	GLuint stride = 8;

	std::vector<GLfloat> vertices (temp_vertices.size()*stride);

	for (int x = 0; x < vertexIndices.size(); x ++)
	{
		vertices[vertexIndices[x]*stride] = temp_vertices[vertexIndices[x]].x;
		vertices[vertexIndices[x]*stride+1] = temp_vertices[vertexIndices[x]].y;
		vertices[vertexIndices[x]*stride+2] = temp_vertices[vertexIndices[x]].z;
		vertices[vertexIndices[x]*stride+3] = temp_uvs[uvIndices[x]].x;
		vertices[vertexIndices[x]*stride+4] = temp_uvs[uvIndices[x]].y;
		vertices[vertexIndices[x]*stride+5] = temp_normals[normalIndices[x]].x;
		vertices[vertexIndices[x]*stride+6] = temp_normals[normalIndices[x]].y;
		vertices[vertexIndices[x]*stride+7] = temp_normals[normalIndices[x]].z;

	}

	std::cout << path << ": " << vertexIndices.size() << "\n";

	GLuint VAOid = createVAO();
	GLuint VertexBufferid = createVBO(&vertices[0], vertices.size());
	createVertexAttribPointer(0, 3, 8, 0);
	createVertexAttribPointer(1, 2, 8, 3);
	createVertexAttribPointer(2, 3, 8, 5);
	GLuint EBOid = createEBO(&vertexIndices[0], vertexIndices.size());
	glBindVertexArray(0);

	return RawModel(VAOid, vertexIndices.size());
}

GLuint Loader::loadToVAOid(GLfloat vertices[], GLuint size)
{
	GLuint VAOid = createVAO();
	GLuint VertexBufferid = createVBO(vertices, size);
	createVertexAttribPointer(0, 2, 2, 0);
	//createVertexAttribPointer(1, 2, 5, 3);
	glBindVertexArray(0);

	return VAOid;
}

GLuint Loader::loadToVAOid(GLfloat vertices[], GLuint verticessize, GLfloat uvcoords[], GLuint uvcoordssize)
{
	GLuint VAOid = createVAO();
	GLuint VertexBufferid = createVBO(vertices, verticessize);
	createVertexAttribPointer(0, 3, 5, 0);
	//GLuint UVCoordsBufferid = createVBO(uvcoords, uvcoordssize);
	createVertexAttribPointer(1, 2, 5, 3);
	glBindVertexArray(0);
	return VAOid;
}

GLuint Loader::loadToVAOid(GLfloat vertices[], GLuint verticessize, GLfloat uvcoords[], GLuint uvcoordssize, GLuint indices[], GLuint indicessize)
{
	GLuint VAOid = createVAO();
	GLuint VertexBufferid = createVBO(vertices, verticessize);
	createVertexAttribPointer(0, 3, 3, 0);
	GLuint UVCoordsBufferid = createVBO(uvcoords, uvcoordssize);
	createVertexAttribPointer(1, 2, 2, 0);
	GLuint EBOid = createEBO(indices, indicessize);
	glBindVertexArray(0);
	return VAOid;
}

GLuint Loader::loadToTextureID(std::string name)
{
	GLuint textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object
											// Set our texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	// Load, create texture and generate mipmaps
	int width, height;
	unsigned char* image = SOIL_load_image(name.c_str(), &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.

	textures.push_back(textureID);

	return textureID;
}

GLuint Loader::createVAO()
{
	GLuint VAOid;
	vaos.push_back(VAOid);
	glGenVertexArrays(1, &VAOid);
	glBindVertexArray(VAOid);
	return VAOid;
}

GLuint Loader::createVBO(GLfloat vertices[], GLuint size)
{
	GLuint VBOid;
	vbos.push_back(VBOid);
	glGenBuffers(1, &VBOid);
	glBindBuffer(GL_ARRAY_BUFFER, VBOid);
	glBufferData(GL_ARRAY_BUFFER, size*sizeof(GLfloat), vertices, GL_STATIC_DRAW);
	return VBOid;
}

GLuint Loader::createEBO(GLuint indices[], GLuint size)
{
	GLuint EBOid;
	ebos.push_back(EBOid);
	glGenBuffers(1, &EBOid);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOid);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size*sizeof(GLuint), indices, GL_STATIC_DRAW);
	return EBOid;
}

void Loader::createVertexAttribPointer(GLuint position, GLuint size, GLuint stride, GLuint offset)
{
	glVertexAttribPointer(position, size, GL_FLOAT, GL_FALSE, stride * sizeof(GLfloat), (GLvoid*)(offset*sizeof(GLfloat)));
	glEnableVertexAttribArray(position);
}

void Loader::flush()
{
	for (GLuint vao : vaos)
	{
		glDeleteVertexArrays(1, &vao);
	}
	for (GLuint vbo : vaos)
	{
		glDeleteBuffers(1, &vbo);
	}
	for (GLuint ebo : ebos)
	{
		glDeleteBuffers(1, &ebo);
	}
	for (GLuint texture : textures)
	{
		glDeleteTextures(1, &texture);
	}
}