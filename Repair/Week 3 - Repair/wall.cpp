#include "wall.hpp"

wall::wall(window & w, const vector & location, const vector & end, bool filled, int update_interval, vector bounce):
   rectangle(w, location, end, bounce),
   filled( filled ),
   update_interval ( update_interval ),
   update_count( 0 )
{}


void wall::draw() {
   if( filled ) {
      int x, y, dif;
      vector temp_lf = location, temp_ef = end;
      x = end.x - location.x;
      y = end.y - location.y;
      
      if(x>y) {
         dif = y;
      }else {
         dif = x;
      }
      
      rectangle(w, temp_lf, temp_ef).draw();
      for (int c = 0; c < dif; c++) {
         rectangle(w, temp_lf+=vector(1 , 1), temp_ef+=vector(-1, -1)).draw();
      }
      
   }else {
      vector temp_le = location, temp_ee = end;
      rectangle(w, temp_le, temp_ee).draw();
   }
   
}

void wall::update() {
   update_count++;
   if ( update_count == update_interval ) {
      filled = !filled;
      update_count = 0;
   }
}
