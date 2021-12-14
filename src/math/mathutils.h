#ifndef MATHUTILS_H
#define MATHUTILS_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../util/util.h"

float randFloat(float min, float max);
int randInt(int min, int max);

void clampF(float* val, float min, float max);
void clampI(int* val, int min, int max);

#endif /* ifndef MATHUTILS_H */
