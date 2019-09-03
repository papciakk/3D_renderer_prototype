#include "perVertexLighting.h"
#include "mesh.h"

float ambientMultiplier = 0.2f;
float diffuseMultiplier = 1.0f;
float specularMultiplier = 1.0f;
float shininness = 16.0f;
auto materialColor = Color(141, 202, 239);
auto viewPos = vec3f::create(0, 1, 5);


Color getLightingForVertex(vec3f positions, vec3f normal, vec3f lightPos);

Color *perVertexLighting(vec3f positions[3], vec3f normals[3], vec3f lightPos) {
    auto *vertexColors = new Color[3];
    vertexColors[0] = getLightingForVertex(positions[2], normals[2], lightPos);
    vertexColors[1] = getLightingForVertex(positions[0], normals[0], lightPos);
    vertexColors[2] = getLightingForVertex(positions[1], normals[1], lightPos);
    return vertexColors;
}

Color getLightingForVertex(vec3f vertexPos, vec3f normal, vec3f lightPos) {
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
