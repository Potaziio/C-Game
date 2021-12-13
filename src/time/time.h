#ifndef TIME_H
#define TIME_H value

#define GLFW_INCLUDE_NONE
#include "../../libs/glfw-3.3.5/include/GLFW/glfw3.h"

struct Time {
    float p_startTime;
    float p_lastTime;
    float dt;
};

void timeInit(struct Time* time);
void timeUpdate(struct Time* time);

float deltaTime(struct Time* time);
float getMilliSeconds();

#endif /* ifndef TIME_H */
