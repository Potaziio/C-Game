#include "vec.h"

// iVec2f

//TODO: Implement ivec2-ivec2 mult

struct iVec2f iVec2fMultF(struct iVec2f vec, float val) {
    struct iVec2f result = {
        .x = vec.x * val,
        .y = vec.y * val,
    };

    return result;
}

struct iVec2f iVec2fSumV(struct iVec2f vec, struct iVec2f vec2) {
    struct iVec2f result = {.x = vec.x + vec2.x, .y = vec.y + vec2.y,};
    return result;
}

struct iVec2f iVec2fMultV(struct iVec2f vec, struct iVec2f vec2) {
    struct iVec2f result = {
        .x = vec.x * vec2.x,
        .y = vec.y * vec2.y,
    };

    return result;
}

void iVec2fIncV(struct iVec2f* vec, struct iVec2f vec2) {
    vec->x += vec2.x;
    vec->y += vec2.y;
}

void iVec2fNorm(struct iVec2f* vec) {
    float mag = sqrt((vec->x * vec->x) + (vec->y * vec->y));

    if (mag > 0.0f) {
        vec->x /= mag;
        vec->y /= mag;
    } 
}

struct iVec2f iVec2fLerp(struct iVec2f source, struct iVec2f target, float speed) {
    struct iVec2f sourceSpeed = iVec2fMultF(source, 1.0f - speed);
    struct iVec2f targSpeed = iVec2fMultF(target, speed);

    return iVec2fSumV(sourceSpeed, targSpeed);
}

float iVec2fMag(struct iVec2f vec) {
    float mag = sqrt((vec.x * vec.x) + (vec.y * vec.y));
    return mag; 
}

struct iVec2f iVec2fDiff(struct iVec2f vec, struct iVec2f target) {
    struct iVec2f distance = {
        .x = vec.x - target.x,
        .y = vec.y - target.y,
    };

    return distance;
}


// iVec3f

void iVec3fNorm(struct iVec3f* vec) {
    float mag = sqrt((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));

    vec->x /= mag;
    vec->y /= mag;
    vec->z /= mag;
}



//iVec4f 

void iVec4fNorm(struct iVec4f* vec) {

}
