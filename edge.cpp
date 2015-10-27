#include "edge.h"

Edge::Edge()
{

}


void Edge::set_point_1(_vertex3f p1){
    this->p1=p1;
}

void Edge::set_point_2(_vertex3f p2){

    this->p2=p2;
}

void Edge::set_point_3(_vertex3f p3){
    this->p3=p3;
}

_vertex3f Edge::get_point_1(){

    return this->p1;

}

_vertex3f Edge::get_point_2(){

    return this->p2;

}

_vertex3f Edge::get_point_3(){

    return this->p3;

}
