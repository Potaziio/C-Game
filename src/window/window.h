#ifndef WINDOW_H
#define WINDOW_H

#include <stdio.h>
#include <stdlib.h>

#include "../math/vec.h"
#include "../util/util.h"

#include "../time/time.h"
#include "../input/input.h"
#include "../util/color.h"

#include "../game/game.h"

#include "../../libs/glew-2.2.0/include/GL/glew.h"
#include "../../libs/glfw-3.3.5/include/GLFW/glfw3.h"

typedef struct Game Game;

struct Window {
    GLFWwindow* window;
    int width;
    int height;
    const char* name;
    Game* game;
    NormColor color;
};

void CreateWindow(struct Window* window);
void WindowLoop(struct Window* window);
void frameBufferSizeCallback(GLFWwindow* window, 
        int width, int height);

#endif /* ifndef WINDOW_H */
