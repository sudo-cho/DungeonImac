#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <string>
#include <glimac/common.hpp>
#include <glimac/Sphere.hpp>

#include "typemonster.hpp"
#include "monster.hpp"
#include "level.hpp"
#include "game.hpp"
#include "draw.hpp"
#include "player.hpp"

using namespace std;
using namespace glimac;

#ifdef _WIN32
#include <windows.h>
int CALLBACK WinMain(
                     _In_ HINSTANCE hInstance,
                     _In_ HINSTANCE hPrevInstance,
                     _In_ LPSTR     lpCmdLine,
                     _In_ int       nCmdShow
                     )
#else
int main(int argc, char *argv[])
#endif
{
	// initialization
	Game game;

	Level level((string)"assets/level1.dml");

	cout << level.monsters.size() << endl;

	for (int i=0; i<(int)level.monsters.size(); i++){
		cout << level.monsters[i].type.name << endl;
	}

	//level.printLevelTest();

  Program program;

  GLuint locationMVPMatrix = 0, locationMVMatrix = 0, locationNormalMatrix = 0;

  //game.initProgram(&program, locationMVPMatrix, locationMVMatrix, locationNormalMatrix);

  // Sphere sphere(1, 32, 16);
  // SphereDraw objectSphere(&sphere);

  WallDraw objectwall;

	bool _continue = true;
	while(_continue){
		SDL_Event e;
		while(SDL_PollEvent(&e)) {
			if(e.type == SDL_QUIT) {
				_continue = false; // Leave the loop after this iteration
			}
		}

    /* game draw objects*/

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    objectwall.drawWall(locationMVPMatrix, locationMVMatrix, locationNormalMatrix);

    SDL_Delay(1000/60);
		SDL_GL_SwapWindow(game.window);
	}

  game.~Game();
  return 0;
}
