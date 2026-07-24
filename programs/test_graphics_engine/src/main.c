#include <stdio.h>
#include <graphics.h>

#include <SDL2/SDL.h>


void process_events( bool *is_running ) 
{
	SDL_Event event;

	// Poll events from queue
	while ( SDL_PollEvent( &event ) ) {
		switch( event.type ) {
			case SDL_QUIT:
				*is_running = false;
				break;
			default:
				break;
		}	
	}
}

void draw_fill_circle( int xCoord, int yCoord, int radius, uint32_t color ) 
{
	for( int Y = -radius; Y <= radius; ++Y )
		for( int X = -radius; X <= radius; ++X )
			if( (X*X + Y*Y) < radius*radius )
				put_pixel( X+xCoord, Y+yCoord, color );
}

void draw_outline_circle( int xCoord, int yCoord, int radius, int weight, uint32_t color ) 
{
	int innerRadius = radius - weight;

	int sqrRadius = radius * radius;
	int sqrInnerRadius = innerRadius * innerRadius;
	
	for( int Y = -radius; Y <= radius; ++Y )
		for( int X = -radius; X <= radius; ++X )
		{
			int sqrCoord = X*X + Y*Y;
			if( sqrCoord < sqrRadius && sqrCoord > sqrInnerRadius )
				put_pixel( X+xCoord, Y+yCoord, color );
		}
}


#define W 512
#define H 512

int main( )
{
	init_graphic_engine();
	
	WindowID main_window; 

	if( create_window( &main_window, W, H, "Hello, World!" ) != WND_OPERATION_RESULT_CREATED_SUCESSFULLY ) 
	{
		quit_graphic_engine();
		return EXIT_FAILURE;
	}

	bool is_running = true;

	set_current_window_by_wid( main_window );	

	while( is_running ) 
	{
		process_events( &is_running );
		clear_framebuffer( 0xFF0000DD );

		draw_outline_circle( W >> 1, H >> 1, 128, 8, 0xFFFFFF00 );
		
		update_window( main_window );
	}

	destroy_window( main_window );

	quit_graphic_engine();

	return EXIT_SUCCESS;;
}
