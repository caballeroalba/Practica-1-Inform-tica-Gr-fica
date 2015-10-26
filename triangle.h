#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <GL/glut.h>

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


};

#endif // TRIANGLE_H
