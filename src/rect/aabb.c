#include "aabb.h"

int AABBCollision(const Rect rect1, const Rect rect2) {
    if (!rect1.isAABB || !rect2.isAABB) return 0;

    return rect1.position.x < rect2.position.x + rect2.scale.x && 
        rect1.position.x + rect1.scale.x > rect2.position.x &&
        rect1.position.y < rect2.position.y + rect2.scale.y && 
        rect1.position.y + rect1.scale.y > rect2.position.y;
}
