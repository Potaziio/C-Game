#include "time.h"

void timeInit(struct Time* time) {
    time->p_startTime = (float)glfwGetTime();
}

void timeUpdate(struct Time* time) {
    time->p_lastTime = (float)glfwGetTime();
    time->dt = time->p_lastTime - time->p_startTime;
    time->p_startTime = (float)glfwGetTime();
}

float deltaTime(struct Time* time) {
    return time->dt;
}

float getMilliSeconds() {
    return (float)glfwGetTime();
}

