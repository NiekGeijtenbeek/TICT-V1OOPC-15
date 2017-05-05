#include "train.hpp"
#include "values.hpp"
#include "window.hpp"

template <class T> void swap( T& a, T& b){
    T c(a); a=b; b=c;
}

void train::wheel(int xcord, int ycord){
    int mid_x = xcord;
    int mid_y = ycord;
     // don't draw anything when the size would be 0 
   if( radius < 1 ){
      return;       
   }
   
   // http://en.wikipedia.org/wiki/Midpoint_circle_algorithm
   
   int fx = 1 - radius;
   int ddFx = 1;
   int ddFy = -2 * radius;
   int x = 0;
   int y = radius;
      
   // top and bottom
   w.draw( mid_x + 0, mid_y + radius );
   w.draw( mid_x + 0, mid_y - radius );
      
   // left and right 
   w.draw( mid_x + radius, mid_y + 0 );
   w.draw( mid_x + radius, mid_y - 0 );
    
   while( x < y ){
      
      // calculate next outer circle point
      if( fx >= 0 ){
        y--;
        ddFy += 2;
        fx += ddFy;
      }
      x++;
      ddFx += 2;
      fx += ddFx;   
      
      w.draw( mid_x + x, mid_y + y );
      w.draw( mid_x - x, mid_y + y );
      w.draw( mid_x + x, mid_y - y );
      w.draw( mid_x - x, mid_y - y );
      w.draw( mid_x + y, mid_y + x );
      w.draw( mid_x - y, mid_y + x );
      w.draw( mid_x + y, mid_y - x );
      w.draw( mid_x - y, mid_y - x );
   }
}

void train::steamtrain() {
//MAIN BODY
      for (int y = steamtrain_body_start_y; y < steamtrain_body_end_y; y++) {
       for (int x = steamtrain_body_start_x; x < steamtrain_body_end_x; x++) {
           w.draw(x, y);
    }
    }
//MAIN BODY LONG
    for (int y = body_long_start_y; y < body_long_end_y; y++) {
       for (int x = body_long_start_x; x < body_long_end_x; x++) {
           w.draw(x, y);
    }
    }
//Smokestack
 for (int y = stack_start_y; y < stack_end_y; y++) {
       for (int x = stack_start_x; x < stack_end_x; x++) {
           w.draw(x, y);
    }
    }
//WHEELS
wheel(33, 16);
wheel(29, 16);
wheel(25, 16);
wheel(21, 16);
}


void train::traincar() {
//TRAINCAR BODY
     for (int y = traincart_body_start_y; y < traincart_body_end_y; y++) {
       for (int x = traincart_body_start_x; x < traincart_body_end_x; x++) {
           w.draw(x, y);
        }
    }
//TRAINCAR TOP    
      for (int y = traincart_top_start_y; y < traincart_top_end_y; y++) {
       for (int x = traincart_top_start_x; x < traincart_top_end_x; x++) {
           w.draw(x, y);
    }
    }
//TRAINCAR WHEELS
   wheel(6, 16);
    
   wheel(13, 16);
//TRAINCAR CONNECT
    for (int x = connect_x ; x < connect_end_x; x++) {
           w.draw(x, connect_y);
    }
}



void train::print(){
    switch(wagon){
            case 0:
                steamtrain();
                break;
            case 1:
                traincar();
                steamtrain();
                break;
    }
    
}