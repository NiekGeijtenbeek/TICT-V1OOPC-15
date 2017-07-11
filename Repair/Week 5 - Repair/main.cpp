#include "hwlib.hpp"
#include "and_hwlib.hpp"

int main (void) {
	auto buttonOne = hwlib::target::pin_in( hwlib::target::pins::d7 );
	auto buttonTwo = hwlib::target::pin_in( hwlib::target::pins::d6 );
   
   hwlib_and andgate(buttonOne, buttonTwo);   
   
   for(;;) {
      hwlib::cout << andgate.get();
      hwlib::wait_ms(500);
   }
   
}

//int main (void) {
//	auto buttonOne = hwlib::target::pin_in( hwlib::target::pins::d7 );
//	auto buttonTwo = hwlib::target::pin_in( hwlib::target::pins::d6 );
//   
//   hwlib_and andgate(buttonOne, buttonTwo);   
//   
//   for(;;) {
//      hwlib::cout << !andgate.get();
//      hwlib::wait_ms(500);
//   }
//   
//}
