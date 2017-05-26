#include "window.hpp"
#include "vector.hpp"
#include "wall.hpp"
#include "drawable.hpp"

int main(){
   window w( vector( 128, 64 ), 2 );
   wall muur(w, vector(0,0), vector(20, 4), false, 5);
   drawable * objects[] = {&muur};

   for(;;){
      w.clear();
      for( auto & p : objects ){
         p->draw();
      }
      wait_ms( 100 );
      for( auto & p : objects ){
          p->update();
      }
   }
}

