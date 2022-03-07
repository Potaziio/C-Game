#include "player.h"

void playerInit(Player* player, Camera* camera, Shader* shader) {
    player->rect = (Rect){
        .position = { 0.0f, 0.0f },
        .scale = { 40.0f, 40.0f },
        .color = { RGBANORM(255.0f, 0.0f, 255.0f, 255.0f) },
        .isAABB = 1,
        .shader = shader
    };

    rectInit(&player->rect);
    player->camera = camera;
}

void cameraFollow(Camera* camera, const Player player, float dt) {
    iVec2f cameraPos = { camera->x, camera->y };
    iVec2f cameraTarget = { (player.rect.position.x + 30.0f) - camera->boundsX * 0.5f, 
        (player.rect.position.y + 10.0f) - camera->boundsY * 0.5f};
    iVec2f lerpPos = iVec2fLerp(cameraPos, cameraTarget, 5.0f * dt);

    camera->x = lerpPos.x;
    camera->y = lerpPos.y;
}

/* float yAccel = 0.0f; */

void playerUpdate(Player* player, float dt) {
    /* printf("%i\n", player->state); */

    if (player->state == DEAD) return;

    iVec2f movement = { InputGetAxisRaw("Horizontal"), InputGetAxisRaw("Vertical") };
    iVec2fNorm(&movement);

    if (iVec2fMag(movement) > 0) {
        if (InputGetKeyHold(GLFW_KEY_LEFT_SHIFT)) 
            player->state = RUNNING;
        else
            player->state = MOVING;
    }

    iVec2fIncV(&player->rect.position, iVec2fMultF(iVec2fMultF(movement, 
                    dt), 500.0f));

    // Gravity code
        
    /* player->rect.position.y -= yAccel; */
    /* yAccel -= dt * 9.81 / 1.5; */

    cameraFollow(player->camera, *player, dt);
}
