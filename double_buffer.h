#ifndef _DOUBLE_BUFFER_H
#define _DOUBLE_BUFFER_H

#include <sys/types.h>
#include <psxgpu.h>

#ifndef OT_LEN
#define OT_LEN 1024
#endif

#ifndef PACKET_LEN
#define PACKET_LEN 32768
#endif

#ifndef SCREEN_XRES
#define SCREEN_XRES 320
#endif

#ifndef SCREEN_YRES
#define SCREEN_YRES 240
#endif

/* Double buffer structure */
typedef struct
{
    DISPENV display_environment;    // Display environment
    DRAWENV draw_environment;       // Drawing environment
    u_long ordering_table[OT_LEN];  // Ordering table
    char packet_buffer[PACKET_LEN]; // Packet buffer
} DoubleBuffer;

/* Double buffer variables */
static DoubleBuffer double_buffer[2];
static int active_buffer = 0;
static char *packet_address; /* Next packet pointer for primitive generation */

void init_double_buffer();

void swap_buffers();

void put_buffers();

#endif // _DOUBLE_BUFFER_H
