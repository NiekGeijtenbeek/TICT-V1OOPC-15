#ifndef HUIS_HPP
#define HUIS_HPP

#include "window.hpp"
#include "line.hpp"
#include "circle.hpp"
#include "filled_rectangle.hpp"
#include "huis.hpp"

class huis {
private:
   int start_x, start_y, end_x, end_y;
   filled_rectangle square;
   line dak1, dak2;
   window & w;
public:
   huis(window & w, int start_x, int start_y, int end_x, int end_y);
   void print();
};
#endif