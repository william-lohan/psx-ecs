#ifndef _POSITION_COMPONENT_H
#define _POSITION_COMPONENT_H

// // #define add_position(entity, x, y) add_position_to_entity(entity, { x, y })

#include "entity.h"

typedef struct _position_component
{
    short y,x;
} PositionComponent;

void add_position_to_entity(Entity entity, PositionComponent *component);

PositionComponent* get_position(Entity entity);

Entity get_entity_from_position_index(unsigned int index);

void set_position_system(void *callback);

void update_position_system();

#endif // _POSITION_COMPONENT_H
