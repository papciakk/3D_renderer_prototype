#ifndef INC_3D_SOLID_TRIANGLEBOUNDINGBOX_H
#define INC_3D_SOLID_TRIANGLEBOUNDINGBOX_H

#include "color.h"
#include "cfg.h"

float drawTriangleBoundingBox(SDL_Surface *screen, Point vertices[3], Point p_tl, Point p_br, Color colors[3],
                              float depths[3], float depthBuffer[][TILE_RES_Y], Point tile_tl);

#endif //INC_3D_SOLID_TRIANGLEBOUNDINGBOX_H
