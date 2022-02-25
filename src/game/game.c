#include "game.h"

Shader shader;
Shader texturedShader;

// TODO: Implement textures
// TODO: Create static object batching,

Rect Player = {
    .position = { 0.0f, 0.0f },
    .scale = { 20.0f, 20.0f },
    .color = { RGBANORM(255.0f, 255.0f, 255.0f, 255.0f) }
};

Rect Enemy = {
    .position = { -2500.0f, 300.0f },
    .scale = { 2500.0f, 25.0f },
    .color = { RGBANORM(255.0f, 0.0f, 0.0f, 255.0f)},
};

Shader* shaders[] = {
    &shader
};

void gameStart(Game* game) {
    shaderInit(&shader, "../assets/shaders/square.vs", 
            "../assets/shaders/square.fs");

    rectInit(&Player, &shader);
    rectInit(&Enemy, &shader);
}

bool AABBCollision(Rect a, Rect b) {
    return a.position.x + a.scale.x > b.position.x &&
        a.position.x < b.position.x + b.scale.x && 
        a.position.y + a.scale.y > b.position.y && 
        a.position.y < b.position.y + b.scale.y;
}

float yAccel = 0.0f;

void gameUpdate(Game* game) {
    glClearColor(0.1f, 0.1f, 0.1f, 255.0f);
    iVec2f movement = { InputGetAxisRaw("Horizontal"), 0.0f };
    iVec2fNorm(&movement);
	
    iVec2fIncV(&Player.position, iVec2fMultF(iVec2fMultF(movement, 
                    deltaTime(game->time)), 500.0f));

    if (AABBCollision(Player, Enemy)) {
        if (movement.x > 0.0f) {
            Player.position.x = Enemy.position.x - Player.scale.x;
        } else if (movement.x < 0.0f) {
            Player.position.x = Enemy.position.x + Enemy.scale.x;
        }
    }

    Player.position.y -= yAccel;
    yAccel -= deltaTime(game->time) * 9.81 / 1.5;

    if (AABBCollision(Player, Enemy)) {
        if (movement.y < 0.0f) {
            Player.position.y = Enemy.position.y + Enemy.scale.y; 
        } else if (movement.y > 0.0f) {
            Player.position.y = Enemy.position.y - Player.scale.y;
        }

        yAccel = 0.0f;
    }

    iVec2f cameraPos = { game->camera.x, game->camera.y };
    iVec2f cameraTarget = { (Player.position.x + 30.0f) - game->camera.boundsX * 0.5f, (Player.position.y + 10.0f) - game->camera.boundsY * 0.5f};
    iVec2f lerpPos = iVec2fLerp(cameraPos, cameraTarget, 5.0f * deltaTime(game->time));

    game->camera.x = lerpPos.x;
    game->camera.y = lerpPos.y;
	
    cameraUpdate(&game->camera, shaders, 1);
	
    rectRender(&Player);
    rectRender(&Enemy);
}

void freeGameMemory(Game* game) {
    free(game->entities.array);
}
