#include "hwlib.hpp"

int main( void ){	
    
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   namespace target = hwlib::target;
   
   auto scl = target::pin_oc( target::pins::scl );
   auto sda = target::pin_oc( target::pins::sda );
   
   auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl,sda );
   
   auto display = hwlib::glcd_oled( i2c_bus, 0x3c );  
   
   
   display.clear();
   for( unsigned int i = 5; i < display.size.x - 10; i++ ){
      display.write( hwlib::location( i, 10 ), hwlib::black);
   }
   
      for( unsigned int i = 5; i < display.size.y - 10; i++ ){
      display.write( hwlib::location(  10 , i ), hwlib::black);
   }
   
     for( unsigned int i = 5; i < display.size.x - 10; i++ ){
      display.write( hwlib::location( i, 50 ), hwlib::black);
   }
   
         for( unsigned int i = 5; i < display.size.y - 10; i++ ){
      display.write( hwlib::location(  65 , i ), hwlib::black);
   }
   
          for( unsigned int i = 5; i < display.size.y - 10; i++ ){
      display.write( hwlib::location(  112 , i ), hwlib::black);
   }
   
}
