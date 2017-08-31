#ifndef INC_3D_SOLID_COLOR_H
#define INC_3D_SOLID_COLOR_H

#include <cstdint>

class Color {

public:

    uint8_t r{0}, g{0}, b{0};

    Color() = default;

    explicit Color(uint8_t color) : r(color), g(color), b(color) {}
    Color(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b) {}

    static Color create(int r, int g, int b) {
        int _r = max(min(r, 255), 0);
        int _g = max(min(g, 255), 0);
        int _b = max(min(b, 255), 0);

        return {static_cast<uint8_t>(_r),
                static_cast<uint8_t>(_g),
                static_cast<uint8_t>(_b)};
    }

    static Color random() {
        return {static_cast<uint8_t>(rand() % 255),
                static_cast<uint8_t>(rand() % 255),
                static_cast<uint8_t>(rand() % 255)};
    }

    Color operator*(float a) {
        return Color::create(static_cast<int>(r * a),
                             static_cast<int>(g * a),
                             static_cast<int>(b * a));
    }

    Color operator+(const Color &c) {
        return Color::create(static_cast<int>(r + c.r),
                             static_cast<int>(g + c.g),
                             static_cast<int>(b + c.b));
    }
};

#endif //INC_3D_SOLID_COLOR_H
