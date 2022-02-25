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

typedef struct {
    unsigned int shaderID;
    
    unsigned int vertexShader;
    unsigned int fragmentShader;
    
    char* vertexShaderPath;
    char* fragmentShaderPath;
    
   int beingUsed;
} Shader;

void shaderInit(Shader* shader, char* vertexFilepath, char* fragmentFilepath);

void useShader(Shader* shader);
void detachShader(Shader* shader);

void sentInt2Shader(Shader shader, const char* varName, int val);
void sendFloat2Shader(Shader shader, const char* varName, float val);
void sendMat42Shader(Shader* shader, const char* varName, mat4 val);

#endif /* ifndef SHADER_H */
