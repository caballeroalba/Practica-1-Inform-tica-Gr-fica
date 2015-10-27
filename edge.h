#ifndef EDGE_H
#define EDGE_H
#include "vertex.h"


class Edge
{

private:
    _vertex3f p1;
    _vertex3f p2;
    _vertex3f p3;
public:
    Edge();
    _vertex3f get_point_1();
    _vertex3f get_point_2();
    _vertex3f get_point_3();
    void set_point_1(_vertex3f p1);
    void set_point_2(_vertex3f p2);
    void set_point_3(_vertex3f p3);

};

#endif // EDGE_H
