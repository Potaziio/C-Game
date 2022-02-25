#include "aabb.h"

int AABB(Rect rect1, Rect rect2) {
    return rect1.position.x < rect2.position.x + rect2.scale.x && 
        rect1.position.x + rect1.scale.x > rect2.position.x &&
        rect1.position.y < rect2.position.y + rect2.scale.y && 
        rect1.position.y + rect1.scale.y > rect2.position.y;
}
