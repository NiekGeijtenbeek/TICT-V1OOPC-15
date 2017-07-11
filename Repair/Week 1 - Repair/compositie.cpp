#ifndef COMPOSITIE_HPP
#define COMPOSITIE_HPP

#include "window.hpp"
#include "line.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "filled_rectangle.hpp"
#include "compositie.hpp"

class compostie {
private:
   int start_x, start_y, end_x, end_y;
   filled_rectangle square;
   line roof1, roof2;
   window & w;
public:
   
}