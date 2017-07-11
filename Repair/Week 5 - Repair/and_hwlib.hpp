#ifndef AND_HWLIB_HPP
#define AND_HWLIB_HPP
#include "hwlib.hpp"

class hwlib_and: public hwlib::pin_in {
private:
   
   hwlib::target::pin_in one;
   hwlib::target::pin_in two;

public:
   hwlib_and(hwlib::target::pin_in & one, hwlib::target::pin_in & two):
      one( one ),
      two( two )
   {}
   
   bool get(hwlib::buffering buffer = hwlib::buffering::buffered) {
        return(! one.get() && ! two.get());
    }
   
};

//class hwlib_and: public hwlib::pin_in {
//private:
//   
//   hwlib::target::pin_in one;
//   hwlib::target::pin_in two;
//
//public:
//   hwlib_and(hwlib::target::pin_in & one, hwlib::target::pin_in & two):
//      one( one ),
//      two( two )
//   {}
//   
//   bool get(hwlib::buffering buffer = hwlib::buffering::buffered) {
//        return(one.get() &&  two.get());
//    }
//   
//};


#endif //AND_HWLIB_HPP