#ifndef _POSITION_COMPONENT_H
#define _POSITION_COMPONENT_H

// // #define add_position(entity, x, y) add_position_to_entity(entity, { x, y })

#include "entity.h"

typedef struct _position_component
{
    short y,x;
} PositionComponent;

void add_position_to_entity(Entity *entity, PositionComponent *component);

PositionComponent* get_position(Entity *entity);

#endif // _POSITION_COMPONENT_H
