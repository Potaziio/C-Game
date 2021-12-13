#include "window.h"

// Just some glfw window boilerplate code

void frameBufferSizeCallback(GLFWwindow* window, int width, int height) {
    win_width = width;
    win_height = height;
    glViewport(0, 0, width, height);
}

void CreateWindow(struct Window* window) {
    // GLFW INIT
    if (!glfwInit()) {
        fprintf(stderr, "ERROR::GLFW::INIT::FAILED");
        exit(-1);
    }

    // WINDOW FLAGS
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
    glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);

    window->window = glfwCreateWindow(window->width, window->height, window->name, NULL, NULL);

    win_width = window->width;
    win_height = window->height;

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

    /* glfwSetFramebufferSizeCallback(window->window, frameBufferSizeCallback); */
    glfwSetCursorPosCallback(window->window, InputMouseCursorCallback); 
    glfwSetScrollCallback(window->window, InputMouseScrollCallback);
    glfwSetMouseButtonCallback(window->window, InputMouseButtonCallback);
    glfwSetKeyCallback(window->window, InputKeyCallback);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void WindowLoop(struct Window* window) {

    gameStart();

    struct Time time;

    timeInit(&time); 

    while(!glfwWindowShouldClose(window->window)) {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if (InputGetKeyDown(GLFW_KEY_ESCAPE)) {
            printf("Exiting..\n");
            break;
        }

        gameUpdate(deltaTime(&time));

        glfwSwapBuffers(window->window);
        timeUpdate(&time);
        endKeyInputFrame();
        endMouseInputFrame();
    }

    glfwTerminate();
    glfwDestroyWindow(window->window);
}
