#include "game.h"

Shader shader;
Shader texturedShader;

// TODO: Finish collision resolution
// TODO: Create static object batching,

Rect Enemy = {
    .position = { -2500.0f, 300.0f },
    .scale = { 2500.0f, 50.0f },
    .color = { RGBANORM(255.0f, 255.0f, 0.0f, 255.0f) },
    .isAABB = 1,
    .shader = &shader
};

Rect Floor = { 
    .position = { -2500.0f, 390.0f },
    .scale = { 2500.0f, 50.0f },
    .color = { RGBANORM(255.0f, 0.0f, 255.0f, 255.0f ) }, 
    .isAABB = 1,
    .shader = &shader
};

TexturedRect rect = {
    .position = { 0.0f, 0.0f },
    .scale = { 100.0f, 100.0f },
    .sprite = (Texture){ .filepath = "../assets/textures/awesomeface.jpg" },
};

Shader* shaders[] = {
    &shader,
    &texturedShader
};

void gameSetWindow(Game* game, struct Window* window) {
    game->window = window;
}

void gameStart(Game* game) {
    shaderInit(&shader, "../assets/shaders/square.vs", 
            "../assets/shaders/square.fs");
    shaderInit(&texturedShader, "../assets/shaders/texturedrect.vs", 
            "../assets/shaders/texturedrect.fs");
    playerInit(&game->player, &game->camera, &shader);
    
    texturedRectInit(&rect, &texturedShader);

    AllocRectArray(&game->entities, 0);
    PushToRectArray(&game->entities, &game->player.rect);
    PushToRectArray(&game->entities, &Enemy);
    PushToRectArray(&game->entities, &Floor);
}

iVec2f playerLastPos;

void gameResolveAllCollisions(Player* player, DRectArray entities) {
    for (int i = 0; i < entities.size; i++) {
        if (entities.array[i] == &player->rect) { continue; }

        if (AABBCollision(player->rect, *entities.array[i])) {


            iVec2f res = { player->rect.position.x - playerLastPos.x, 
                player->rect.position.y - playerLastPos.y };

            player->rect.position.x -= res.x;
        }

        if (AABBCollision(player->rect, *entities.array[i])) {
            iVec2f res = { player->rect.position.x - playerLastPos.x, 
                player->rect.position.y - playerLastPos.y };

            player->rect.position.y -= res.y;
        }   
    }
}

void gameUpdate(Game* game) {
    game->window->color = (NormColor){ 0.1f, 0.1f, 0.1f, 0.1f };

    playerUpdate(&game->player, deltaTime(game->time));

    // Do physics update here

    gameResolveAllCollisions(&game->player, game->entities);

    Rect r = { 
        .scale = { 50.0f, 50.0f }, 
        .color = RandomNormColor(),
        .isAABB = 1,
        .shader = &shader,
    };

    if (InputMouseButtonDown(0)) {
        iVec2f position;
        InputGetMousePos(&position.x, &position.y);
        r.position = position;
        rectInit(&r);
        PushToRectArray(&game->entities, &r);
    }

    playerLastPos = game->player.rect.position;

    cameraUpdate(&game->camera, shaders, 2);
	
    texturedRectRender(&rect);
}

void freeGameMemory(Game* game) {
    free(game->entities.array);
}
