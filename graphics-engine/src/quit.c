#include <graphics/quit.h>
#include <SDL2/SDL.h>

bool quit_graphic_engine() {
	SDL_Quit();

	return true;
}
