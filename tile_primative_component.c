#include <sys/types.h>
#include <psxgpu.h>
#include "entity.h"
#include "tile_primative_component.h"
#include "position_component.h"

int sparse_tile_primatives[256]; // todo max components
Entity dense_tile_primative_entities[MAX_ENTITIES];
TilePrimativeComponent dense_tile_primatives[MAX_ENTITIES];
int count_tile_primatives = 0;

void add_tile_primative_to_entity(Entity entity, TilePrimativeComponent *component)
{
    sparse_tile_primatives[entity] = count_tile_primatives;
    dense_tile_primative_entities[count_tile_primatives] = entity;
    dense_tile_primatives[count_tile_primatives] = *component;
    count_tile_primatives++;
}

TilePrimativeComponent *get_tile_primative(Entity entity)
{
    // TODO check if exist
    return &dense_tile_primatives[sparse_tile_primatives[entity]];
}

Entity get_entity_from_tile_primative_index(unsigned int index)
{
    return dense_tile_primative_entities[index];
}

// todo remove component

void draw_tile_primatives(u_long *ordering_table, char *nextpri)
{
    TILE *tile;

    for (int i = 0; i < count_tile_primatives; i++)
    {
        TilePrimativeComponent *component = &dense_tile_primatives[i];
        Entity entity = get_entity_from_tile_primative_index(i);
        PositionComponent *pos = get_position(entity);

        tile = (TILE *)nextpri;                                           // Cast next primitive
        setTile(tile);                                                    // Initialize the primitive (very important)
        setXY0(tile, pos->x, pos->y);                                     // Set primitive (x,y) position
        setWH(tile, component->width, component->height);                 // Set primitive size
        setRGB0(tile, component->red, component->green, component->blue); // Set color yellow
        addPrim(ordering_table, tile);                                    // Add primitive to the ordering table
        nextpri += sizeof(TILE);                                          // Advance the next primitive pointer
    }
}
