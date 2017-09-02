#include <tuple>
#include "main.h"
#include "color.h"
#include "triangleMidpointTraversal.h"

//#define STEP_BY_STEP

void putPixelIfInTriangle(const SDL_Surface *screen, const Point *vertices, const Color *colors, uint16_t tx,
                          uint16_t ty);

bool isInTriangle(const Point *vertices, uint16_t tx, uint16_t ty);

int edgeFunction(const Point &a, const Point &b, uint16_t x, uint16_t y) {
    return (x - a.x) * (b.y - a.y) - (y - a.y) * (b.x - a.x);
}

float drawTriangleMidpointTraversal(SDL_Surface *screen, Point vertices[3], Point p_tl, Point p_br, Color colors[3],
                                    float depths[3], float depthBuffer[][TILE_RES_Y], Point tile_tl) {

    Point v[3] = {vertices[0], vertices[1], vertices[2]};

    Point tmp;
    if (v[0].y > v[1].y) {
        tmp = v[0];
        v[0] = v[1];
        v[1] = tmp;
    }
    if (v[0].y > v[2].y) {
        tmp = v[0];
        v[0] = v[2];
        v[2] = tmp;
    }
    if (v[1].y > v[2].y) {
        tmp = v[1];
        v[1] = v[2];
        v[2] = tmp;
    }

    int leftEndPointX = v[1].x;
    int rightEndPointX = v[1].x;

    int tx = v[1].x;

    for (int ty = v[1].y; ty < v[2].y; ty++) {
        int tempx = tx;
        int tempy = ty;

        tempx--;
        while (isInTriangle(vertices, tempx, tempy)) {
            putPixel(screen, tempx, tempy, colors[0].r, colors[0].g, colors[0].b);
#ifdef STEP_BY_STEP
            SDL_Flip(screen);
            SDL_Delay(10);
#endif
            tempx--;
        }

        leftEndPointX = tempx + 1;
        tempx = tx + 1;

        tempx++;
        while (isInTriangle(vertices, tempx, tempy)) {
            putPixel(screen, tempx, tempy, colors[0].r, colors[0].g, colors[0].b);
#ifdef STEP_BY_STEP
            SDL_Flip(screen);
            SDL_Delay(10);
#endif
            tempx++;
        }

        putPixel(screen, tx, ty, 0, 255, 255);

        rightEndPointX = tempx - 1;
        tx = leftEndPointX + ((rightEndPointX - leftEndPointX) >> 1);
    }

    tx = v[1].x;

    for (int ty = v[1].y - 1; ty > v[0].y; ty--) {
        int tempx = tx;
        int tempy = ty;

        tempx--;
        while (isInTriangle(vertices, tempx, tempy)) {
            putPixel(screen, tempx, tempy, colors[0].r, colors[0].g, colors[0].b);
#ifdef STEP_BY_STEP
            SDL_Flip(screen);
            SDL_Delay(10);
#endif
            tempx--;
        }

        leftEndPointX = tempx + 1;
        tempx = tx + 1;

        tempx++;
        while (isInTriangle(vertices, tempx, tempy)) {
            putPixel(screen, tempx, tempy, colors[0].r, colors[0].g, colors[0].b);
#ifdef STEP_BY_STEP
            SDL_Flip(screen);
            SDL_Delay(10);
#endif
            tempx++;
        }

        putPixel(screen, tx, ty, 0, 255, 255);

        rightEndPointX = tempx - 1;
        tx = leftEndPointX + ((rightEndPointX - leftEndPointX) >> 1);
    }

    putPixel(screen, v[0].x, v[0].y, 0, 255, 255);
    putPixel(screen, v[1].x, v[1].y, 255, 0, 255);
    putPixel(screen, v[2].x, v[2].y, 255, 255, 0);

    int all = 0, effective = 0;
}

bool isInTriangle(const Point *vertices, uint16_t tx, uint16_t ty) {
    int e[3] = {
            edgeFunction(vertices[0], vertices[1], tx, ty),
            edgeFunction(vertices[1], vertices[2], tx, ty),
            edgeFunction(vertices[2], vertices[0], tx, ty)
    };

    return (e[0] <= 0 && e[1] <= 0 && e[2] <= 0);
}


