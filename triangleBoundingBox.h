#ifndef INC_3D_SOLID_TRIANGLEBOUNDINGBOX_H
#define INC_3D_SOLID_TRIANGLEBOUNDINGBOX_H

#include "color.h"
#include "cfg.h"

float drawTriangleBoundingBox(SDL_Surface *screen, Point vertices[3], Point p_tl, Point p_br, float depths[3],
                              float depthBuffer[][TILE_RES_Y], Point tile_tl,
                              vec3f positions[3], vec3f normals[3], vec3f lightPos);

#endif //INC_3D_SOLID_TRIANGLEBOUNDINGBOX_H
