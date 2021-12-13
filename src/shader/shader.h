#ifndef SHADER_H
#define SHADER_H

#pragma once

#include <string.h>

#include "../../libs/glew-2.2.0/include/GL/glew.h"

#define GLFW_INCLUDE_NONE
#include "../../libs/glfw-3.3.5/include/GLFW/glfw3.h"

#include "../../libs/cglm/include/cglm/cglm.h"
#include "../../libs/cglm/include/cglm/mat4.h"
#include "../../libs/cglm/include/cglm/vec3.h"
#include "../../libs/cglm/include/cglm/vec2.h"

struct Shader {
    unsigned int shaderID;
    
    unsigned int vertexShader;
    unsigned int fragmentShader;
    
    char* vertexShaderPath;
    char* fragmentShaderPath;
    
    int beingUsed;
};

void shaderInit(struct Shader* shader, char* vertexFilepath, char* fragmentFilepath);

void useShader(struct Shader* shader);
void detachShader(struct Shader* shader);

void sentInt2Shader(struct Shader shader, const char* varName, int val);
void sendFloat2Shader(struct Shader shader, const char* varName, float val);
void sendMat42Shader(struct Shader* shader, const char* varName, mat4 val);

#endif /* ifndef SHADER_H */
