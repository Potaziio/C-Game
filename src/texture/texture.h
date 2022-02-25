#ifndef TEXTURE_H
#define TEXTURE_H

#include "../../libs/glew-2.2.0/include/GL/glew.h"
#define GLFW_INCLUDE_NONE
#include "../../libs/glfw-3.3.5/include/GLFW/glfw3.h"
#include "../../libs/stb_image/stb_image.h"

typedef struct {
    int width;
    int height;
    int channels;
    char* filepath;
    unsigned char* data;
    unsigned int textureID;
} Texture;

void loadTexture(Texture* texture);
void bindTexture(Texture texture);
void unbindTexture(Texture texture);

#endif // TEXTURE_H
