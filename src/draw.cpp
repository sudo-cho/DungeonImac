#include <GL/glew.h>
#include <GL/gl.h>
#include <glimac/common.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/glm.hpp>
#include <SDL2/SDL.h>

#include "draw.hpp"

using namespace glimac;

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

SphereDraw::SphereDraw(Sphere * sphere){
  glGenBuffers(1, &this->vbo);
  glBindBuffer(GL_ARRAY_BUFFER, this->vbo);

  glBufferData(
                 GL_ARRAY_BUFFER,
                 sphere->getVertexCount()*sizeof(ShapeVertex),
                 sphere->getDataPointer(),
                 GL_STATIC_DRAW
               );

  glBindBuffer(GL_ARRAY_BUFFER, 0);

  glGenVertexArrays(1, &this->vao);
  glBindVertexArray(vao);
  glBindBuffer(GL_ARRAY_BUFFER, this->vbo);

  const GLuint VERTEX_ATTR_POSITION = 0;
  glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
  glVertexAttribPointer(
                        VERTEX_ATTR_POSITION,
                        3,
                        GL_FLOAT,
                        GL_FALSE,
                        sizeof(ShapeVertex),
                        (const GLvoid*)offsetof(ShapeVertex, position)
                        );

  const GLuint VERTEX_ATTR_NORMAL = 1;
  glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
  glVertexAttribPointer(
                        VERTEX_ATTR_NORMAL,
                        3,
                        GL_FLOAT,
                        GL_FALSE,
                        sizeof(ShapeVertex),
                        (const GLvoid*)offsetof(ShapeVertex, normal)
                        );

  const GLuint VERTEX_ATTR_TEXCOORDS = 2;
  glEnableVertexAttribArray(VERTEX_ATTR_TEXCOORDS);
  glVertexAttribPointer(
                        VERTEX_ATTR_TEXCOORDS,
                        2,
                        GL_FLOAT,
                        GL_FALSE,
                        sizeof(ShapeVertex),
                        (const GLvoid*)offsetof(ShapeVertex, texCoords)
                        );

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
  // Les matrices
  this->ProjMatrix = glm::perspective(
                                          glm::radians(70.f),
                                          800.f / 600.f,
                                          0.1f,
                                          100.f
                                          );

  this->MVMatrix = glm::translate(glm::mat4(), glm::vec3(0.0f, 0.0f, -5.0f));
  this->NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
  this->MVPMatrix = ProjMatrix * MVMatrix ;

  glEnable(GL_DEPTH_TEST);

}
void SphereDraw::drawSphere(Sphere *sphere, GLuint locationMVPMatrix, GLuint locationMVMatrix, GLuint locationNormalMatrix){
  glBindVertexArray(this->vao);

  glUniformMatrix4fv(
                     locationMVPMatrix,
                     1,
                     GL_FALSE,
                     glm::value_ptr(MVPMatrix)
                     );

  glUniformMatrix4fv(
                     locationMVMatrix,
                     1,
                     GL_FALSE,
                     glm::value_ptr(this->MVMatrix)
                     );

  glUniformMatrix4fv(
                     locationNormalMatrix,
                     1,
                     GL_FALSE,
                     glm::value_ptr(this->NormalMatrix)
                     );

  glDrawArrays(GL_TRIANGLES, 0, sphere->getVertexCount());
  glBindVertexArray(0);

}
SphereDraw::~SphereDraw(){
  glDeleteBuffers(1, &this->vbo);
  glDeleteVertexArrays(1, &this->vao);
}


WallDraw::WallDraw(){
  glGenBuffers(1, &this->vbo);
  glBindBuffer(GL_ARRAY_BUFFER, this->vbo);

  GLfloat vertices [] = {
    -0.5f,0.f,0.f,
    -0.5f,0.f,0.5f,
    0.f,0.5f,0.f,
    0.f,0.5f,0.5f
  };

  glBufferData(
               GL_ARRAY_BUFFER,
               sizeof(vertices),
               vertices,
               GL_STATIC_DRAW
               );

  glBindBuffer(GL_ARRAY_BUFFER, 0);

  glGenVertexArrays(1, &this->vao);
  glBindVertexArray(vao);
  glBindBuffer(GL_ARRAY_BUFFER, this->vbo);

  const GLuint VERTEX_ATTR_POSITION = 0;
  glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
  glVertexAttribPointer(
                        VERTEX_ATTR_POSITION,
                        3,
                        GL_FLOAT,
                        GL_FALSE,
                        sizeof(vertices),
                        0
                        );

  const GLuint VERTEX_ATTR_NORMAL = 1;
  glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
  glVertexAttribPointer(
                        VERTEX_ATTR_NORMAL,
                        3,
                        GL_FLOAT,
                        GL_FALSE,
                        sizeof(vertices),
                        0
                        );

  const GLuint VERTEX_ATTR_TEXCOORDS = 2;
  glEnableVertexAttribArray(VERTEX_ATTR_TEXCOORDS);
  glVertexAttribPointer(
                        VERTEX_ATTR_TEXCOORDS,
                        2,
                        GL_FLOAT,
                        GL_FALSE,
                        sizeof(vertices),
                        0
                        );

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}

WallDraw::~WallDraw() {
  glDeleteBuffers(1, &this->vbo);
  glDeleteVertexArrays(1, &this->vao);
}
void WallDraw::drawWall(GLuint locationMVPMatrix, GLuint locationMVMatrix, GLuint locationNormalMatrix){

  glBindVertexArray(this->vao);

  // glUniformMatrix4fv(
  //                    locationMVPMatrix,
  //                    1,
  //                    GL_FALSE,
  //                    glm::value_ptr(MVPMatrix)
  //                    );

  // glUniformMatrix4fv(
  //                    locationMVMatrix,
  //                    1,
  //                    GL_FALSE,
  //                    glm::value_ptr(this->MVMatrix)
  //                    );

  // glUniformMatrix4fv(
  //                    locationNormalMatrix,
  //                    1,
  //                    GL_FALSE,
  //                    glm::value_ptr(this->NormalMatrix)
  //                    );


  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

  glBindVertexArray(0);

}
