#ifndef TIME_H
#define TIME_H value

#define GLFW_INCLUDE_NONE
#include "../../libs/glfw-3.3.5/include/GLFW/glfw3.h"

typedef struct {
    float p_startTime;
    float p_lastTime;
    float dt;
} Time;

void timeInit(Time* time);
void timeUpdate(Time* time);

float deltaTime(Time time);
float getMilliSeconds();

#endif /* ifndef TIME_H */
