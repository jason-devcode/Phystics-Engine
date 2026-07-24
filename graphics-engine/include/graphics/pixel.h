/**
* Created at: 23-07-2026
*/
#ifndef PHYSTICS_GRAPHIC_ENGINE_PIXEL_MANAGEMENT_UTILITIES_H
#define PHYSTICS_GRAPHIC_ENGINE_PIXEL_MANAGEMENT_UTILITIES_H

/** for uint32_t */
#include <stdint.h>

/** for WindowID */
#include <graphics/types/window_id.h>

/** use RGBA8888 format - 24 and 32 bit deph colors = 4 bytes including align for RGBX888 color format */
#define BYTES_PER_PIXEL 4

extern uint32_t* global_framebuffer;

extern int32_t global_framebuffer_width;
extern int32_t global_framebuffer_pitch;
extern int32_t global_framebuffer_height;

extern WindowID global_framebuffer_current_wid;

/**
* Set current window to draw by its window id
*/
[[maybe_unused]] void set_current_window_by_wid( WindowID wid );


/**
* Draw a single pixel in the given coordinates
*/
[[maybe_unused]] void put_pixel( int32_t x_coord, int32_t y_coord, uint32_t color );


/**
* Clear current global framebuffer
*/
[[maybe_unused]] void clear_framebuffer( uint32_t clear_color );



#endif // PHYSTICS_PIXEL_MANAGEMENT_UTILITIES_H
