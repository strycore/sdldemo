#include <SDL2/SDL.h>
#include <GL/gl.h>

int main(int argc, char **argv) {
    int done = 0;

    SDL_Window *window = SDL_CreateWindow(
        "SDL2/OpenGL Demo", 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        640, 480,
        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    // Create an OpenGL context associated with the window.
    SDL_GLContext glcontext = SDL_GL_CreateContext(window);

    SDL_Event event;
    // now you can make GL calls.
    glClearColor(0,1,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow(window);
    while (!done) {
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                done = 1;
            }
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        done = 1;
                        break;
                    case SDLK_a:
                        printf("A\n");
                    default:
                        break;
                }
            }
        };
    }
    // Once finished with OpenGL functions, the SDL_GLContext can be deleted.
    SDL_GL_DeleteContext(glcontext);
    SDL_Quit();
}

