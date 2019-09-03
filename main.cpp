#include <tuple>
#include <ctime>
#include "main.h"
#include "triangleBoundingBox.h"
#include "mesh.h"
#include "perVertexLighting.h"

auto lightPos = vec3f::create(30.0f, -30.0f, 15.0f);
float scale = 1.0f;

int main(int argc, char **argv) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        return showSDLError("SDL_Init");
    }
    atexit(SDL_Quit);

    SDL_Surface *screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
    if (screen == nullptr) {
        return showSDLError("SDL_SetVideoMode");
    }

    bool isRunning = true;

    while (isRunning) {
        redraw(screen);

        Uint8 *k = SDL_GetKeyState(nullptr);
        if (k['a']) lightPos.x -= 1;
        if (k['d']) lightPos.x += 1;
        if (k['w']) lightPos.y -= 1;
        if (k['s']) lightPos.y += 1;
        if (k['q']) lightPos.z -= 1;
        if (k['e']) lightPos.z += 1;
        if (k['z']) scale -= 0.1f;
        if (k['x']) scale += 0.1f;

        SDL_Event event{};
        while (SDL_PollEvent(&event) != 0) {
            switch (event.type) {
                case SDL_QUIT:
                    isRunning = false;
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                        isRunning = false;
                    }
                default:
                    break;
            }
        }
    }
}

void redraw(SDL_Surface *screen) {

    SDL_FillRect(screen, nullptr, 0);

    renderMesh(screen);

    SDL_Flip(screen);
    SDL_Delay(16);
}

Point tile_tl;
Point tile_br;

float efficiency;
int cntFacesProcessed;

void renderTile(const SDL_Surface *screen);

void renderMesh(const SDL_Surface *screen) {
    cntFacesProcessed = 0;
    efficiency = 0;

    clock_t t = clock();

    for (uint16_t y = 0; y < SCREEN_HEIGHT; y += TILE_RES_Y) {
        for (uint16_t x = 0; x < SCREEN_WIDTH; x += TILE_RES_X) {
            tile_tl.x = x;
            tile_tl.y = y;
            tile_br.x = x + TILE_RES_X;
            tile_br.y = y + TILE_RES_Y;
            renderTile(screen);
        }
    }

    cout << (double) (clock() - t) / CLOCKS_PER_SEC * 1000.0f << " ms" << endl;
    cout << "efficiency: " << efficiency / cntFacesProcessed << endl;

#ifdef ENABLE_CULLING
    cout << "triangle inefficiency: " << (float) cntFacesProcessed / faceCount << endl;
#endif
}

void renderTile(const SDL_Surface *screen) {
    float depthBuffer[TILE_RES_X][TILE_RES_Y];
    memset(depthBuffer, 0, TILE_RES_X * TILE_RES_Y * sizeof(float));

    for (int i = 0; i < faceCount; i++) {
        Point vertices[3];
        float depths[3];

        int vertexIds[3] = {faces[i][0], faces[i][1], faces[i][2]};

        // project vertices to screen space
        for (int j = 0; j < 3; j++) {
            int vertexId = vertexIds[j];
            vec3f vertex = vec3f::create(model[vertexId][0], model[vertexId][1], model[vertexId][2]);
            vertex = vertex * scale;

            vertices[j].x = static_cast<uint16_t>((vertex.x + 0.5f) * SCREEN_HEIGHT + (SCREEN_WIDTH - SCREEN_HEIGHT) / 2);
            vertices[j].y = static_cast<uint16_t>((vertex.y + 0.5f) * SCREEN_HEIGHT);
            depths[j] = vertex.z + 0.5f;
        }

        float depths1[3] = {depths[2], depths[0], depths[1]}; // TODO: fix vertices order

#ifdef ENABLE_CULLING
        int16_t area = (vertices[0].x - vertices[1].x) * (vertices[2].y - vertices[1].y) -
                       (vertices[0].y - vertices[1].y) * (vertices[2].x - vertices[1].x);

        // backface culling - ccw mode
        if (area < 0) {
#endif

            // calculate triangle bounding box
            Point bounding_box_tl(min(vertices[0].x, min(vertices[1].x, vertices[2].x)),
                                  min(vertices[0].y, min(vertices[1].y, vertices[2].y)));
            Point bounding_box_br(max(vertices[0].x, max(vertices[1].x, vertices[2].x)),
                                  max(vertices[0].y, max(vertices[1].y, vertices[2].y)));

            // intersection with tile boundaries
            bounding_box_tl.x = max(bounding_box_tl.x, tile_tl.x);
            bounding_box_tl.y = max(bounding_box_tl.y, tile_tl.y);
            bounding_box_br.x = min(bounding_box_br.x, tile_br.x);
            bounding_box_br.y = min(bounding_box_br.y, tile_br.y);

            vec3f positions[3];
            vec3f normals[3];
            for(int k = 0; k < 3; k++) {
                int vertexId = vertexIds[k];
                vec3f vertexPos = vec3f::create(model[vertexId][0], model[vertexId][1], model[vertexId][2]);
                vec3f normal = vec3f::create(vertexNormals[vertexId][0], vertexNormals[vertexId][1],
                                             vertexNormals[vertexId][2]);

                positions[k] = vertexPos;
                normals[k] = normal;
            }

            Color *colors = perVertexLighting(positions, normals, lightPos);

            // intersection has positive area
            if (bounding_box_tl.x < bounding_box_br.x && bounding_box_tl.y < bounding_box_br.y) {
                cntFacesProcessed++;

                efficiency += drawTriangleBoundingBox(const_cast<SDL_Surface *>(screen), vertices, bounding_box_tl,
                                                      bounding_box_br, colors, depths1, depthBuffer, tile_tl);

            }

#ifdef ENABLE_CULLING
        }
#endif

    }
}

void putPixel(SDL_Surface *surface, int x, int y, uint8_t r, uint8_t g, uint8_t b) {
    Uint32 pixel = SDL_MapRGB(surface->format, r, g, b);
    Uint8 *p = (Uint8 *) surface->pixels + y * surface->pitch + x * 4;
    *(Uint32 *) p = pixel;
}

int showSDLError(const string &msg) {
    cout << msg << ": " << SDL_GetError() << endl;
    exit(1);
}
