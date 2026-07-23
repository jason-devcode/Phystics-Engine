#include <stdio.h>
#include <graphics.h>

int main( )
{
	init_graphic_engine();
	
	WindowID main_window; 

	if( create_window( &main_window,  512, 512, "Hello, World!" ) != WND_OPERATION_RESULT_CREATED_SUCESSFULLY ) {
		quit_graphic_engine();
		return EXIT_FAILURE;
	}

	getchar();

	destroy_window( main_window );

	quit_graphic_engine();

	return EXIT_SUCCESS;;
}
