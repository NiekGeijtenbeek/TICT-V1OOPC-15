#include "hwlib.hpp"

namespace hwlib {

class inverted : public pin_out{
private:
	pin_out & one;
public:
	inverted(pin_out & one):
		one(one)
      {}
      
	void set( bool x, buffering buf = buffering::unbuffered )override{
		one.set(!x, buf);
	}
};

class pin_out_all : public pin_out {
private:
   pin_out * list[ 8 ];     
   
public:

   pin_out_all( 
      pin_out & p0, 
      pin_out & p1 = pin_out_dummy,  
      pin_out & p2 = pin_out_dummy, 
      pin_out & p3 = pin_out_dummy, 
	   pin_out & p4 = pin_out_dummy,  
      pin_out & p5 = pin_out_dummy, 
      pin_out & p6 = pin_out_dummy,
	   pin_out & p7 = pin_out_dummy 
   ):
      list{ &p0, &p1, &p2, &p3, &p4, &p5, &p6, &p7 }
   {}
   
   void set( bool v,  buffering buff = buffering::unbuffered ) override {
      for( auto p  : list ){
          p->set( v, buff );
      }
   }
};


}; //namespace hwlib

int main( void ){
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	auto led0 = hwlib::target::pin_out( hwlib::target::pins::d13 );
	auto led1 = hwlib::target::pin_out( hwlib::target::pins::d12 );
	auto led2 = hwlib::target::pin_out( hwlib::target::pins::d11 );
	auto led3 = hwlib::target::pin_out( hwlib::target::pins::d10 );
	
	
	auto led2_invert = hwlib::inverted(led2);
	auto led3_invert = hwlib::inverted(led3);
	
	
	auto leds = hwlib::pin_out_all( 
		led2_invert, 
		led3_invert, 
		led0, 
		led1 
	);

   hwlib::blink( leds );
	return 0;
}