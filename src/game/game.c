#include "game.h"

// TODO: Mouse input and automatic shader loading and initialization functions

float playerSpeed = 200.0f;
float playerRunningSpeed = 300.0f;
float maxStamina = 100.0f;
float stamina = 100.0f;
float minStamina = 0.0f;

float staminaDecRate = 15.0f;
float staminaRegRate = 10.0f;

struct Shader shader;

struct Camera camera = {
    .x = 0.0f,
    .y = 0.0f,
};

struct Rect player;
struct iVec2f mousePos; 

void gameStart() {
    shaderInit(&shader, "../assets/shaders/square.vs", "../assets/shaders/square.fs");
    createRect(&player, &shader, 500.0f, 500.0f, 50.0f, 50.0f, 1.0f, 1.0f, 0.0f, 1.0f);
}

void gameUpdate(float deltaTime) {
    glClearColor(RGBADNORM(100.0f, 0.0f, 100.0f, 1.0f));

    struct iVec2f movement = { 
        .x = (InputGetAxisRaw("Horizontal")), 
        .y = (InputGetAxisRaw("Vertical")) };

    iVec2fNorm(&movement);

    if (InputGetKeyHold(GLFW_KEY_LEFT_SHIFT) && stamina > minStamina) {
        movement = iVec2fMultF(movement, playerRunningSpeed * deltaTime);
        if (stamina > minStamina)
            stamina -= deltaTime * staminaDecRate;
    } else {
        if (stamina < maxStamina)
            stamina += staminaRegRate * deltaTime;
        movement = iVec2fMultF(movement, playerSpeed * deltaTime);
    }

    InputGetMousePos(&mousePos.x, &mousePos.y);

    player.position = iVec2fLerp(player.position, mousePos, 10.0f * deltaTime);
    
    printf("%i, %i\n", win_width, win_height);

    /* iVec2fIncV(&player.position, iVec2fMultF(movement, playerSpeed * deltaTime)); */

    rectRender(&player);
    cameraUpdate(&camera, &shader);
}
