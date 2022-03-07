#ifndef COLOR_H
#define COLOR_H

#include "../math/mathutils.h"
#include "util.h"

typedef struct color {
    float r;
    float g;
    float b;
    float a;
} Color;


typedef struct normalized_color {
    float r;
    float g;
    float b;
    float a;
} NormColor;


NormColor ColorToNorm(Color color);
Color NormColorToColor(NormColor color);
Color RandomColor();
NormColor RandomNormColor();

#endif //COLOR_H
