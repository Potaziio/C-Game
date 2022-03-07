#include "window.h"

// Just some glfw window boilerplate code

void frameBufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);

    struct Window* win = (struct Window*)glfwGetWindowUserPointer(window);
    win->width = width;
    win->height = height;
}

void CreateWindow(struct Window* window) {
    // GLFW INIT
    if (!glfwInit()) {
        fprintf(stderr, "ERROR::GLFW::INIT::FAILED");
        exit(-1);
    }

    // WINDOW FLAGS

    glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
    glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);

    window->window = glfwCreateWindow(window->width, window->height, window->name, NULL, NULL);

    if (!window) {
        glfwTerminate();
        fprintf(stderr, "ERROR::WINDOW::CREATION::FAILED");
        exit(-1);
    }

    glfwMakeContextCurrent(window->window);
    glfwSwapInterval(1);

    // GLEW INIT
    GLenum err;
    if ((err = glewInit()) != GLEW_OK) {
        fprintf(stderr, "ERROR::GLEW::INIT::FAILED -> %s\n", glewGetErrorString(err));
    }

    glfwSetWindowUserPointer(window->window, (void*)window);

    glfwSetFramebufferSizeCallback(window->window, frameBufferSizeCallback);
    glfwSetCursorPosCallback(window->window, InputMouseCursorCallback); 
    glfwSetScrollCallback(window->window, InputMouseScrollCallback);
    glfwSetMouseButtonCallback(window->window, InputMouseButtonCallback);
    glfwSetKeyCallback(window->window, InputKeyCallback);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Seed srand
    srand(time(NULL));

    window->color = (NormColor){ 0.0f, 0.0f, 0.0f, 1.0f };
}

void WindowLoop(struct Window* window) {
    Time time;

    window->game = (Game*)malloc(sizeof(Game));

    window->game->camera.x = 0.0f;
    window->game->camera.y = 0.0f;
    window->game->camera.boundsX = window->width;
    window->game->camera.boundsY = window->height;
    window->game->time = time;

    // Init game stuff
    
    AllocRectArray(&window->game->entities, 0);

    gameStart(window->game);

    for (int i = 0; i < window->game->entities.size; i++) {
        rectInit(window->game->entities.array[i]);
    }

    gameSetWindow(window->game, window);

    timeInit(&window->game->time);

    float t = 1.0f;

    while(!glfwWindowShouldClose(window->window)) {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(window->color.r, window->color.g, window->color.b, window->color.a);

        if (InputGetKeyDown(GLFW_KEY_ESCAPE)) {
            printf("Exiting..\n");
            break;
        }

        gameUpdate(window->game);

        // Rendering
        
        for (int i = 0; i < window->game->entities.size; i++) {
            rectRender(window->game->entities.array[i]);
        }


        /* Prints FPS */

        if (t <= 0.0f) {
            printf("FPS: %.1f\n", (0.001f / (deltaTime(window->game->time) / 1000.0f)));
            t = 1.0f;
        } else {
            t -= deltaTime(window->game->time);
        }

        window->game->camera.boundsX = window->width;
        window->game->camera.boundsY = window->height;

        glfwSwapBuffers(window->window);
        timeUpdate(&window->game->time);
        endKeyInputFrame();
        endMouseInputFrame();
    }
    freeGameMemory(window->game);

    glfwTerminate();
    glfwDestroyWindow(window->window);
}
