#include "figurarevolucion.h"

figuraRevolucion::figuraRevolucion(int n, char *Ruta)
{


    //primero rellenamos los vertices iniciales en q1

    carga_fichero_ply(Ruta);
    VerticesQ1=Vertices;

}


