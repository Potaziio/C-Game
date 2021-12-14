#include "game.h"

// TODO: Learn more about c arrays and create a dynamic gameObject array to add and remove rects from the screen  
// TODO: automatic shader loading and initialization functions

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 1000

#define MAX_SNAKE_SIZE 100

#define SNAKE_HEAD 0

int currentSnakeSize = 0;

struct Shader shader;

struct Camera camera = {
    .x = 0.0f,
    .y = 0.0f,
};

struct Rect* snake;

struct Rect food;

void addEntity(struct Rect* entity, struct Shader* shader, float x, float y, float scaleX, float scaleY, float r, float g, float b, float a) {
    createRect(entity, shader, x, y, scaleX, scaleY, r, g, b, a); 
    entities[entitiesInGame] = entity;
    entitiesInGame++;
}

void removeEntity(struct Rect* entity) {
    if (entity == NULL)  { return; }

    for (int i = 0; i < entitiesInGame; ++i) {
        if (entities[i] == entity) {

            // Replace this entity by the next in order if there is any.
            // This also moves down any following entities.
            
            if (entities[i + 1] != NULL) {
                entities[i] = entities[i + 1];
                entities[i + 1] = 0;

                for (int j = i + 1; j < entitiesInGame; ++j) {
                    if (entities[j + 1] != NULL) {
                        entities[j] = entities[j + 1];
                        entities[j + 1] = 0;
                    }
                }
            } else {
                entities[i] = 0;
            }

            entitiesInGame--;
        }
    }
}

void renderRects() {
    for (int i = 0; i < entitiesInGame; ++i) {
       rectRender(entities[i]); 
    }
}

void gameStart() {
    shaderInit(&shader, "../assets/shaders/square.vs", "../assets/shaders/square.fs");
    entities = (struct Rect**)calloc(MAX_ENTITIES, sizeof(struct Rect*));
    snake = (struct Rect*)calloc(MAX_SNAKE_SIZE, sizeof(struct Rect));

    addEntity(&food, &shader, 
            randFloat(0.0f, SCREEN_WIDTH), randFloat(0.0f, SCREEN_HEIGHT), 
            20.0f, 20.0f, 
            RGBANORM(255.0f, 0.0f, 0.0f, 155.0f));

    addEntity(&snake[SNAKE_HEAD], &shader, 0.0f, 100.0f, 
            30.0f, 30.0f, 
            RGBANORM(0.0f, 0.0f, 255.0f, 255.0f));
}

int lastMoveX = 1;
int lastMoveY;

int snakeSpeed = 150;

float currentMoveTime = 0.0f;
float moveTimer = 0.07f;

int snakeDead = 0;

void gameUpdate(float deltaTime) {
    glClearColor(RGBANORM(0.0, 0.0f, 0.0f, 255.0f));

    // Horizontal Movement

    if (InputGetKeyDown(GLFW_KEY_RIGHT) && lastMoveX != -1) {
        lastMoveX = 1;
        lastMoveY = 0;
    } else if(InputGetKeyDown(GLFW_KEY_LEFT) && lastMoveX != 1) {
        lastMoveX = -1;
        lastMoveY = 0;
    }

    // Vertical Movement

    if (InputGetKeyDown(GLFW_KEY_UP) && lastMoveY != 1) {
        lastMoveY = -1;
        lastMoveX = 0;
    } else if(InputGetKeyDown(GLFW_KEY_DOWN) && lastMoveY != -1) {
        lastMoveY = 1;
        lastMoveX = 0;
    }

    struct iVec2f movement = {
        .x = lastMoveX * 30.0f,
        .y = lastMoveY * 30.0f,
    };

    // Player Movement Update

    if (currentMoveTime > 0.0f) {
        currentMoveTime -= deltaTime;
    } 

    if (!snakeDead) {

        if (currentMoveTime <= 0.0f) {
            currentMoveTime = moveTimer;

            if (AABB(snake[SNAKE_HEAD], food)) {
                struct iVec2f newFoodPos = {
                    .x = randFloat(0.0f, SCREEN_WIDTH - 50),
                    .y = randFloat(0.0f, SCREEN_HEIGHT - 50),
                };

                food.position = newFoodPos;

                currentSnakeSize++;

                addEntity(&snake[currentSnakeSize], &shader,
                        snake[currentSnakeSize - 1].position.x, snake[currentSnakeSize - 1].position.y, 
                        snake[SNAKE_HEAD].scale.x, snake[SNAKE_HEAD].scale.y, 
                        RGBANORM(255.0f, 255.0f, 255.0f, 255.0f));
            }

            for (int i = currentSnakeSize; i > 0; --i) {
                snake[i].position = snake[i - 1].position; 
            }

            iVec2fIncV(&snake[SNAKE_HEAD].position, movement);

            // Checking wall and body collision

            for (int i = 1; i < currentSnakeSize + 1; ++i) {
                if (AABB(snake[SNAKE_HEAD], snake[i])) {
                    snakeDead = 1; 
                }
            }

            if (snake[SNAKE_HEAD].position.x < -20.0f || 
                    snake[SNAKE_HEAD].position.x > 1620.0f ||
                    snake[SNAKE_HEAD].position.y > 1020.0f ||
                    snake[SNAKE_HEAD].position.y < -20.0f) {

                snakeDead = 1;
            }
        }
    }

    cameraUpdate(&camera, &shader);
    renderRects();
}

void freeGameMemory() {
    free(entities);
    free(snake);
}
