#ifndef GAME_H
#define GAME_H

#include "../util/util.h"
#include "../math/vec.h"
#include "../shader/shader.h"
#include "../rect/rect.h"
#include "../rect/texturedrect.h"
#include "../rect/aabb.h"
#include "../input/input.h"
#include "../math/mathutils.h"
#include "../time/time.h"
#include "../camera/camera.h"
#include "../util/dynamicarray.h"
#include "../texture/texture.h"
#include "../util/color.h"
#include "entities/player/player.h"
#include "../window/window.h"

#include "../../libs/glew-2.2.0/include/GL/glew.h"
#define GLFW_INCLUDE_NONE
#include "../../libs/glfw-3.3.5/include/GLFW/glfw3.h"

#include "../../libs/cglm/include/cglm/cglm.h"
#include "../../libs/cglm/include/cglm/mat4.h"
#include "../../libs/cglm/include/cglm/vec3.h"
#include "../../libs/cglm/include/cglm/vec2.h"

struct Window; 

typedef struct Game {
    struct Window* window;
    Player player;
    Camera camera;
    Time time;
    DRectArray entities;
} Game;

void gameResolveAllCollisions(Player* player, DRectArray entities);
void gameSetWindow(Game* game, struct Window* window);
void gameUpdate(Game* game);
void gameStart(Game* game);
void freeGameMemory(Game* game);

#endif /* ifndef GAME_H */
