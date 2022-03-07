#ifndef RECT_H
#define RECT_H value

#include "../../libs/cglm/include/cglm/cglm.h"
#include "../../libs/cglm/include/cglm/mat4.h"
#include "../../libs/cglm/include/cglm/vec3.h"
#include "../../libs/cglm/include/cglm/vec2.h"

#include "../math/vec.h"
#include "../shader/shader.h"
#include "../util/color.h"

typedef struct {
    iVec2f position, scale;
    NormColor color;

    int wasInitialized;
    int isAABB;

    float vertices[28];
    unsigned int indices[6];

    unsigned int VAO, EBO, VBO;

    mat4 p_modelMatrix;
    Shader* shader;
} Rect;

void genRectVertices(Rect* rect);
void rectInit(Rect* rect);
void rectRender(Rect* rect);

#endif /* ifndef RECT_H */
