#include "RenderSystem.h"



RenderSystem::RenderSystem()
{
	simpleShader = Shader("Simple.vs", "Simple.fs");
	GuiShader = Shader("GuiShader.vs", "GuiShader.fs");
	glEnable(GL_DEPTH_TEST);
}

void RenderSystem::render(std::unordered_map<GLuint, GLuint> & textureID, std::unordered_map<GLuint, mystructure> & models, std::unordered_map<GLuint, glm::vec3> & position, std::unordered_map<GLuint, 
	glm::vec3> & orientation)
{
	simpleShader.Use();

	glUniformMatrix4fv(glGetUniformLocation(simpleShader.Program, "viewMatrix"), 1, GL_FALSE, glm::value_ptr(viewMat));
	glUniformMatrix4fv(glGetUniformLocation(simpleShader.Program, "projectionMatrix"), 1, GL_FALSE, glm::value_ptr(projectionMat));
	glUniform3f(glGetUniformLocation(simpleShader.Program, "viewPos"), positionVec.x, positionVec.y, positionVec.z);

	//glUniform3f(glGetUniformLocation(simpleShader.Program, "light.lightPosition"), 4.0f, 10.0f, 4.0f);
	glUniform3f(glGetUniformLocation(simpleShader.Program, "light.lightDirection"), -0.2f, -1.0f, -0.3f);
	glUniform3f(glGetUniformLocation(simpleShader.Program, "light.lightColor"), 0.5f, 0.5f, 0.5f);
	glUniform3f(glGetUniformLocation(simpleShader.Program, "ambientColor"), 0.5f, 0.5f, 0.5f);

	for (auto i : models)
	{
		GLuint key = i.first;
		glm::mat4 trans;

		trans = glm::translate(trans, position[key]);
		if (orientation.count(key) == 1) {
			trans = glm::rotate(trans, -orientation[key].y, glm::vec3(0.0f, 1.0f, 0.0f));
			trans = glm::rotate(trans, -orientation[key].x, glm::vec3(1.0f, 0.0f, 0.0f));
		}
		
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, textureID[key]);
		glUniform1i(glGetUniformLocation(simpleShader.Program, "ourTexture"), 0);

		glUniformMatrix4fv(glGetUniformLocation(simpleShader.Program, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(trans));

		glBindVertexArray(i.second.VAOid);
		//glEnableVertexAttribArray(0);

		//glDrawArrays(GL_TRIANGLES, 0, i.second.verticeCount);
		glDrawElements(GL_TRIANGLES, i.second.verticeCount, GL_UNSIGNED_INT, 0);

		//glDisableVertexAttribArray(0);
		glBindVertexArray(0);
	}
}

void RenderSystem::renderGUI(std::unordered_map<GLuint, GLuint> & textureID, std::unordered_map<GLuint, glm::vec3> & GuiPosition, std::unordered_map<GLuint,glm::vec3> & Scale, std::unordered_map<GLuint, mystructure> & models)
{
	GuiShader.Use();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_DEPTH_TEST);

	for (auto i : GuiPosition)
	{
		GLuint key = i.first;
		
		glm::mat4 trans;
		trans = glm::translate(trans, GuiPosition[key]);
		trans = glm::scale(trans, Scale[key]);
		glUniformMatrix4fv(glGetUniformLocation(GuiShader.Program, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(trans));

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, textureID[key]);
		glUniform1i(glGetUniformLocation(GuiShader.Program, "ourTexture"), 0);

		glBindVertexArray(quad);

		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
		//glDrawElements(GL_TRIANGLES, models[key].verticeCount, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);
	}

	glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
}

void RenderSystem::prepare( GLuint & width, GLuint & height, GLfloat & fov, glm::vec3 & position, glm::vec3 & orientation)
{
	glClearColor(0.5f, 0.8f, 0.9f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glm::mat4 projection, view;

	projection = glm::perspective(fov, width*1.0f / height*1.0f, 0.1f, 500.0f);

	view = glm::rotate(view, orientation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	view = glm::rotate(view, orientation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	view = glm::translate(view, -position);

	viewMat = view;
	projectionMat = projection;
	positionVec = position;
}