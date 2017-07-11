#include "victim.hpp"
#include <iostream>

void victim::update(){
   if (impact) {
      if (location.x != end.x){
      location+= vector ( 1 , 1 );
      end+= vector ( -1 , -1 );
      }
   }
}

victim::victim(  window & w, const vector & location, const vector & end, vector bounce):
   rectangle( w, location, end, bounce ),
   impact ( false )
 {}

void victim::interact( drawable & other ){
   if( this != & other){
      if( overlaps( other )){
         impact = true;
         bounce = vector ( 1 , 1 );
      }
   }
}

void victim::draw() {
   rectangle (w, location, end).draw();
}