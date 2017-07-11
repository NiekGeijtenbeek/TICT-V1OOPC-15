// example: 
// using a line that requires its window

#include <iostream>
#include "circle.hpp"
#include "window.hpp"
#include "line.hpp"
#include "filled_rectangle.hpp"
#include "huis.hpp"

int main(int argc, char **argv){
    window w(128, 64, 2);
    
   huis mijnHuis(w, 1, 40, 100, 100);
   mijnHuis.print();
   return 0;
}


