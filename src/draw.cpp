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
		-0.5f, -0.5f,
		0.5f, -0.5f,
		0.f, 0.5f
	};

	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);


  /* VERTEX ARRAY OBJECT */
	glGenVertexArrays(1, &this->vao);
	glBindVertexArray(this->vao);

	glEnableVertexAttribArray(0);
	
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
	glVertexAttribPointer(0, 2, GL_FLOAT,GL_FALSE, 2 * sizeof(GLfloat), 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	glBindVertexArray(0);

}

void ObjectDraw::drawObject(){
  glBindVertexArray(this->vao);

  glDrawArrays(GL_TRIANGLES,0,3);

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

  glUniformMatrix4fv(locationMVPMatrix, 1, GL_FALSE, glm::value_ptr(MVPMatrix));

  glUniformMatrix4fv(locationMVMatrix, 1, GL_FALSE, glm::value_ptr(this->MVMatrix));

  glUniformMatrix4fv(locationNormalMatrix, 1, GL_FALSE, glm::value_ptr(this->NormalMatrix));

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
    -0.5f,-0.5f,
    0.5f,-0.5f,
    -0.5f,0.5f,
    0.5f,0.5f
  };
  /*
  -1.f,-1.f,
    1.f,-1.f,
    -1.f,1.f,
    1.f,1.f*/

  glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ARRAY_BUFFER, 0);

  glGenVertexArrays(1, &this->vao);
  glBindVertexArray(this->vao);
  
  //const GLuint VERTEX_ATTR_POSITION = 0;
  //glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
  
  glEnableVertexAttribArray(0);
  
  glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), 0);

  /*const GLuint VERTEX_ATTR_NORMAL = 1;
  glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
  glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);

  const GLuint VERTEX_ATTR_TEXCOORDS = 2;
  glEnableVertexAttribArray(VERTEX_ATTR_TEXCOORDS);
  glVertexAttribPointer(VERTEX_ATTR_TEXCOORDS, 2, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);*/

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
  
  ProjMatrix = glm::perspective (glm::radians(70.f),(float)800/600,0.1f,100.f);
  NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
}

WallDraw::~WallDraw() {
  glDeleteBuffers(1, &this->vbo);
  glDeleteVertexArrays(1, &this->vao);
}

glm::mat3 translate(float tx, float ty) {
	glm::mat3 M = glm::mat3(glm::vec3(1,0,0), glm::vec3(0,1,0), glm::vec3(tx,ty,1));
	return M;
}

glm::mat3 scale(float tx, float ty) {
	glm::mat3 M = glm::mat3(glm::vec3(tx,0,0), glm::vec3(0,ty,0), glm::vec3(0,0,1));
	return M;
}

glm::mat3 rotate(float a) {
	glm::mat3 M = glm::mat3(glm::vec3(cos(a),-sin(a),0), glm::vec3(sin(a),cos(a),0), glm::vec3(0,0,1));
	return M;
}

void WallDraw::drawWall(GLuint locationMVPMatrix, GLuint locationMVMatrix, GLuint locationNormalMatrix, glm::mat4 MVMat){

  glBindVertexArray(this->vao);
  
  MVMatrix = MVMat;

  glUniformMatrix4fv(locationMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix));
  glUniformMatrix4fv(locationMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
  glUniformMatrix4fv(locationNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));

  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

  glBindVertexArray(0);

}

PathDraw::PathDraw(){
}

PathDraw::~PathDraw(){
}

void PathDraw::drawPath(GLuint locationMVPMatrix, GLuint locationMVMatrix, GLuint locationNormalMatrix, Level level, Camera camera){
	glm::mat4 MVMat = glm::mat4(1.f);
	int test = 0;
	for (int i=0 ; i<(int)level.map.size() ; i++){
		if (level.map[i].type == 1){
			test++;
			WallDraw path;
			int translateZ = camera.position.x - level.map[i].position.x;
			int translateX = camera.position.y - level.map[i].position.y;
			//std::cout << "Z = " << translateZ << ", X = " << translateX << std::endl;
			MVMat = glm::translate (glm::mat4(1.f), glm::vec3(-translateX,-0.5f,translateZ));
			// rotate 1.5708f : 90 degrés
			MVMat = glm::rotate(MVMat, 1.5708f, glm::vec3(1, 0, 0));
			path.drawWall(locationMVPMatrix,locationMVMatrix,locationNormalMatrix,MVMat);
			
			// dessin murs
			if (level.map[i-1].type == 0){
				WallDraw pathWall;
				MVMat = glm::translate (glm::mat4(1.f), glm::vec3(-translateX,0.f,translateZ + 0.5f));
				pathWall.drawWall(locationMVPMatrix,locationMVMatrix,locationNormalMatrix,MVMat);
			}
			if (level.map[i+1].type == 0){
				WallDraw pathWall;
				MVMat = glm::translate (glm::mat4(1.f), glm::vec3(-translateX,0.f,translateZ - 0.5f));
				pathWall.drawWall(locationMVPMatrix,locationMVMatrix,locationNormalMatrix,MVMat);
			}
			if (level.map[i-level.width].type == 0){
				WallDraw pathWall;
				MVMat = glm::translate (glm::mat4(1.f), glm::vec3(-translateX - 0.5f,0.f,translateZ));
				MVMat = glm::rotate(MVMat, 1.5708f, glm::vec3(0, 1, 0));
				pathWall.drawWall(locationMVPMatrix,locationMVMatrix,locationNormalMatrix,MVMat);
			}
			if (level.map[i+level.width].type == 0){
				WallDraw pathWall;
				MVMat = glm::translate (glm::mat4(1.f), glm::vec3(-translateX + 0.5f,0.f,translateZ));
				MVMat = glm::rotate(MVMat, 1.5708f, glm::vec3(0, 1, 0));
				pathWall.drawWall(locationMVPMatrix,locationMVMatrix,locationNormalMatrix,MVMat);
			}
		}
	}
}
