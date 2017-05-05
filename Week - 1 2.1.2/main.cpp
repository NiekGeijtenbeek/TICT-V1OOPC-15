// example: 
// using a line that requires its window

#include <iostream>

#include "window.hpp"
#include "line.hpp"
#include "filled_rectangle.hpp"

int main(int argc, char **argv){
    window w(128, 64, 2);
    
    filled_rectangle rechthoek1(w, 20, 10, 30, 20);
    filled_rectangle rechthoek2(w, 60, 40, 120, 100);
    filled_rectangle rechthoek3(w, 30, 25, 50, 40);
    
    rechthoek1.print();
    rechthoek2.print();
    rechthoek3.print();
   return 0;
}


