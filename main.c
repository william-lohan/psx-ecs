#include <stdio.h>
#include <sys/types.h>
#include <psxetc.h>
#include <psxgte.h>
#include <psxgpu.h>
#include "double_buffer.h"
#include "entity.h"
#include "position_component.h"
#include "tile_primative_component.h"

#define OT_LEN 8
#define SCREEN_XRES 320
#define SCREEN_YRES 240

Entity e1;
Entity e2;

void init();

void update(int *counter);

void display();

int main()
{
    int counter;

    // Init stuff
    init();

    // Main loop
    counter = 0;
    while (1)
    {
        update(&counter);

        // Update display
        display();

        // Increment the counter
        counter++;
    }

    return 0;
}

void updatePositions(PositionComponent *pos)
{
    pos->x = pos->x + 1;
}

void init()
{
    /* Reset the GPU, also installs a VSync event handler */
    ResetGraph(0);

    init_double_buffer();

    e1 = create_entity();
    PositionComponent comp = {5, 5};
    add_position_to_entity(e1, &comp);
    TilePrimativeComponent tile = {10, 10, 255, 255, 0 };
    add_tile_primative_to_entity(e1, &tile);
    e2 = create_entity();

    set_position_system(&updatePositions);

    // Load test font
    FntLoad(960, 0);

    // Open up a test font text stream of 100 characters
    FntOpen(0, 8, 320, 224, 0, 100);
}

void update(int *counter)
{
    /* Clear the OT of the next frame */
	ClearOTagR(double_buffer[active_buffer].ordering_table, OT_LEN);

    update_position_system();

    // pos system
    PositionComponent *myPos = get_position(&e1);

    // Print the obligatory hello world and counter to show that the
    // program isn't locking up to the last created text stream
    FntPrint(-1, "HELLO WORLD\n");
    FntPrint(-1, "COUNTER=%d\n", *counter);
    FntPrint(-1, "E1=%d\n", e1);                       // see that entity is an int
    FntPrint(-1, "E2=%d\n", e2);                       // see that entity is an int
    FntPrint(-1, "pos=%d , %d\n", myPos->x, myPos->y); // see that we can get component from entity, and that a system can update it

    // setWH

    // Draw

    // Draw the last created text stream
    FntFlush(-1);

    draw_tile_primatives(double_buffer[active_buffer].ordering_table, double_buffer[active_buffer].packet_buffer);

}

void display()
{
    DrawSync(0);
    VSync(0);
    put_buffers();
    // Enable display output, ResetGraph() disables it by default
    SetDispMask(1);
    DrawOTag(double_buffer[active_buffer].ordering_table + OT_LEN - 1);
    swap_buffers();
}
