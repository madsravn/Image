#include "Filter.hpp"

Filter::Filter() {}

void Filter::Set(std::function<Pixel(int,int)> function) {
    _function = function;
}


Image Filter::apply(const Image& input) {
    Image img;
    img.setdimension(input.dimension());





    return img;

}
   
