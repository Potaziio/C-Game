#include "input.h"

/* KEYBOARD HANDLING */

int InputGetKeyHold(int key) {
    return keyPressed[key];  
}

int InputGetKeyDown(int key) {
    return keyClicked[key];
}

int InputGetKeyUp(int key) {
    return keyReleased[key];
}

float InputGetAxisRaw(const char* axis) {
    if (strcmp(axis, "Horizontal") == 0) {
        if (InputGetKeyHold(GLFW_KEY_D))
            return 1.0f;
        if (InputGetKeyHold(GLFW_KEY_A))
            return -1.0f;
    } else if (strcmp(axis, "Vertical") == 0){ 
        if (InputGetKeyHold(GLFW_KEY_W))  
            return -1.0f;  
        if (InputGetKeyHold(GLFW_KEY_S))
            return 1.0f;
    } else {
        return -10.0f;
    }

    return 0.0f;
}

void InputKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        keyPressed[key] = 1;
        keyClicked[key] = 1;
    } else if (action == GLFW_RELEASE) {
        keyPressed[key] = 0;
        keyReleased[key] = 1;
    }
}

void endKeyInputFrame() {
    for (int i = 0; i < 350; ++i) {
        keyClicked[i] = 0;
        keyReleased[i] = 0;
    }
}

/* MOUSE HANDLING */

void InputMouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    if (action == GLFW_PRESS) {
        if (button < MOUSEBUTTONS) {
            mouseButtonPressed[button] = 1;
            mouseButtonClicked[button] = 1;
        }
    } else if (action == GLFW_RELEASE) {
        mouseButtonPressed[button] = 0;
        mouseButtonReleased[button] = 1;
        isMouseDragging = 0;
    } 
}

void InputMouseCursorCallback(GLFWwindow* window, double xpos, double ypos) {
   cursorX = (float)xpos;
   cursorY = (float)ypos;
}


void InputMouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset) {
    mWheelOffset = yOffset;
}

int InputGetMouseButtonHold(int button) {
    return mouseButtonPressed[button]; 
}

int InputGetMouseButtonDown(int button) {
    return mouseButtonClicked[button];
}

int InputGetMouseButtonUp(int button) {
    return mouseButtonReleased[button];
}

int InputIsMouseDragging() {
    return isMouseDragging;
}

void InputGetMousePos(float* x, float* y) {
    *x = cursorX;
    *y = cursorY;
}

void InputGetLastMousePos(float* x, float* y) {
    *x = lastCursorX;
    *y = lastCursorY;
}

void InputGetMouseScroll(float* y) {
    *y = mWheelOffset;
}

void endMouseInputFrame() {
    lastCursorX = cursorX;
    lastCursorY = cursorY;
    mWheelOffset = 0.0f;
    isMouseDragging = mouseButtonPressed[0] || mouseButtonPressed[1] || mouseButtonPressed[2];

    for (int i = 0; i < MOUSEBUTTONS; ++i) {
        mouseButtonReleased[i] = 0;
        mouseButtonClicked[i] = 0;
    }
}
