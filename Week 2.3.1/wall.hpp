#ifndef WALL_HPP
#define WALL_HPP

#include "window.hpp"
#include "vector.hpp"
#include "rectangle.hpp"


class wall : public rectangle{
private:
   bool filled;
   int update_interval;
   int update_count;

public:
   wall ( window & w, const vector & location, const vector & end, bool filled, int update_interval );
   void draw() override;
   void update() override;

   
};

#endif // WALLS_HPP