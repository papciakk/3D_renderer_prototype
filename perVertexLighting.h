#ifndef INC_3D_SOLID_PERVERTEXLIGHTING_H
#define INC_3D_SOLID_PERVERTEXLIGHTING_H

#include "vec3f.h"
#include "main.h"
#include "color.h"

Color *perVertexLighting(int vertexIds[3], vec3f lightPos);
Color getLightingForVertex(int vertexId, vec3f lightPos);
static float getAmbient();
static float getDiffuse(const vec3f &normal, const vec3f &lightDir);
static float getSpecular(const vec3f &normal, const vec3f &facePos, vec3f &lightDir);

#endif //INC_3D_SOLID_PERVERTEXLIGHTING_H
