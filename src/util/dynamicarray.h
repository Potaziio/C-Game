#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../rect/rect.h"

typedef struct {
    Rect** array;
    int size;
} DRectArray;

void AllocRectArray(DRectArray* array, int size);
void PushToRectArray(DRectArray* array, Rect* t);
void PopFromRectArray(DRectArray* array, int index);

#endif // DYNAMIC_ARRAY
