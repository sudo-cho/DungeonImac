#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <string>

#include "typemonster.hpp"
#include "monster.hpp"
#include "game.hpp"
#include "player.hpp"
#include "draw.hpp"

using namespace std;

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

	Player lucas(glm::vec2(3,3),2,50, 50, 1, 5);
	Player micka(glm::vec2(3,4),2,50, 35, 3, 6);

	cout << "Point de vie :" << lucas.getHealth() << endl;

	lucas.damageTake(&micka);

	cout << "Point de vie après :" << lucas.getHealth() << endl;

	TypeMonster type1("badmoon",50,50,20);

	Monster monster1(glm::vec2(5,5), 3, NULL, type1);

	monster1.changeDirection(2);
	monster1.move();


	cout << "Position monster : " << monster1.getPos().x << "," << monster1.getPos().y << ", Direction monster : " << monster1.getDir() << endl;

  ObjectDraw triangle;

	bool _continue = true;
	while(_continue){
		SDL_Event e;
		while(SDL_PollEvent(&e)) {
			if(e.type == SDL_QUIT) {
				_continue = false; // Leave the loop after this iteration
			}
		}

    /* game draw objects*/

    triangle.drawObject();

    SDL_Delay(1000/60);
		SDL_GL_SwapWindow(game.window);
	}
  game.~Game();
  return 0;
}
