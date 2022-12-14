#ifndef _TILE_PRIMATIVE_COMPONENT_H
#define _TILE_PRIMATIVE_COMPONENT_H

#include <sys/types.h>
#include "entity.h"
#include "color.h"

typedef struct _tile_primative_component
{
    short width, height;
    Color color;
} TilePrimativeComponent;

void add_tile_primative_to_entity(Entity entity, TilePrimativeComponent *component);

TilePrimativeComponent *get_tile_primative(Entity entity);

Entity get_entity_from_tile_primative_index(unsigned int index);

void draw_tile_primatives(u_long *ordering_table, char *nextpri);

#endif // _TILE_PRIMATIVE_COMPONENT_H
