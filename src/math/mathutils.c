#include "mathutils.h"

float randFloat(float min, float max) {
    return ((max - min) * ((float)rand() / RAND_MAX)) + min;
}

int randInt(int min, int max) {
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

void clampF(float* val, float min, float max) {
    unimplemented();
}

void clampI(int* val, int min, int max) {
    unimplemented();
}
