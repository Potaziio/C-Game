#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <string.h>

#define GLFW_INCLUDE_NONE
#include "../../libs/glfw-3.3.5/include/GLFW/glfw3.h"

#define MOUSEBUTTONS (int)sizeof mouseButtonPressed / (int)sizeof mouseButtonPressed[0]

#define KEYBOARDKEYS (int)sizeof keyPressed / (int)sizeof keyPressed[0]

// KEYBOARD HANDLING

static int keyPressed[350];
static int keyClicked[350];
static int keyReleased[350];

/* Returns true as long as key is being held */
int InputGetKeyHold(int key);

/* Returns true only once upon key press */
int InputGetKeyDown(int key);

/* Returns true only one upon key release */
int InputGetKeyUp(int key);

float InputGetAxisRaw(const char* axis);

void InputKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void endKeyInputFrame(); 


/* MOUSE INPUT HANDLING */

static int mouseButtonPressed[4];
static int mouseButtonClicked[4];
static int mouseButtonReleased[4];

static int isMouseDragging;

static float cursorX;
static float cursorY;

static float lastCursorX;
static float lastCursorY;

static float mWheelOffset;

/* returns 1 while a mouse button is pressed */
int InputMouseButtonHold(int button);

/* returns 1 only once upon a mouse click */
int InputMouseButtonDown(int button);

/* returns 1 only once upon a mouse button is released */
int InputMouseButtonUp(int button);

/* sets given x and y to the mousepos */
void InputGetMousePos(float* x, float* y);

/* returns 1 if a mouse button is pressed while the mouse is moving */
int InputIsMouseDragging();

/* sets given x and y to the last mousepos */
void InputGetLastMousePos(float* x, float* y);

void InputGetMouseScroll(float* y);

void InputMouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
void InputMouseCursorCallback(GLFWwindow* window, double xpos, double ypos);
void InputMouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset);

void endMouseInputFrame();

#endif /* ifndef INPUT_H */
