#ifndef RECT_H
#define RECT_H value

#include "../../libs/cglm/include/cglm/cglm.h"
#include "../../libs/cglm/include/cglm/mat4.h"
#include "../../libs/cglm/include/cglm/vec3.h"
#include "../../libs/cglm/include/cglm/vec2.h"

#include "../math/vec.h"
#include "../shader/shader.h"

struct Rect {
    struct iVec2f position, scale;
    struct iVec4f color;

    int wasInitialized;

    float vertices[28];
    unsigned int indices[6];

    unsigned int VAO, EBO, VBO;

    mat4 p_modelMatrix;
    struct Shader* shader;
};

void genRectVertices(struct Rect* rect);
void rectInit(struct Rect* rect, struct Shader* shader);
void rectRender(struct Rect* rect);
void createRect(struct Rect* rect, struct Shader* shader, float x, float y, float w, float h, float r, float g, float b, float a);

#endif /* ifndef RECT_H */
