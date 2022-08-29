#include "tile_primative_component.h"

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

TilePrimativeComponent* get_tile_primative(Entity entity)
{
    // TODO check if exist
    return &dense_tile_primatives[sparse_tile_primatives[entity]];
}

Entity get_entity_from_tile_primative_index(unsigned int index)
{
    return dense_tile_primative_entities[index];
}

// todo remove component
