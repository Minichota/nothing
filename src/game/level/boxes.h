#ifndef BOXES_H_
#define BOXES_H_

#include "game/camera.h"
#include "game/level/platforms.h"
#include "lava.h"
#include "ebisp/expr.h"

typedef struct Boxes Boxes;
typedef struct Player Player;
typedef struct LineStream LineStream;
typedef struct Player Player;
typedef struct RectLayer RectLayer;

Boxes *create_boxes_from_rect_layer(const RectLayer *layer, RigidBodies *rigid_bodies);
void destroy_boxes(Boxes *boxes);

int boxes_render(Boxes *boxes, const Camera *camera);
int boxes_update(Boxes *boxes, float delta_time);

void boxes_float_in_lava(Boxes *boxes, Lava *lava);

int boxes_add_box(Boxes *boxes, Rect rect, Color color);
int boxes_delete_at(Boxes *boxes, Vec position);

struct EvalResult
boxes_send(Boxes *boxes, Gc *gc, struct Scope *scope, struct Expr path);

#endif  // BOXES_H_
