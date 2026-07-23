#include <graphics/init.h>
#include <SDL2/SDL.h>


bool init_graphic_engine() {
	// Initialize SDL2 Video
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		return false;
	}

	return true;
}
