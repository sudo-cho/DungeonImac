#include <GL/glew.h>
#include <GL/gl.h>

#include "draw.hpp"

ObjectDraw::ObjectDraw(){
  /* VERTEX BUFFER OBJECT */
	glGenBuffers(1, &this->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);

	GLfloat vertices[] = {
		-0.5, -0.5,
		0.5, -0.5,
		0., 0.5,
	};

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);


  /* VERTEX ARRAY OBJECT */
	glGenVertexArrays(1, &this->vao);
	glBindVertexArray(this->vao);

	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(
                        0,
                        2,
                        GL_FLOAT,
                        GL_FALSE,
                        2 * sizeof(GLfloat),
                        0
                        );

	glBindVertexArray(0);

  /* TEXTURES */

  }

void ObjectDraw::drawObject(){
  glBindVertexArray(this->vao);

  glDrawArrays(GL_TRIANGLES,0,6);

  glBindVertexArray(0);
}
