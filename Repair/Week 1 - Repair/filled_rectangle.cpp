#include "filled_rectangle.hpp"

void filled_rectangle::print(){
    for (int y = start_y; y < end_y; y++) {
       for (int x = start_x; x < end_x; x++) {
           w.draw(x, y);
    }
    }
}