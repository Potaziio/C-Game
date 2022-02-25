#include "vec.h"

// iVec2f

//TODO: Implement ivec2-ivec2 mult

iVec2f iVec2fMultF(iVec2f vec, float val) {
    iVec2f result = {
        .x = vec.x * val,
        .y = vec.y * val,
    };

    return result;
}

iVec2f iVec2fSumV(iVec2f vec, iVec2f vec2) {
    iVec2f result = {.x = vec.x + vec2.x, .y = vec.y + vec2.y,};
    return result;
}

iVec2f iVec2fMultV(iVec2f vec, iVec2f vec2) {
    iVec2f result = {
        .x = vec.x * vec2.x,
        .y = vec.y * vec2.y,
    };

    return result;
}

float iVec2fDist(iVec2f vec1, iVec2f vec2) {
    return sqrt((vec1.x - vec2.x) * (vec1.x - vec2.x) + 
            (vec1.y - vec2.y) * (vec1.y - vec2.y));
}

void iVec2fIncV(iVec2f* vec, iVec2f vec2) {
    vec->x += vec2.x;
    vec->y += vec2.y;
}

void iVec2fNorm(iVec2f* vec) {
    float mag = sqrt((vec->x * vec->x) + (vec->y * vec->y));

    if (mag > 0.0f) {
        vec->x /= mag;
        vec->y /= mag;
    } 
}

iVec2f iVec2fLerp(iVec2f source, iVec2f target, float speed) {
    iVec2f sourceSpeed = iVec2fMultF(source, 1.0f - speed);
    iVec2f targSpeed = iVec2fMultF(target, speed);

    return iVec2fSumV(sourceSpeed, targSpeed);
}

float iVec2fMag(iVec2f vec) {
    float mag = sqrt((vec.x * vec.x) + (vec.y * vec.y));
    return mag; 
}

iVec2f iVec2fDiff(iVec2f vec, iVec2f target) {
    iVec2f distance = {
        .x = vec.x - target.x,
        .y = vec.y - target.y,
    };

    return distance;
}


// iVec3f

void iVec3fNorm(iVec3f* vec) {
    float mag = sqrt((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));

    vec->x /= mag;
    vec->y /= mag;
    vec->z /= mag;
}



//iVec4f 

void iVec4fNorm(iVec4f* vec) {

}
