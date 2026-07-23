#ifndef WINDOW_SYSTEM_PHYSTICS_H
#define WINDOW_SYSTEM_PHYSTICS_H

/**
	Construir un sistema de gestión de ventanas sobre SDL2 que cumpla los siguientes requisitos:
		1. Identificación de ventanas mediante IDs numéricos.
		2. Un máximo de 8 ventanas. -> con posibilidad de escalar a futuro a mas ventanas si es requerido.
		3. Crear ventanas libremente y obtener su ID.
		4. Gestionar cada ventana mediante la API ofrecida aquí y el ID proveido.
		5. Eliminar ventanas.
		6. Liberar los recursos utilizados por cada ventana.
*/


/** for SDL_Window  */
#include <SDL2/SDL.h>

/** for uint32_t  */
#include <stdint.h>

/** This macro define the max of windows that the system can manage */
#define MAX_WINDOWS_LIMIT 8


/** Define exit status codes from window operations */

#define WND_EXIT_FAILURE						   4294967295
#define WND_EXIT_SUCESSFULLY 					   (1 << 0)

#define WND_OPERATION_RESULT_CREATED_SUCESSFULLY   WND_EXIT_SUCESSFULLY

/** Window Management Operation Result Error Codes */
#define WND_OPERATION_RESULT_FAILED_TO_CREATE      (1 << 1)
#define WND_OPERATION_RESULT_FAILED_TO_GET_SURFACE (1 << 2)

/** Data type for Window  Identifiers */
typedef uint32_t WindowID;

/** Data type for window result operations */
typedef uint32_t WindowOperationResult;


/** Struct to store window properties */
typedef struct __tag_window_properties__ 
{
	WindowID wid;            // Window ID - This should acts like Window Index in
							 // windows array in global window system state.
	bool is_active;          // This indicates when this window slot is used by an active window

	// SDL2 Backend Dependencies
	SDL_Window* backend_wnd; // Backend Window Instance

	SDL_Surface* surface; // Window Surface

	// Other window properties like dimensions and title
	uint32_t    width;
	uint32_t    height;
	const char* title;
} WindowElement;

/** Window System state machine */
typedef struct __tag_window_system_state__ {
	WindowElement windows[ MAX_WINDOWS_LIMIT ];
} WindowSystemState;

/** Global Window System State */
extern WindowSystemState global_window_system_state;

WindowOperationResult create_window( 
	WindowID* wid, 
	uint32_t window_width, 
	uint32_t window_height, 
	const char* title 
);

[[maybe_unused]] WindowOperationResult destroy_window( WindowID wid );


#endif // WINDOW_SYSTEM_PHYSTICS
