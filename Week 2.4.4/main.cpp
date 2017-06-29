#include <stdio.h>
#include <stdio.h>

void switch_led( hwlib::port_out & leds, auto & button_more, auto & button_less, auto & indicator ){
	unsigned int limit = 1;
	
   for(;;){
      
		if ( button_more.get () == 0 && limit < 4 ){
			++limit;
			indicator.set(1);
			hwlib::wait_ms(250);
         indicator.set(0);
		}
		
      if ( button_less.get() == 0 && limit > 0 ){
			--limit;
			indicator.set(1);
			hwlib::wait_ms(250);
			indicator.set(0);
		}
		
		for ( unsigned int count = 0; count < limit; ++count ){
			leds.set(0x01 << count);
			hwlib::wait_ms(5);
		}
	}
}

int main( void ){
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
	
   //LED Values
	auto led0 = hwlib::target::pin_out( hwlib::target::pins::d13 );
	auto led1 = hwlib::target::pin_out( hwlib::target::pins::d12 );
	auto led2 = hwlib::target::pin_out( hwlib::target::pins::d11 );
	auto led3 = hwlib::target::pin_out( hwlib::target::pins::d10 );
	auto indicator = hwlib::target::pin_out( hwlib::target::pins::d9 );
	
   //LEDS grouped
   auto leds = hwlib::port_out_from_pins( led0,led1,led2,led3 );
	
   //BUTTON Values
	auto button_more = hwlib::target::pin_in( hwlib::target::pins::d7 );
	auto button_less = hwlib::target::pin_in( hwlib::target::pins::d6 );
		
	switch_led( leds, button_more, button_less, indicator );
	
	return 0;
}