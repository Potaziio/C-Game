#ifndef CAMERA_H
#define CAMERA_H 

#include "../../libs/cglm/include/cglm/cglm.h"
#include "../../libs/cglm/include/cglm/mat4.h"
#include "../../libs/cglm/include/cglm/vec3.h"
#include "../../libs/cglm/include/cglm/vec2.h"

#include "../shader/shader.h"

typedef struct {
    float x;
    float y;

    float boundsX;
    float boundsY;
    
    mat4 viewMatrix, projectionMatrix;
} Camera;

void cameraUpdate(Camera* camera, Shader** shader, int size);

#endif /* ifndef CAMERA_H */
