#ifndef FIGURAPLY_H
#define FIGURAPLY_H
#include "objeto3d.h"
#include "file_ply_stl.h"

class FiguraPLy : public Objeto3D
{

private:
    vector<float> Vertices;
    vector<int> faces;
    _file_ply fply;
    vector<_vertex3f> listaV;
    vector<Triangle> listaC;
    void carga_datos_ply();

public:
    FiguraPLy();
    bool carga_fichero_ply(char *Ruta);
    void dibuja_fichero_ply();



};

#endif // FIGURAPLY_H
