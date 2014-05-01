#ifndef FILTER_HPP_E87
#define FILTER_HPP_E87

#include <functional>
#include "Image.hpp"

class Filter {
    public:
        Filter();
        
        void Set(std::function<Pixel(int,int)> function);
        Image apply(const Image& input);

    private:
        std::function<Pixel(int,int)> _function;

};

#endif
