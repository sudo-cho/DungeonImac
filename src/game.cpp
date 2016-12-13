#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>

#include "game.hpp"

Game::Game(){
  SDL_Init(SDL_INIT_VIDEO);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

  this->window = SDL_CreateWindow(
                                        "SDL2/OpenGL Demo", 400, 200, 640, 480,
                                        SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE);

  // Check that the window was successfully created
  if (window == NULL) {
    // In the case that the window could not be made...
    printf("Could not create window: %s\n", SDL_GetError());
  }

  this->glcontext = SDL_GL_CreateContext(window);

  // Initialisation de GLEW; nous verrons dans le prochain TP à quoi cela sert.
  GLint error;
  if(GLEW_OK != (error = glewInit())) {
    std::cerr << "Impossible d'initialiser Glew" << std::endl;
  }

  std::cout << glGetString(GL_VERSION) << std::endl;
}

Game::~Game(){
  SDL_GL_DeleteContext(this->glcontext);
	SDL_Quit();
}