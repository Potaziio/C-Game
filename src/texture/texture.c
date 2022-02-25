#include "texture.h"

void loadTexture(Texture* texture) {
    stbi_set_flip_vertically_on_load(1);
    texture->data = stbi_load(texture->filepath, &texture->width, &texture->height, &texture->channels, 0);

    if (!texture->data) {
        fprintf(stderr, "ERROR:TEXTURE::FAILED_TO_LOAD_TEXTURE\n");
        exit(EXIT_FAILURE);
    }
    else {
        // Generate and bind texture

        glGenTextures(1, &texture->textureID);
        glBindTexture(GL_TEXTURE_2D, texture->textureID);

        // Set texture parameters of currently bound texture
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        if (texture->channels == 3) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture->width, texture->height, 0, GL_RGB, GL_UNSIGNED_BYTE, texture->data); 
            glGenerateMipmap(GL_TEXTURE_2D);
        } else if (texture->channels == 4) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texture->width, texture->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture->data); 
            glGenerateMipmap(GL_TEXTURE_2D);
        } else {
            fprintf(stderr, "ERROR::TEXTURE::UKNOWN_FILE_FORMAT::%i::CHANNELS \n");
            exit(EXIT_FAILURE);
        }

        glBindTexture(GL_TEXTURE_2D, 0);
    }

    stbi_image_free(texture->data);
}

void bindTexture(Texture texture) {
    glBindTexture(GL_TEXTURE_2D, texture.textureID);
}

void unbindTexture(Texture texture) {
    glBindTexture(GL_TEXTURE_2D, 0);
}
