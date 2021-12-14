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
#include "../rect/aabb.h"

#include "../input/input.h"
#include "../math/mathutils.h"

#include "../camera/camera.h"

#define MAX_ENTITIES 100

static int entitiesInGame = 0;

static struct Rect** entities;

void addEntity(struct Rect* entity, struct Shader* shader, float x, float y, float scaleX, float scaleY, float r, float g, float b, float a);
void removeEntity(struct Rect* entity);

void renderRects();

void gameUpdate(float deltaTime);
void gameStart();
void freeGameMemory();

#endif /* ifndef GAME_H */
