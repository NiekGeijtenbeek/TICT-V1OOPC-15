#include "ball.hpp"
#include <iostream>

void ball::update(){
   location += speed;
}

ball::ball( window & w, const vector & midpoint, int radius, const vector & speed ):
   circle( w, midpoint, radius ),
   speed( speed )
{}

void ball::interact( drawable & other ){
   if( this != & other){
      if( overlaps( other )){
         vector bounce_direction = other.getbounce();
         speed.x *= bounce_direction.x;
         speed.y *= bounce_direction.y;
      }
   }
}