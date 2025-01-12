#include "system/stacktrace.h"
#include <math.h>

#include "point.h"

Vec vec(float x, float y)
{
    Vec result = {
        .x = x,
        .y = y
    };
    return result;
}

Vec vec_from_polar(float arg, float mag)
{
    return vec_scala_mult(
        vec(cosf(arg), sinf(arg)),
        mag);
}

Vec vec_from_ps(Point p1, Point p2)
{
    Vec result = {
        .x = p2.x - p1.x,
        .y = p2.y - p1.y
    };
    return result;
}

float vec_arg(Vec v)
{
    return atan2f(v.y, v.x);
}

float vec_mag(Vec v)
{
    return sqrtf(v.x * v.x + v.y * v.y);
}

Vec vec_sum(Vec v1, Vec v2)
{
    Vec result = {
        .x = v1.x + v2.x,
        .y = v1.y + v2.y
    };
    return result;
}

Vec vec_sub(Vec v1, Vec v2)
{
    Vec result = {
        .x = v1.x - v2.x,
        .y = v1.y - v2.y
    };
    return result;
}

Vec vec_neg(Vec v)
{
    Vec result = {
        .x = -v.x,
        .y = -v.y
    };

    return result;
}

float vec_length(Vec v)
{
    return sqrtf(v.x * v.x + v.y * v.y);
}

void vec_add(Vec *v1, Vec v2)
{
    v1->x += v2.x;
    v1->y += v2.y;
}

Vec vec_scala_mult(Vec v, float scalar)
{
    Vec result = {
        .x = v.x * scalar,
        .y = v.y * scalar
    };
    return result;
}

Vec vec_entry_mult(Vec v1, Vec v2)
{
    Vec result = {
        .x = v1.x * v2.x,
        .y = v1.y * v2.y
    };

    return result;
}

Vec vec_entry_div(Vec v1, Vec v2)
{
    Vec result = {
        .x = v1.x / v2.x,
        .y = v1.y / v2.y
    };

    return result;
}

float rad_to_deg(float a)
{
    return 180 / PI * a;
}

Vec vec_norm(Vec v)
{
    // TODO(#657): math/point/vec_norm: using vec_length is too expensive
    //   It involves multiplication and sqrt. We can just check if its components are close to 0.0f.

    const float l = vec_length(v);

    if (l < 1e-6) {
        return vec(0.0f, 0.0f);
    }

    return vec(v.x / l, v.y / l);
}

float vec_sqr_norm(Vec v)
{
    return v.x * v.x + v.y * v.y;
}
