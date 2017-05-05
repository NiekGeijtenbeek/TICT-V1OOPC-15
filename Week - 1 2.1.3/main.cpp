// example: 
// using a line that requires its window

#include <iostream>

#include "window.hpp"
#include "train.hpp"


int main(int argc, char **argv){
    window w(30, 35, 2);
    train train (w, 1);
    train.print();
   return 0;
}


