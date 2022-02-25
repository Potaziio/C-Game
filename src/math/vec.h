#ifndef VEC_H
#define VEC_H 

#include <stdio.h>
#include <math.h>

// Vector 2 floats

typedef struct {
    float x;
    float y;
} iVec2f;

iVec2f iVec2fMultV(iVec2f vec, iVec2f vec2);
iVec2f iVec2fMultF(iVec2f vec, float val);

float iVec2fDist(iVec2f vec1, iVec2f vec2);

iVec2f iVec2fSumV(iVec2f vec, iVec2f vec2);

void iVec2fNorm(iVec2f* vec);
void iVec2fIncV(iVec2f* vec, iVec2f vec2);

float iVec2fMag(iVec2f vec);

iVec2f iVec2fDiff(iVec2f vec, iVec2f target);

iVec2f iVec2fLerp(iVec2f source, iVec2f target, float speed);

// Vector 3 floats

typedef struct {
    float x;
    float y;
    float z;
} iVec3f;

void iVec3fNorm(iVec3f* vec);

// Vector 4 floats
typedef struct {
    float x;
    float y;
    float z;
    float w;
} iVec4f;

void iVec4fNorm(iVec4f* vec);

#endif /* ifndef VEC_H */
