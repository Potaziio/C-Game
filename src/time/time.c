#include "time.h"

void timeInit(Time* time) {
    time->p_startTime = (float)glfwGetTime();
}

void timeUpdate(Time* time) {
    time->p_lastTime = (float)glfwGetTime();
    time->dt = time->p_lastTime - time->p_startTime;
    time->p_startTime = (float)glfwGetTime();
}

float deltaTime(Time time) {
    return time.dt;
}

float getMilliSeconds() {
    return (float)glfwGetTime();
}

