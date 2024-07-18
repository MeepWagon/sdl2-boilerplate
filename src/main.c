#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

// Screen dimension constants
#define SCREEN_HEIGHT 640
#define SCREEN_WIDTH 480

int main(int argc, char **argv) {
    // Initializing window & surface variables
    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;

    // Fail if SDL doesnt initialize
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL Could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }
    
    // Create window
    window = SDL_CreateWindow("SDL Boilerplate", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    }

    // Get window surface
    screenSurface = SDL_GetWindowSurface(window);

    // Fill the surface white
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

    // Update the surface
    SDL_UpdateWindowSurface(window); 
    
    //Hack to get window to stay up
    SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
    
    //Quit SDL & Destroy window
	SDL_DestroyWindow(window);
	SDL_Quit();
    
    return 0;
}