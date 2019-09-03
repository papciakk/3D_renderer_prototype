#ifndef INC_3D_SOLID_PERPIXELLIGHTING_H
#define INC_3D_SOLID_PERPIXELLIGHTING_H

#include "vec3f.h"
#include "main.h"
#include "color.h"

Color getLightingForPixel(vec3f position, vec3f normal, vec3f lightPos);
static float getAmbient();
static float getDiffuse(const vec3f &normal, const vec3f &lightDir);
static float getSpecular(const vec3f &normal, const vec3f &facePos, vec3f &lightDir);


#endif //INC_3D_SOLID_PERPIXELLIGHTING_H
