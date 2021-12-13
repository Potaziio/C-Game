#ifndef GAME_H
#define GAME_H

#include "../../libs/glew-2.2.0/include/GL/glew.h"

#define GLFW_INCLUDE_NONE
#include "../../libs/glfw-3.3.5/include/GLFW/glfw3.h"

#include "../../libs/cglm/include/cglm/cglm.h"
#include "../../libs/cglm/include/cglm/mat4.h"
#include "../../libs/cglm/include/cglm/vec3.h"
#include "../../libs/cglm/include/cglm/vec2.h"

#include "../util/util.h"
#include "../math/vec.h"

#include "../shader/shader.h"
#include "../rect/rect.h"

#include "../input/input.h"

#include "../camera/camera.h"

static int win_width, win_height;

void gameUpdate(float deltaTime);
void gameStart();

#endif /* ifndef GAME_H */
