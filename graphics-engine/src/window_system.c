/**
	Fecha de creación: 22-7-2026

	Este fichero contiene la implementación del sistema de gestión de ventanas.

	Como se tiene planteado que funcione:
		El sistema debe de funcionar mediante un arreglo 
*/
#include <graphics/window_system.h>

#include <SDL2/SDL.h>

/**
* Return a window element from windows elements in  window system state.
*/
#define GET_WINDOW_BY_INDEX( window_index )\
	global_window_system_state.windows[ window_index ]

/**
* Return a window element reference from windows elements in window system state.
*/
#define GET_WINDOW_REF_BY_INDEX( window_index )\
	&(GET_WINDOW_BY_INDEX( window_index ))

WindowSystemState global_window_system_state = { 
	.windows = {}
};


/**
*  Search for the first free window element in windows 
*  elements array inside global window system state.
*/
WindowElement* find_first_free_window() {
	for( uint32_t index_iterator = 0; index_iterator < MAX_WINDOWS_LIMIT; ++index_iterator ) {

		WindowElement* current_window = GET_WINDOW_REF_BY_INDEX( index_iterator );

		if( current_window->is_active == false ) {
			// set window id before return
			current_window->wid = index_iterator;			
			return current_window;
		}
	}
			
	// There's no empty window elements
	return NULL;
}

/**
* Search for an active window element in windows elements array 
* inside global window system state using its window id.
*/
WindowElement* find_active_window_by_wid( WindowID wid ) {
	// Remember: wid = window index
	WindowElement* wnd = GET_WINDOW_REF_BY_INDEX( wid );

	if( wnd->is_active )
		return wnd;

	// Could'nt found an active window with this wid
	return NULL;
}


WindowOperationResult create_window( 
	WindowID* wid, 
	uint32_t window_width, 
	uint32_t window_height, 
	const char* title 
) {
	// Could'nt execute without a way to return wid allocated
	if( wid == NULL )
		return WND_EXIT_FAILURE;

	// First find a free window element
	WindowElement* wnd = find_first_free_window();

	// Initialize window element props
	wnd->width  = window_width;
	wnd->height = window_height;
	wnd->title  = title;

	// Create SDL Window
	wnd->backend_wnd = SDL_CreateWindow( 
		title, 
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		(int32_t) window_width, (int32_t) window_height,
		SDL_WINDOW_SHOWN
	);

	// if failed to create backend window
	if( wnd->backend_wnd == NULL )
		return WND_OPERATION_RESULT_FAILED_TO_CREATE;

	// Get Window Surface
	wnd->surface = SDL_GetWindowSurface( wnd->backend_wnd );

	// if failed to get window surface
	if( wnd->surface == NULL )
	{
		// Release window resources already allocated
		SDL_DestroyWindow( wnd->backend_wnd );
		return WND_OPERATION_RESULT_FAILED_TO_GET_SURFACE;
	}

	// Finally set return wid
	*wid = wnd->wid;

	return WND_OPERATION_RESULT_CREATED_SUCESSFULLY;
}


WindowOperationResult destroy_window( WindowID wid ) {
	WindowElement *wnd = find_active_window_by_wid( wid );

	if( wnd == NULL )
		return WND_EXIT_FAILURE;

	SDL_DestroyWindow( wnd->backend_wnd );

	// Release props
	wnd->backend_wnd = NULL;
	wnd->surface     = NULL;
	wnd->width       = 0;
	wnd->height      = 0;
	
	return WND_EXIT_SUCESSFULLY;
}


