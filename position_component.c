// #include "entity.h"
#include "position_component.h"

int sparse_positions[256];
PositionComponent dense_positions[64];
int count_positions = 0;

void add_position_to_entity(Entity *entity, PositionComponent *component)
{
    sparse_positions[*entity] = count_positions;
    dense_positions[count_positions] = *component;
    count_positions++;
}

PositionComponent* get_position(Entity *entity)
{
    return &dense_positions[sparse_positions[*entity]];
}
