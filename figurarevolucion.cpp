#include "figurarevolucion.h"

figuraRevolucion::figuraRevolucion()
{


    //primero rellenamos los vertices iniciales en q1
    grados=30;



}

bool figuraRevolucion::carga_fichero_ply(char *Ruta){

    int result=this->fply.open(Ruta);


    if (result == 0){
        carga_datos_ply();
         VerticesQ1=get_vertices();
        return true;
    }else{
        return false;
    }



}



void figuraRevolucion::setRevoluciones(int n){
    this->numeroRevoluciones=n;
}


void figuraRevolucion::calculaPuntosDesdePerfilQ1(int revoluciones){

    //Según las revoluciones, calculamos los puntos en
    //vector de puntos finales Vertices.

    //primero lo borramos, como es una var privada, lo hacemos así:


    //clear_vertices();

    // y ahora aplicamos las transformaciones para almacenar los vertices de la revolución
    // Qj = Q1RY (αj), con j = 1,...,N
    //vector de vectores de los distintos perfiles
    vector<vector<_vertex3f> > perfilesAlmacenados;
    vector<_vertex3f> perfilActual;
    vector<_vertex3f> perfilAux;
    for (int i=0; i<revoluciones; i++){


        //primera vez
        if(perfilesAlmacenados.empty()){
            perfilActual=get_vertices();
        }

        for (int j=0; j<perfilActual.size(); j++){
            _vertex3f verticeActual;

            verticeActual=rotaPorEjeYMatricial(perfilActual[j]);
            perfilAux.push_back(verticeActual);


        }

        perfilesAlmacenados.push_back(perfilAux);

        perfilActual=perfilAux;

        perfilAux.clear();

        }


    //cargamos todos los vertices almacenados en perfilesAlmacenados en vertices
    vector<_vertex3f> verticesNuevos;
    vector<_vertex3f> perfil;
    for (int i=0; i<perfilesAlmacenados.size(); i++){
        perfil=perfilesAlmacenados[i];
        for (int j=0; j<perfil.size(); j++){

            verticesNuevos.push_back(perfil[j]);
        }

    }
    //asignamos al objeto actual los vertices revolucionarios

    set_vertices(verticesNuevos);

    /*ahora debemos de calcular las caras del objeto según la formula siguiente:
    Las caras longitudinales del sólido (triángulos) se crean a partir de los vértices de dos
    perfiles consecutivos Qj y Qj+1. Tomando dos puntos adyacentes en cada uno de los
    dos perfiles Qj y Qj+1 y estando dichos puntos a la misma altura, se pueden crear
    dos triángulos. En la figura 2.3(a) se muestran los triángulos así obtenidos solamente
    para un lado longitudinal para una mejor visualización. Los vértices de los triángulos
    tienen que estar ordenados en el sentido contrario a las agujas del reloj.
    */
    vector<Triangle> caras;

    for (int i=0; i<=perfilesAlmacenados.size()-2; i++){

        Triangle cara1;
        Triangle cara2;

        for (int j=0; j<perfilesAlmacenados[i].size()-2; j++){

            cara1.set_point_1(perfilesAlmacenados[i][j]);
            cara1.set_point_2(perfilesAlmacenados[i][j+1]);
            cara1.set_point_3(perfilesAlmacenados[i+1][j]);
            cara2.set_point_1(perfilesAlmacenados[i+1][j]);
            cara2.set_point_2(perfilesAlmacenados[i+1][j+1]);
            cara2.set_point_3(perfilesAlmacenados[i][j+1]);
            caras.push_back(cara1);
            caras.push_back(cara2);

        }




    }
    set_caras(caras);
}

//hay que pasarlo a una matriz de 4x4 o hacer una clase transformaciones
//que implemente todas las transformaciones

_vertex3f figuraRevolucion::rotaPorEjeYMatricial(_vertex3f vertice){


    _vertex3f result;

    double grados2 = gradosARadianes(grados);
    result.x=vertice.x*cos(grados2)+vertice.y*0+vertice.z*sin(grados2);
    result.y=vertice.y;
    result.z=vertice.x*-sin(grados2)+vertice.y*0+vertice.z*cos(grados2);
    return result;

}
