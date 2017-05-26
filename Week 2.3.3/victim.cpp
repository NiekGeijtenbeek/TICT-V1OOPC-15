#include "victim.hpp"
#include <iostream>

void victim::update(){
   if (impact) {
      location+= vector ( 1 , 1 );
      end+= vector ( -1 , -1 );
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
   if ((location == end) || (location.x == end.x) ) {
      impact = false;
   }
   else {
      rectangle (w, location, end).draw();
   }
}