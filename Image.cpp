#include "Image.hpp"
#include "lodepng.h"
#include <iostream>

Image::Image(): _width(0), _height(0) {

}

Image::Image(unsigned int width, unsigned int height): _width(width), _height(height) {

}

Pixel& Image::pixel(Pos position) {
    // TODO: Better solution than letting vector handle the error 
    //if(x < width && y < height) 

    if(position._x > -1 && position._x < _width && position._y > -1 && position._y < _height) {
        return _pixels.at(_width*position._y + position._x);
    }
    return _pixels.at(0);
}

bool Image::loadpicture(const std::string& filename) {
    bool success = true;
    std::vector<unsigned char> vec;
    unsigned error = lodepng::decode(vec, _width, _height, filename);
    if(error) {
        std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
        success = false;
    }
    return success;
}

//TODO: What if the size has been changed? We need to crop the image correctly
bool Image::savepicture(const std::string& filename) {
    
    // TODO: Better word for it? 
    bool success = true;
    std::vector<unsigned char> vec;
    // Output the data
    unsigned error = lodepng::encode(filename, vec, _width, _height);

    //if there's an error, display it
    if(error) {
        std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
        success = false;
    }
    return success;
}
