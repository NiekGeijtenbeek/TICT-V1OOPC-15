#include "hwlib.hpp"
#include <stdio.h>

void ledmatrix( int matrix[][4], int delay, int rows ){
   int pins[][2] = {{1,27},{3,8},{3,7},{2,29}};
   int coloms = 4;
   int check = 0;
   int check = 0;

   for ( int i = 0; i<rows; ++i ){
      for ( int j = 0; j<coloms; ++j ){
         if ( matrix[i][j] == 1 ){
            hwlib::target::pin_out(pins[check][0],pins[check][1]).set(1);

         }else{
            hwlib::target::pin_out(pins[check][0],pins[check][1]).set(0);
         }
         ++check;
      }
      check = 0;
      hwlib::wait_ms( delay );
   }

   hwlib::target::pin_out(pins[0][0],pins[0][1]).set(0);
   hwlib::target::pin_out(pins[1][0],pins[1][1]).set(0);
   hwlib::target::pin_out(pins[2][0],pins[2][1]).set(0);
   hwlib::target::pin_out(pins[3][0],pins[3][1]).set(0);
}

int main( void ){
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;

   int matrix[][4] = {
      {1,1,0,0},
      {0,1,1,0},
      {0,0,1,1},
      {0,1,1,0},
      {1,1,0,0}
   };
   
   int delay = 250;
   int rows = 5;

ledmatrix(matrix, delay, rows);
}