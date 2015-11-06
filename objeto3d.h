#ifndef OBJETO3D_H
#define OBJETO3D_H
#include "vertex.h"
#include <vector>
#include <edge.h>
#include <triangle.h>

class Objeto3D
{
private:
    _vertex3f Vertex_1;
    _vertex3f Vertex_2;
    _vertex3f Vertex_3;
    vector<_vertex3f> Vertices;
    vector<Edge> Edges;
    vector<Triangle> CarasC;



public:
    Objeto3D();
    void set_vertices(vector<_vertex3f> Vertices);
    void set_caras(vector<Triangle> CarasC);
    void set_Edges(vector<Edge> Edges);
    vector<_vertex3f> get_vertices();
    void dibuja(int modo);
    void dibuja_puntos();
    void dibuja_aristas();
    void dibuja_solido();
    void dibuja_ajedrez();
    void dibuja_todo();
    void clear_vertices();


};

#endif // OBJETO3D_H
