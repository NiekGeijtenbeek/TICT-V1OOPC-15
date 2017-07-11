#include "window.hpp"
#include "line.hpp"
#include "circle.hpp"
#include "filled_rectangle.hpp"
#include "huis.hpp"

huis::huis(window & w, int start_x, int start_y, int end_x, int end_y):
   square (w, start_x, start_y, end_x, end_y),
   dak1 (w, start_x, start_y, end_x-(start_x/3), start_y/3),
   dak2 (w, end_x, start_y, end_x-(start_x/3), start_y/3),
   w(w)
{}

void huis::print() {
   square.print();
   dak1.print();
   dak2.print();
};