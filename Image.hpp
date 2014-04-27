#ifndef IMAGE_HPP_E87
#define IMAGE_HPP_E87
#include <cstddef>
#include <vector>
#include <string>

typedef unsigned char color;

struct Pixel {
    unsigned char _r, _g, _b, _a;
    Pixel(color r, color g, color b, color a=255) : _r(r), _g(g), _b(b), _a(a) {}
};

class Image {
    public:
        Image();
        Image(unsigned int width, unsigned int height);
        Pixel& pixel(unsigned int x, unsigned int y);
        bool loadpicture(const std::string& filename);
        bool savepicture(const std::string& filename);

    private:
        unsigned int _width, _height;
        std::vector<Pixel> _pixels;

};


#endif
