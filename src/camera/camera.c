#include "camera.h"

vec3 cameraPos = {
    0.0f, 0.0f, 0.0f
};

vec3 cameraFront = {
    0.0f, 0.0f, -1.0f
};

vec3 cameraUp = {
    0.0f, 1.0f, 0.0f
};

void cameraUpdate(Camera* camera, Shader** shader, int size) {
    cameraPos[0] = camera->x;
    cameraPos[1] = camera->y;

    glm_mat4_identity(camera->projectionMatrix);
    glm_ortho(0.0f, camera->boundsX, camera->boundsY, 0.0f, 0.0f, 100.0f, camera->projectionMatrix);

    vec3 dest;

    glm_mat4_identity(camera->viewMatrix);
    glm_vec3_add(cameraPos, cameraFront, dest);
    glm_lookat(cameraPos, dest, cameraUp, camera->viewMatrix);

    for (int i = 0; i < size; i ++) {
        sendMat42Shader(shader[i], "view", camera->viewMatrix);
        sendMat42Shader(shader[i], "projection", camera->projectionMatrix);
    }
}
