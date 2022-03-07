#ifndef PLAYER_H
#define PLAYER_H

#include "../../../util/util.h"
#include "../../../math/vec.h"
#include "../../../shader/shader.h"
#include "../../../rect/rect.h"
#include "../../../rect/texturedrect.h"
#include "../../../rect/aabb.h"
#include "../../../input/input.h"
#include "../../../math/mathutils.h"
#include "../../../time/time.h"
#include "../../../camera/camera.h"
#include "../../../util/dynamicarray.h"
#include "../../../texture/texture.h"
#include "../../../util/color.h"

#include <stdio.h>

enum PLAYER_STATE {
    MOVING,
    RUNNING,
    DEAD,
    RESPAWNING
};

typedef struct player {
    Camera* camera;
    Rect rect;
    enum PLAYER_STATE state;
    float speed;
    float health;
} Player;

void cameraFollow(Camera* camera, const Player player, float dt);
void playerInit(Player* player, Camera* camera, Shader* shader);
void playerUpdate(Player* player, float dt);

#endif //PLAYER_H
