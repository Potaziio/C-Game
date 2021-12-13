#ifndef CAMERA_H
#define CAMERA_H 

#include "../../libs/cglm/include/cglm/cglm.h"
#include "../../libs/cglm/include/cglm/mat4.h"
#include "../../libs/cglm/include/cglm/vec3.h"
#include "../../libs/cglm/include/cglm/vec2.h"

#include "../shader/shader.h"

struct Camera {
    float x;
    float y;
    
    mat4 viewMatrix, projectionMatrix;
};

void cameraUpdate(struct Camera* camera, struct Shader* shader);

#endif /* ifndef CAMERA_H */
