#include "perPixelLighting.h"
#include "mesh.h"

float ambientMultiplier = 0.2f;
float diffuseMultiplier = 1.0f;
float specularMultiplier = 1.0f;
float shininness = 8.0f;
auto materialColor = Color(141, 202, 239);
auto viewPos = vec3f::create(0, 1, 5);

Color getLightingForPixel(vec3f vertexPos, vec3f normal, vec3f lightPos) {
    normal = vec3f::normalize(normal);
    vec3f lightDir = vec3f::normalize(lightPos - vertexPos);

    float ambient = getAmbient();
    float specular = getSpecular(normal, vertexPos, lightDir);
    float diffuse = getDiffuse(normal, lightDir);

    return materialColor * ambientMultiplier * ambient
           + materialColor * diffuseMultiplier * diffuse
           + Color(255, 255, 255) * specularMultiplier * specular;
}

float getAmbient() {
    return 1.0f;
}

float getDiffuse(const vec3f &normal, const vec3f &lightDir) {
    return max(vec3f::dot(normal, lightDir), 0.0f);
}

float getSpecular(const vec3f &normal, const vec3f &facePos, vec3f &lightDir) {
    vec3f viewDir = vec3f::normalize(viewPos - facePos);
    vec3f reflectDir = vec3f::reflect(-lightDir, normal);
    return static_cast<float>(pow(max(vec3f::dot(viewDir, reflectDir), 0.0f), shininness));
}
