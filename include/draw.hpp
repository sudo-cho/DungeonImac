#pragma once

#include <GL/gl.h>
#include <glimac/common.hpp>
#include <glimac/Sphere.hpp>

using namespace glimac;

class ObjectDraw{
public:
  GLuint vbo, vao;

  ObjectDraw();

  void drawObject();
};

class SphereDraw{
public:
  GLuint vbo, vao;
  glm::mat4 ProjMatrix, MVPMatrix, MVMatrix, NormalMatrix;

  SphereDraw(Sphere*);
  ~SphereDraw();

  void drawSphere(Sphere*, GLuint, GLuint, GLuint);
};

class WallDraw{
public:
  GLuint vbo, vao;
  glm::mat4 ProjMatrix, MVPMatrix, MVMatrix, NormalMatrix;

  WallDraw();
  ~WallDraw();

  void drawWall(GLuint, GLuint, GLuint);
};
