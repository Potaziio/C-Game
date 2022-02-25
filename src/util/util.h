#ifndef UTIL_H
#define UTIL_H 

#define RGBANORM(x, y, z, w) x / 255.0f, y / 255.0f, z / 255.0f, w / 255.0f

#define unimplemented() printf("This function '%s' is unimplemented...", __FUNCTION__); \
    exit(1)

typedef struct  {
    float r;
    float g;
    float b;
    float a;
} RGBA_Color;



#endif /* ifndef UTIL_H */
