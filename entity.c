#include "entity.h"

Entity global_count = 0;

Entity create_entity()
{
    return global_count++;
}
