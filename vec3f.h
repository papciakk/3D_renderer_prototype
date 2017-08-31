#ifndef INC_3D_SOLID_VEC3F_H
#define INC_3D_SOLID_VEC3F_H

#include <cmath>

class vec3f {
public:

    float x{0.0f}, y{0.0f}, z{0.0f};

    vec3f() = default;

    explicit vec3f(float a) : x(a), y(a), z(a) {}

    vec3f(float x, float y) : x(x), y(y) {}

    vec3f(float x, float y, float z) : x(x), y(y), z(z) {}

    static vec3f create(float x, float y, float z) {
        return {x, y, z};
    }

    vec3f operator+(const vec3f &a) const {
        return {x + a.x, y + a.y, z + a.z};
    }

    vec3f operator-(const vec3f &a) const {
        return {x - a.x, y - a.y, z - a.z};
    }

    vec3f operator-() const {
        return {-x, -y, -z};
    }

    vec3f operator*(float c) const {
        return {c * x, c * y, c * z};
    }

    vec3f operator/(float c) const {
        return {x / c, y / c, z / c};
    }

    static float dot(const vec3f &a, const vec3f &b) {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    float length() {
        return std::sqrt(x * x + y * y + z * z);
    }

    static vec3f normalize(vec3f a) {
        float len = a.length();
        return {a.x / len, a.y / len, a.z / len};
    }

    static vec3f reflect(vec3f I, vec3f N) {
        return I - N * 2.0 * dot(N, I);
    }
};

#endif //INC_3D_SOLID_VEC3F_H
