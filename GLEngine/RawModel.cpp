#include "RawModel.h"

RawModel::RawModel()
{
}

RawModel::RawModel(GLuint VAO, GLuint VertC)
{
	VAOid = VAO;
	verticeCount = VertC;
}

GLuint RawModel::getVAOid()
{
	return VAOid;
}

GLuint RawModel::getVertCount()
{
	return verticeCount;
}
