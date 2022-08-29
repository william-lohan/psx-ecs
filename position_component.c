#include "entity.h"
#include "position_component.h"

int sparse_positions[256]; // todo max components
Entity dense_entities[MAX_ENTITIES];
PositionComponent dense_positions[MAX_ENTITIES];
int count_positions = 0;
void (*system)(PositionComponent*);

void add_position_to_entity(Entity entity, PositionComponent *component)
{
    sparse_positions[entity] = count_positions;
    dense_entities[count_positions] = entity;
    dense_positions[count_positions] = *component;
    count_positions++;
}

PositionComponent *get_position(Entity entity)
{
    // TODO check if exist
    // int dense_index = sparse_positions[entity];
    // if (dense_index)
    // {
    //     return &dense_positions[dense_index];
    // }
    return &dense_positions[sparse_positions[entity]];
}

Entity get_entity_from_position_index(unsigned int index)
{
    return dense_entities[index];
}

// todo remove component

void set_position_system(void *callback)
{
    system = callback;
}

void update_position_system()
{
    for(int i = 0; i < count_positions; i++)
    {
        PositionComponent* component = &dense_positions[i];
        (*system)(component);
    }
}
