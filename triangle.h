#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <GL/glut.h>
#include "vertex.h"

class Triangle
{

private:
    _vertex3f p1;
    _vertex3f p2;
    _vertex3f p3;
public:
    Triangle();
    _vertex3f get_point_1();
    _vertex3f get_point_2();
    _vertex3f get_point_3();
    void set_point_1(_vertex3f p1);
    void set_point_2(_vertex3f p2);
    void set_point_3(_vertex3f p3);


};

#endif // TRIANGLE_H
