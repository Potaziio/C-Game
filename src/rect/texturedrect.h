#ifndef TEXTURED_RECT_H
#define TEXTURED_RECT_H

#include "../../libs/cglm/include/cglm/cglm.h"
#include "../../libs/cglm/include/cglm/mat4.h"
#include "../../libs/cglm/include/cglm/vec3.h"
#include "../../libs/cglm/include/cglm/vec2.h"

#include "../math/vec.h"
#include "../shader/shader.h"
#include "../texture/texture.h"
#include "../util/util.h"

typedef struct {
    iVec2f position, scale;
    Texture sprite;
	
    int wasInitialized;
	
    float vertices[20];
    unsigned int indices[6];
	
    unsigned int VAO, EBO, VBO;
	
    mat4 p_modelMatrix;
    Shader* shader;
} TexturedRect;

void genTexturedRectVertices(TexturedRect* rect);
void texturedRectInit(TexturedRect* rect, Shader* shader);
void texturedRectRender(TexturedRect* rect);

#endif // TEXTURED_RECT_H
