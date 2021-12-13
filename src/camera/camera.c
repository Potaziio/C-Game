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

void cameraUpdate(struct Camera* camera, struct Shader* shader) {
    cameraPos[0] = camera->x;
    cameraPos[1] = camera->y;

    glm_mat4_identity(camera->projectionMatrix);
    glm_ortho(0.0f, 1600.0f, 1000.0f, 0.0f, 0.0f, 100.0f, camera->projectionMatrix);

    vec3 dest;

    glm_mat4_identity(camera->viewMatrix);
    glm_vec3_add(cameraPos, cameraFront, dest);
    glm_lookat(cameraPos, dest, cameraUp, camera->viewMatrix);

    sendMat42Shader(shader, "view", camera->viewMatrix);
    sendMat42Shader(shader, "projection", camera->projectionMatrix);
}
