#ifndef FIGURAPLY_H
#define FIGURAPLY_H
#include "objeto3d.h"
#include "file_ply_stl.h"

class FiguraPLy : public Objeto3D
{

private:
    vector<float> Vertices;
    vector<int> faces;

    vector<_vertex3f> listaV;
    vector<Triangle> listaC;


public:
    FiguraPLy();
     _file_ply fply;
     void carga_datos_ply();
    bool carga_fichero_ply(char *Ruta);
    void dibuja_fichero_ply();
    double gradosARadianes(double angulo){return angulo*(M_PI/180);}




};

#endif // FIGURAPLY_H
