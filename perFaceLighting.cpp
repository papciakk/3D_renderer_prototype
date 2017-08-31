#include "perFaceLighting.h"
#include "mesh.h"
#include "color.h"

Color perFaceLighting(int faceId, vec3f lightPos) {
//    vec3f facePos = vec3f::create(model[faces[faceId][0]][0], model[faces[faceId][0]][1], model[faces[faceId][0]][2]);
//    vec3f normal = vec3f::create(faceNormals[faceId][0], faceNormals[faceId][1], faceNormals[faceId][2]);
//
//    normal = vec3f::normalize(normal);
//    vec3f lightDir = vec3f::normalize(lightPos - facePos);
//
//    float ambient = getAmbient();
//    float specular = getSpecular(normal, facePos, lightDir);
//    float diffuse = getDiffuse(normal, lightDir);
//
//    return Color(141, 202, 239) * ambient + Color(141, 202, 239) * diffuse + Color(static_cast<uint8_t>(70 * specular));
    return Color();
}

static float getAmbient() {
    return 0.1f;
}

static float getDiffuse(const vec3f &normal, const vec3f &lightDir) {
    return max(vec3f::dot(normal, lightDir), 0.0f);
}

static float getSpecular(const vec3f &normal, const vec3f &facePos, vec3f &lightDir) {
    vec3f viewDir = vec3f::normalize(viewPos - facePos);
    vec3f reflectDir = vec3f::reflect(-lightDir, normal);
    return static_cast<float>(pow(max(vec3f::dot(viewDir, reflectDir), 0.0f), 8));
}