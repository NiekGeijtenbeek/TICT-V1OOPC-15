#ifndef VICTIM_HPP
#define VICTIM_HPP

#include "window.hpp"
#include "vector.hpp"
#include "rectangle.hpp"


class victim : public rectangle{
protected:
   bool impact;

public:
   victim ( window & w, const vector & location, const vector & end, vector bounce =  vector ( 1 , 1 ) );
   void draw() override;
   void update() override;
   void interact( drawable & other) override;
   void kill();
   
};

#endif // VICTIM_HPP