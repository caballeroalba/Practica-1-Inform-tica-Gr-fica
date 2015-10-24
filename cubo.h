#ifndef CUBO_H
#define CUBO_H
#include <vertex.h>


class Cubo
{
private:

    _vertex3f Vertex_1;
    _vertex3f Vertex_2;
    _vertex3f Vertex_3;
    _vertex3f Vertices[8];
    int Edges[12][2];
    int CarasC[12][3];





public:

     Cubo();
    void set_vertices(_vertex3f Vertices[]);
    _vertex3f get_vertices();
    void dibuja_cubo(int modo);
    void dibuja_cubo_puntos();
    void dibuja_cubo_aristas();
    void dibuja_cubo_solido();
    void dibuja_cubo_ajedrez();
    void dibuja_cubo_todo();




};

#endif // CUBO_H
