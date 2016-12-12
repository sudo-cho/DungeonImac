#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>

using namespace std;

#ifdef _WIN32
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

  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *window = SDL_CreateWindow(
                                        "SDL2/OpenGL Demo", 0, 0, 640, 480,
                                        SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE);

  SDL_GLContext glcontext = SDL_GL_CreateContext(window);

  // Check that the window was successfully created
  if (window == NULL) {
    // In the case that the window could not be made...
    printf("Could not create window: %s\n", SDL_GetError());
    return 1;
  }

	// Initialisation de GLEW; nous verrons dans le prochain TP à quoi cela sert.
	GLint error;
	if(GLEW_OK != (error = glewInit())) {
		std::cerr << "Impossible d'initialiser Glew" << std::endl;
		return 1;
	}

  cout << glGetString(GL_VERSION) << endl;

	// Création d'un Vertex Buffer Object et d'un Vertex Array Object
	GLuint vbo, vao;

	// Allocation d'un Vertex Buffer Object:
	glGenBuffers(1, &vbo);

	// "vbo" devient le VBO courant sur la cible GL_ARRAY_BUFFER:
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

		// Tableau des attributs des sommets
	GLfloat vertices[] = {
		-0.5, -0.5, // Premier vertex
		0.5, -0.5, // Deuxième vertex
		0., 0.5, // Troisème vertex
	};

	// Stockage des données du tableau vertices dans le vbo placé sur GL_ARRAY_BUFFER (c'est à dire "vbo" ici) :
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Plus de VBO sur la cible GL_ARRAY_BUFFER:
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Allocation d'un Vertex Array Objet:
	glGenVertexArrays(1, &vao);

	// "vao" devient le VAO courant:
	glBindVertexArray(vao);

		// "vbo" devient le VBO courant sur la cible GL_ARRAY_BUFFER:
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	// Activation de l'attribut de vertex 0; nous l'interpretons comme la position
	glEnableVertexAttribArray(0 /* Incide attribut*/);
	// On spécifie le type de donnée de l'attribut position ainsi que la manière dont il est stocké dans le VBO
	glVertexAttribPointer(
		0 /* Indice attribut */,
		2 /* Nombre de composantes */,
		GL_FLOAT /* Type d'une composante */,
		GL_FALSE /* Pas de normalisation */,
		2 * sizeof(GLfloat) /* Taille en octet d'un vertex complet entre chaque attribut position */,
		0 /* OpenGL doit utiliser le VBO attaché à GL_ARRAY_BUFFER et commencer à l'offset 0 */);

	// Plus de VAO courant:
	glBindVertexArray(0);

	bool _continue = true;
	while(_continue){
		SDL_Event e;
		while(SDL_PollEvent(&e)) {
			if(e.type == SDL_QUIT) {
				_continue = false; // Leave the loop after this iteration
			}
		}
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES,0,6);
		glBindVertexArray(0);
		SDL_Delay(1000/60);
    SDL_GL_SwapWindow(window);
	}

  SDL_GL_DeleteContext(glcontext);
	SDL_Quit();
	return 0;
}
