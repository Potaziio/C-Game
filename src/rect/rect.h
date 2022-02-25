#ifndef RECT_H
#define RECT_H value

#include "../../libs/cglm/include/cglm/cglm.h"
#include "../../libs/cglm/include/cglm/mat4.h"
#include "../../libs/cglm/include/cglm/vec3.h"
#include "../../libs/cglm/include/cglm/vec2.h"

#include "../math/vec.h"
#include "../shader/shader.h"
#include "../util/util.h"

typedef struct {
    iVec2f position, scale;
    RGBA_Color color;

    int wasInitialized;

    float vertices[28];
    unsigned int indices[6];

    unsigned int VAO, EBO, VBO;

    mat4 p_modelMatrix;
    Shader* shader;
} Rect;

void genRectVertices(Rect* rect);
void rectInit(Rect* rect, Shader* shader);
void rectRender(Rect* rect);
void createRect(Rect* rect, Shader* shader, float x, float y, float w, float h, float r, float g, float b, float a);

#endif /* ifndef RECT_H */
