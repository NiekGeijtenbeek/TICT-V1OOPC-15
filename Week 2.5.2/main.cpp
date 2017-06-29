#include "hwlib.hpp"

namespace hwlib {
class two_input_AND : public pin_in {
private:
	pin_in & one;
	pin_in & two;
public:
	two_input_AND(pin_in & one, pin_in & two):
   one(one),two(two)
	{}
	
	bool get(buffering buf = buffering::unbuffered ) override{
		if (one.get() == 1 || two.get() == 1){
			return 1;
		}
		return 0;
	}
};
};

int main( void ){
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	auto led = hwlib::target::pin_out( hwlib::target::pins::d13 );
   auto button_one = hwlib::target::pin_in( hwlib::target::pins::d6 );
	auto button_two = hwlib::target::pin_in( hwlib::target::pins::d5 );
	auto buttons = hwlib::two_input_AND (button_one, button_two);
	
	for(;;){
		led.set(buttons.get());
		hwlib::wait_ms( 15 );
	}
	
   return 0;
}