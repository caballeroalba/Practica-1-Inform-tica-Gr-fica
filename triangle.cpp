#include "triangle.h"

Triangle::Triangle()
{

}

void Triangle::set_point_1(_vertex3f p1){
    this->p1=p1;
}

void Triangle::set_point_2(_vertex3f p2){

    this->p2=p2;
}

void Triangle::set_point_3(_vertex3f p3){
    this->p3=p3;
}

_vertex3f Triangle::get_point_1(){

    return p1;

}

_vertex3f Triangle::get_point_2(){

    return p2;

}

_vertex3f Triangle::get_point_3(){

    return p3;

}
