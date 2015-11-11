#ifndef FIGURAREVOLUCION_H
#define FIGURAREVOLUCION_H
#include "figuraply.h"
#include "math.h"


class figuraRevolucion : public FiguraPLy
{
private:
    int numeroRevoluciones;
    double grados;
    double gradosARev;
    vector<_vertex3f> VerticesQ1;
    vector<_vertex3f> VerticesFinales;


public:
    figuraRevolucion();
    figuraRevolucion(int numRev, double gradosARev);
    void setRevoluciones(int n);
    void calculaPuntosDesdePerfilQ1();
    bool carga_fichero_ply(char *Ruta);
    _vertex3f rotaPorEjeYMatricial(_vertex3f vertice);
    void dibuja_perfil(int modo);
    void set_perfil();
    vector<_vertex3f> getPefilQ1();





};

#endif // FIGURAREVOLUCION_H
