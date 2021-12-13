#ifndef VEC_H
#define VEC_H 

#include <stdio.h>
#include <math.h>


// Vector 2 floats

struct iVec2f {
    float x;
    float y;
};

struct iVec2f iVec2fMultV(struct iVec2f vec, struct iVec2f vec2);
struct iVec2f iVec2fMultF(struct iVec2f vec, float val);

struct iVec2f iVec2fSumV(struct iVec2f vec, struct iVec2f vec2);

void iVec2fNorm(struct iVec2f* vec);
void iVec2fIncV(struct iVec2f* vec, struct iVec2f vec2);

float iVec2fMag(struct iVec2f vec);

struct iVec2f iVec2fDiff(struct iVec2f vec, struct iVec2f target);

struct iVec2f iVec2fLerp(struct iVec2f source, struct iVec2f target, float speed);

// Vector 3 floats

struct iVec3f {
    float x;
    float y;
    float z;
};

void iVec3fNorm(struct iVec3f* vec);


// Vector 4 floats
struct iVec4f {
    float x;
    float y;
    float z;
    float w;
};

void iVec4fNorm(struct iVec4f* vec);

#endif /* ifndef VEC_H */
