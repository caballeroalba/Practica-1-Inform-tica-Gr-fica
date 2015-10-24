#ifndef TETRAEDRO_H
#define TETRAEDRO_H
#include <GL/glut.h>
#include "vertex.h"

class Tetraedro
{
private:

    _vertex3f Vertex_1;
    _vertex3f Vertex_2;
    _vertex3f Vertex_3;
    _vertex3f VerticesT[4];
    int EdgesT[6][2];
    int Caras[4][3];


public:

    Tetraedro();
    void set_vertices(_vertex3f Vertices[]);
    _vertex3f get_vertices();
    void dibuja_tetraedro(int modo);
    void dibuja_tetraedro_puntos();
    void dibuja_tetraedro_aristas();
    void dibuja_tetraedro_solido();
    void dibuja_tetraedro_ajedrez();
    void dibuja_tetraedro_todo();
};

#endif // TETRAEDRO_H
