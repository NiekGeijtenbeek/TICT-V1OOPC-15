#include "window.hpp"
#include "ball.hpp"
#include "drawable.hpp"
#include "wall.hpp"
#include "vector.hpp"
#include "victim.hpp"


int main(){
   window w( vector( 128, 64 ), 1 );
   wall left(w, vector( 0 , 0 ), vector( 4 , 64 ), false, 2, vector ( -1 , 1 ));
   wall right(w, vector( 126 , 0 ), vector( 128 , 64 ), false, 2, vector ( -1 , 1 ));
   wall bottom(w, vector(4 , 0 ), vector( 126 , 4 ), false, 2, vector ( 1 , -1 ));
   wall top(w, vector( 4 , 60 ), vector( 126 , 64 ), false, 2, vector ( 1 , -1 ));
   ball canonball(w, vector ( 64 , 32), 4, vector( 2 , 2 ));
   
   victim rip(w, vector ( 20 , 20 ), vector ( 40 , 40 ), vector ( -1 , 1 ));
   
   drawable * objects[] = { &right, &left, &top, &bottom, &canonball, &rip };

   for(;;){
      w.clear();
      for( auto & p : objects ){
         p->draw();
      }
      wait_ms( 100 );
      for( auto & p : objects ){
          p->update();
      }
      for( auto & p : objects ){
         for( auto & other : objects ){
            p->interact( *other );
         } 
      }
   }
}

