#pragma once

#include <GL/gl.h>

class ObjectDraw{
public:
  GLuint vbo, vao;

  ObjectDraw();

  void drawObject();
};
