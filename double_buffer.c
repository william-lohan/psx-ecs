#include <sys/types.h>
#include <psxgpu.h>
#include "double_buffer.h"

void init_double_buffer()
{
	/* Set display and draw environment areas */
	SetDefDispEnv(&double_buffer[0].display_environment, 0, 0, SCREEN_XRES, SCREEN_YRES);
	SetDefDrawEnv(&double_buffer[0].draw_environment, SCREEN_XRES, 0, SCREEN_XRES, SCREEN_YRES);

	// Enable draw area clear and dither processing
	setRGB0(&double_buffer[0].draw_environment, 63, 0, 127);
	double_buffer[0].draw_environment.isbg = 1;
	// double_buffer[0].draw_environment.dtd = 1;

	// Define the second set of display/draw environments
	SetDefDispEnv(&double_buffer[1].display_environment, SCREEN_XRES, 0, SCREEN_XRES, SCREEN_YRES);
	SetDefDrawEnv(&double_buffer[1].draw_environment, 0, 0, SCREEN_XRES, SCREEN_YRES);

	setRGB0(&double_buffer[1].draw_environment, 63, 0, 127);
	double_buffer[1].draw_environment.isbg = 1;
	// double_buffer[1].draw_environment.dtd = 1;

	// Apply the drawing environment of the first double buffer
	PutDrawEnv(&double_buffer[0].draw_environment);
	PutDispEnv(&double_buffer[0].display_environment);

	// Clear both ordering tables to make sure they are clean at the start
	ClearOTagR(double_buffer[0].ordering_table, OT_LEN);
	ClearOTagR(double_buffer[1].ordering_table, OT_LEN);

	// Set primitive pointer address
	packet_address = double_buffer[0].packet_buffer;
}

void swap_buffers2()
{
	/* Apply display/drawing environments */
	PutDrawEnv(&double_buffer[active_buffer].draw_environment);
	PutDispEnv(&double_buffer[active_buffer].display_environment);
	
	/* Swap buffers */
	active_buffer ^= 1;
	packet_address = double_buffer[active_buffer].packet_buffer;

}

void swap_buffers()
{
	/* Swap buffers */
	active_buffer ^= 1;
	packet_address = double_buffer[active_buffer].packet_buffer;
}

void put_buffers()
{
	/* Apply display/drawing environments */
	PutDrawEnv(&double_buffer[active_buffer].draw_environment);
	PutDispEnv(&double_buffer[active_buffer].display_environment);
}
