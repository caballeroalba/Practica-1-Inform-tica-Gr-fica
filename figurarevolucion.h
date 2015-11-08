#ifndef FIGURAREVOLUCION_H
#define FIGURAREVOLUCION_H
#include "figuraply.h"
#include "math.h"


class figuraRevolucion : public FiguraPLy
{
private:
    int numeroRevoluciones;
    int grados;
    vector<_vertex3f> VerticesQ1;
    vector<_vertex3f> VerticesFinales;


public:
    figuraRevolucion();
    void setRevoluciones(int n);
    void calculaPuntosDesdePerfilQ1(int revoluciones);
    bool carga_fichero_ply(char *Ruta);
    _vertex3f rotaPorEjeYMatricial(_vertex3f vertice);
    void dibuja_perfil(int modo);
    vector<_vertex3f> getPefilQ1();





};

#endif // FIGURAREVOLUCION_H
