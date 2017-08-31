#include "perVertexLighting.h"

#include "perFaceLighting.h"
#include "mesh.h"

float ambientMultiplier = 0.2f;
float diffuseMultiplier = 1.0f;
float specularMultiplier = 1.0f;
float shininness = 8.0f;
auto materialColor = Color(141, 202, 239);

Color getLightingForVertex(int vertexId, vec3f lightPos);

Color *perVertexLighting(int vertexIds[3], vec3f lightPos) {
    auto *vertexColors = new Color[3];
    vertexColors[0] = getLightingForVertex(vertexIds[2], lightPos);
    vertexColors[1] = getLightingForVertex(vertexIds[0], lightPos);
    vertexColors[2] = getLightingForVertex(vertexIds[1], lightPos);
    return vertexColors;
}

Color getLightingForVertex(int vertexId, vec3f lightPos) {
    vec3f vertexPos = vec3f::create(model[vertexId][0], model[vertexId][1], model[vertexId][2]);
    vec3f normal = vec3f::create(vertexNormals[vertexId][0], vertexNormals[vertexId][1], vertexNormals[vertexId][2]);

    normal = vec3f::normalize(normal);
    vec3f lightDir = vec3f::normalize(lightPos - vertexPos);

    float ambient = getAmbient();
    float specular = getSpecular(normal, vertexPos, lightDir);
    float diffuse = getDiffuse(normal, lightDir);

    return materialColor*ambientMultiplier*ambient
           + materialColor*diffuseMultiplier*diffuse
           + Color(255, 255, 255)*specularMultiplier*specular;
}

static float getAmbient() {
    return 1.0f;
}

static float getDiffuse(const vec3f &normal, const vec3f &lightDir) {
    return max(vec3f::dot(normal, lightDir), 0.0f);
}

static float getSpecular(const vec3f &normal, const vec3f &facePos, vec3f &lightDir) {
    vec3f viewDir = vec3f::normalize(viewPos - facePos);
    vec3f reflectDir = vec3f::reflect(-lightDir, normal);
    return static_cast<float>(pow(max(vec3f::dot(viewDir, reflectDir), 0.0f), shininness));
}
