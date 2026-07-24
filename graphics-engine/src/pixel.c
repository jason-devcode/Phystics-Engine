/** for window system management utilities */
#include <graphics/window_system.h>

/** for pixel management definitions */
#include <graphics/pixel.h>

uint32_t* global_framebuffer        = NULL;

int32_t global_framebuffer_width  = 0;
int32_t global_framebuffer_pitch  = 0;
int32_t global_framebuffer_height = 0;

WindowID global_framebuffer_current_wid = 99999999;

void set_current_window_by_wid( WindowID wid ) {
	// First search window by its window id
	WindowElement* wnd = GET_WINDOW_REF_BY_INDEX( wid );

	global_framebuffer_width  = wnd->surface->w;
	global_framebuffer_height = wnd->surface->h;
	
	global_framebuffer        = wnd->surface->pixels;

	// Shift Right 2 bits is equal to divide by 4 
	// this -> Convert byte counter to dword counter.
	global_framebuffer_pitch  = wnd->surface->pitch >> 2;

	global_framebuffer_current_wid = wid;
}


void clear_framebuffer( [[maybe_unused]]  uint32_t clear_color ) {
	if( global_framebuffer == NULL ) return;
	for( int32_t pixel_index = 0; pixel_index < global_framebuffer_pitch * global_framebuffer_height; ++pixel_index )
		global_framebuffer[ pixel_index ] = clear_color; 
}

void put_pixel( int32_t x_coord, int32_t y_coord, uint32_t color ) {
	// Safe check pixel outbounds
	if( 
		x_coord < 0 || x_coord > ( global_framebuffer_width  - 1 ) || // X bound
		y_coord < 0 || y_coord > ( global_framebuffer_height - 1 )    // Y bound		
	)
		return;

	int32_t pixel_index = ( y_coord * global_framebuffer_pitch ) + x_coord;
	
	global_framebuffer[ pixel_index ] = color;
}
