#include <stdio.h>
#include <sys/types.h>
#include <psxetc.h>
#include <psxgte.h>
#include <psxgpu.h>
#include "double_buffer.h"
#include "entity.h"
#include "position_component.h"

// #define OT_LEN 8
// #define SCREEN_XRES 320
// #define SCREEN_YRES 240

Entity e1;
Entity e2;

void init();

void update(char *counter);

void display();

int main()
{
    char counter;

	// Init stuff	
	init();
	
	// Main loop
	counter = 0;
	while(1)
	{
        update(&counter);
		
		// Update display
		display();
		
		// Increment the counter
		counter++;
	}
	
	return 0;
}

void init()
{
    /* Reset the GPU, also installs a VSync event handler */
    ResetGraph(0);

    init_double_buffer();

    e1 = create_entity();
    PositionComponent comp = { 5, 5 };
    add_position_to_entity(&e1, &comp);
    e2 = create_entity();

    // Load test font
    FntLoad(960, 0);

    // Open up a test font text stream of 100 characters
    FntOpen(0, 8, 320, 224, 0, 100);
}

void update(char *counter)
{

    // pos system
    PositionComponent* myPos = get_position(&e1);

    // Print the obligatory hello world and counter to show that the
    // program isn't locking up to the last created text stream
    FntPrint(-1, "HELLO WORLD\n");
    FntPrint(-1, "COUNTER=%d\n", *counter);
    FntPrint(-1, "E1=%d\n", e1);
    FntPrint(-1, "E2=%d\n", e2);
    FntPrint(-1, "pos=%d , %d\n", myPos->x, myPos->y);

    // setWH

    // Draw the last created text stream
    FntFlush(-1);
}

void display()
{
    DrawSync(0);
    VSync(0);
    swap_buffers();

    // Enable display output, ResetGraph() disables it by default
	SetDispMask(1);
}
