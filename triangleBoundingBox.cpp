#include <tuple>
#include "main.h"
#include "color.h"
#include "triangleBoundingBox.h"
#include "perPixelLighting.h"

float drawTriangleBoundingBox(SDL_Surface *screen, Point vertices[3], Point p_tl, Point p_br, float depths[3],
                              float depthBuffer[][TILE_RES_Y], Point tile_tl,
                              vec3f positions[3], vec3f normals[3], vec3f lightPos) {

    int all = 0, effective = 0;

    int dx[3] = {vertices[1].x - vertices[0].x, vertices[2].x - vertices[1].x, vertices[0].x - vertices[2].x};
    int dy[3] = {vertices[1].y - vertices[0].y, vertices[2].y - vertices[1].y, vertices[0].y - vertices[2].y};

    const int startX = p_tl.x;
    const int startY = p_tl.y;

    int e[3] = {
            (startX - vertices[0].x) * dy[0] - (startY - vertices[0].y) * dx[0],
            (startX - vertices[1].x) * dy[1] - (startY - vertices[1].y) * dx[1],
            (startX - vertices[2].x) * dy[2] - (startY - vertices[2].y) * dx[2]
    };

    int e_tmp[3];

#ifdef Z_BUFFERING
    int area = (vertices[0].x - vertices[1].x) * (vertices[2].y - vertices[1].y) -
               (vertices[0].y - vertices[1].y) * (vertices[2].x - vertices[1].x);
#endif

    for (uint16_t y = p_tl.y; y < p_br.y; y++) {
        e_tmp[0] = e[0];
        e_tmp[1] = e[1];
        e_tmp[2] = e[2];

        for (uint16_t x = p_tl.x; x < p_br.x; x++) {
            all++;

            if (e[0] <= 0 && e[1] <= 0 && e[2] <= 0) {

                float normalx = (e[0] * normals[2].x + e[1] * normals[0].x + e[2] * normals[1].x) / area;
                float normaly = (e[0] * normals[2].y + e[1] * normals[0].y + e[2] * normals[1].y) / area;
                float normalz = (e[0] * normals[2].z + e[1] * normals[0].z + e[2] * normals[1].z) / area;
                vec3f normal(normalx, normaly, normalz);

                float posx = (e[0] * positions[2].x + e[1] * positions[0].x + e[2] * positions[1].x) / area;
                float posy = (e[0] * positions[2].y + e[1] * positions[0].y + e[2] * positions[1].y) / area;
                float posz = (e[0] * positions[2].z + e[1] * positions[0].z + e[2] * positions[1].z) / area;
                vec3f position(posx, posy, posz);


                Color color = getLightingForPixel(position, normal, lightPos);

//                auto r = static_cast<uint8_t>((e[0] * colors[0].r + e[1] * colors[1].r + e[2] * colors[2].r) / area);
//                auto g = static_cast<uint8_t>((e[0] * colors[0].g + e[1] * colors[1].g + e[2] * colors[2].g) / area);
//                auto b = static_cast<uint8_t>((e[0] * colors[0].b + e[1] * colors[1].b + e[2] * colors[2].b) / area);

#ifdef Z_BUFFERING
                float depth = (e[0] * depths[0] + e[1] * depths[1] + e[2] * depths[2]) / area * 255;
                if (depth > depthBuffer[x - tile_tl.x][y - tile_tl.y]) {
                    putPixel(screen, x, y, color.r, color.g, color.b);
                    depthBuffer[x - tile_tl.x][y - tile_tl.y] = depth;
                }
#else
                putPixel(screen, x, y, colors[0].r, colors[0].g, colors[0].b);
#endif

                effective++;
            }

            e[0] += dy[0];
            e[1] += dy[1];
            e[2] += dy[2];
        }

        e[0] = e_tmp[0] - dx[0];
        e[1] = e_tmp[1] - dx[1];
        e[2] = e_tmp[2] - dx[2];
    }

    return (float) effective / all;
}
