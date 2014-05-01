#ifndef IMAGE_HPP_E87
#define IMAGE_HPP_E87
#include <cstddef>
#include <vector>
#include <string>

typedef unsigned char color;

struct Pixel {
    unsigned char _r, _g, _b, _a;
    Pixel(color r=0, color g=0, color b=0, color a=255) : _r(r), _g(g), _b(b), _a(a) {}
};

struct Pos {
    int _x,_y;
    Pos(int x, int y) : _x(x), _y(y) {}
};
typedef Pos Dim;

class Image {
    public:
        Image();
        Image(unsigned int width, unsigned int height);
        Pixel& pixel(Pos position);
        bool loadpicture(const std::string& filename);
        bool savepicture(const std::string& filename);
        Dim dimension() const { return Dim(_width, _height); }
        //TODO: Rewrite to make sure _pixels change size as well
        void setdimension(Dim dim) { _width=dim._x;_height=dim._y;}

    private:
        unsigned int _width, _height;
        std::vector<Pixel> _pixels;

};


#endif
