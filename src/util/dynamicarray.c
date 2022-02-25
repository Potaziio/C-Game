#include "dynamicarray.h"

void AllocRectArray(DRectArray* array, int size) {
    array->array = (Rect**)calloc(size, sizeof(Rect*));
    array->size = size;
}

void PushToRectArray(DRectArray* array, Rect* t) {
    Rect** temp = (Rect**)calloc(array->size, sizeof(Rect*));
    memcpy(temp, array->array, sizeof(Rect**) * array->size);
    free(array->array);
    array->array = (Rect**)calloc(array->size + 1, sizeof(Rect*));
    array->size++;
    memcpy(array->array, temp, sizeof(Rect*) * array->size);
    array->array[array->size - 1] = t;
    free(temp);
}

void PopFromRectArray(DRectArray* array, int index) {
    int elements_to_right = array->size - (index + 1);

    if (elements_to_right != 0) {
        int tmp = index;
        for (int i = 0; i < elements_to_right; i++) {
            printf("Popping with %i\n", elements_to_right);
            array->array[tmp] = array->array[tmp + 1];
            array->array[tmp + 1] = NULL;
            tmp++;
        }
    } else {
        for (int i = 0; i < 1; i++) {
            printf("Popping with 0\n");
            int tmp = index;
            array->array[tmp] = NULL;
            tmp++;
        }
    }

    Rect** temp = (Rect**)calloc(array->size, sizeof(Rect*));
    memcpy(temp, array->array, sizeof(Rect**) * array->size);
    free(array->array);
    array->array = (Rect**)calloc(array->size, sizeof(Rect*));
    memcpy(array->array, temp, sizeof(Rect**) * array->size);
    array->size--;
    free(temp);
}
