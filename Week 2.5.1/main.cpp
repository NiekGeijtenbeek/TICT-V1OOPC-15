#include "hwlib.hpp"

void switch_led( hwlib::port_out & leds, auto & button_more, auto & button_less){
	unsigned int limit = 1;
   
	for(;;){
		if( button_more.get() == 0 && limit < 8 ){
			++limit;
			hwlib::wait_ms( 200 );
		}
		
		if( button_less.get() == 0 && limit > 0 ){
			--limit;
			hwlib::wait_ms( 200 );
		}
		
		for( unsigned int row_count = 0; row_count < limit; ++row_count ){
			leds.set( 0x01 << row_count );
			hwlib::wait_ms( 1 );
		}
	}
}

int main( void ){
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	auto led_0 = hwlib::target::pin_out( hwlib::target::pins::d13 );
	auto led_1 = hwlib::target::pin_out( hwlib::target::pins::d12 );
	auto led_2 = hwlib::target::pin_out( hwlib::target::pins::d11 );
	auto led_3 = hwlib::target::pin_out( hwlib::target::pins::d10 );
	
	auto ds = hwlib::target::pin_out( hwlib::target::pins::d7 );
	auto shcp = hwlib::target::pin_out( hwlib::target::pins::d6 );
	auto stcp = hwlib::target::pin_out( hwlib::target::pins::d5 );

	auto spi = hwlib::spi_bus_bit_banged_sclk_mosi_miso(
		shcp, 
		ds, 
		hwlib::pin_in_dummy
	);
	
	auto sn74_hc959 = hwlib::hc595(spi, stcp);
	
	auto leds = hwlib::port_out_from_pins(
		led_0,
		led_1,
		led_2,
		led_3,
		sn74_hc959.p0,
		sn74_hc959.p1,
		sn74_hc959.p2,
		sn74_hc959.p3
	);
	
	auto button_more = hwlib::target::pin_in( hwlib::target::pins::d6 );
	auto button_less = hwlib::target::pin_in( hwlib::target::pins::d5 );
		
	switch_led(leds, button_add, button_less);
	return 0;
}

