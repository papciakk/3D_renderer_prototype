#ifndef INC_3D_SOLID_PERFACELIGHTING_H
#define INC_3D_SOLID_PERFACELIGHTING_H

#include "vec3f.h"
#include "main.h"
#include "color.h"

const vec3f viewPos = vec3f::create(0.0f, 1.0f, 5.0f);

Color perFaceLighting(int faceId, vec3f lightPos);
static float getSpecular(const vec3f &normal, const vec3f &facePos, vec3f &lightDir);
static float getDiffuse(const vec3f &normal, const vec3f &lightDir);
static float getAmbient();

#endif //INC_3D_SOLID_PERFACELIGHTING_H
