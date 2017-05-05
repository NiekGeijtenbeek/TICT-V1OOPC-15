#ifndef TRAIN_HPP
#define TRAIN_HPP

#include "window.hpp"

class train {
private:
    int wagon;
    window & w;
public:
    train(window & w, int wagon):
        wagon ( wagon ),
        w ( w )
      {}
    
    void wheel(int xcord, int ycord);
    void print();
    void traincar();
    void steamtrain ();
};
#endif //TRAIN_HPP