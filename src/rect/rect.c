#include "rect.h"

void genRectVertices(Rect* rect) {
    float r = rect->color.r;
    float g = rect->color.g;
    float b = rect->color.b;
    float a = rect->color.a;

    rect->vertices[0] = 0.0f;
    rect->vertices[1] = 0.0f;
    rect->vertices[2] = 0.0f;
    rect->vertices[3] = r;
    rect->vertices[4] = g;
    rect->vertices[5] = b;
    rect->vertices[6] = a;

    rect->vertices[7] = 1.0f;
    rect->vertices[8] = 0.0f;
    rect->vertices[9] = 0.0f;
    rect->vertices[10] = r;
    rect->vertices[11] = g;
    rect->vertices[12] = b;
    rect->vertices[13] = a;

    rect->vertices[14] = 0.0f; 
    rect->vertices[15] = 1.0f;
    rect->vertices[16] = 0.0f;
    rect->vertices[17] = r;
    rect->vertices[18] = g;
    rect->vertices[19] = b;
    rect->vertices[20] = a;

    rect->vertices[21] = 1.0f; 
    rect->vertices[22] = 1.0f;
    rect->vertices[23] = 0.0f;
    rect->vertices[24] = r;
    rect->vertices[25] = g;
    rect->vertices[26] = b;
    rect->vertices[27] = a;

    rect->indices[0] = 0;
    rect->indices[1] = 2;
    rect->indices[2] = 1;

    rect->indices[3] = 3; 
    rect->indices[4] = 2;
    rect->indices[5] = 1;
}

void rectInit(Rect* rect) {
    rect->wasInitialized = 1;
    genRectVertices(rect);

    glGenVertexArrays(1, &rect->VAO);
    glGenBuffers(1, &rect->VBO);
    glGenBuffers(1, &rect->EBO);

    glBindVertexArray(rect->VAO);

    glBindBuffer(GL_ARRAY_BUFFER, rect->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(rect->vertices), rect->vertices, GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rect->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(rect->indices), rect->indices, GL_DYNAMIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

void rectRender(Rect* rect) {
    if (!rect->wasInitialized) {return;}

    vec3 transform;
    transform[0] = rect->position.x;
    transform[1] = rect->position.y;
    transform[2] = 0.0f;

    vec3 scale;
    scale[0] = rect->scale.x;
    scale[1] = rect->scale.y;
    scale[2] = 0.0f;

    glm_mat4_identity(rect->p_modelMatrix);
    glm_translate(rect->p_modelMatrix, transform);
    glm_scale(rect->p_modelMatrix, scale);

    sendMat42Shader(rect->shader, "model", rect->p_modelMatrix);

    useShader(rect->shader);
    glBindVertexArray(rect->VAO);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

    detachShader(rect->shader);
    glBindVertexArray(0);
}
