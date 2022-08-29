#ifndef _TILE_PRIMATIVE_COMPONENT_H
#define _TILE_PRIMATIVE_COMPONENT_H

#include "entity.h"

typedef struct _tile_primative_component
{
    short width, height;
    unsigned char red, blue, green;
} TilePrimativeComponent;

void add_tile_primative_to_entity(Entity entity, TilePrimativeComponent *component);

TilePrimativeComponent* get_tile_primative(Entity entity);

Entity get_entity_from_tile_primative_index(unsigned int index);

#endif // _TILE_PRIMATIVE_COMPONENT_H
