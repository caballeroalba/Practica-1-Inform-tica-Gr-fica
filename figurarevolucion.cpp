
#include "figurarevolucion.h"

figuraRevolucion::figuraRevolucion()
{



    //grados por defecto en constructor normal
    grados=30;



}

figuraRevolucion::figuraRevolucion(int numRev, double gradosARev, double gradosInicial){

    // se han de calcular los grados en función del numero de divisiones y total de grados a rotar
    //ej: Revolucionar 9 grados con 10 divisiones, pues los grados son: 90/10= 9º
    grados=gradosARev/numRev;
    numeroRevoluciones=numRev;
    this->gradosARev=gradosARev;
    this->gradosInical=gradosInicial;

}

vector<_vertex3f> figuraRevolucion::getPefilQ1(){
    return VerticesQ1;
}

void figuraRevolucion::dibuja_perfil(int modo){
    vector<_vertex3f> aux=getPefilQ1();
    set_vertices(aux);
    dibuja(modo);

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


void figuraRevolucion::set_perfil(){
    clear_vertices();
    set_vertices(getPefilQ1());
}

void figuraRevolucion::setRevoluciones(int n){
    this->numeroRevoluciones=n;
}


void figuraRevolucion::calculaPuntosDesdePerfilQ1(){
    //movemos al grado inicial en el que nos piden

     vector<_vertex3f> grados_inicial;
     grados_inicial=get_vertices();
     vector<_vertex3f> grados_aux;

     _vertex3f punto;
     _vertex3f puntoaux;

     for (int i=0; i<grados_inicial.size(); i++){

         punto = rotaPorEjeYMatricialInicial(grados_inicial[i]);
         grados_aux.push_back(punto);
     }
     set_vertices(grados_aux);
     VerticesQ1=get_vertices();

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
    double cuenta;
    for (int i=0; i<=numeroRevoluciones; i++){

        if(cuenta>=gradosARev)
            continue;
        //primera vez
        if(perfilesAlmacenados.empty()){
            perfilActual=get_vertices();
            //y añadimos el perfil q1 al principio
            perfilesAlmacenados.push_back(getPefilQ1());
        }

        for (int j=0; j<perfilActual.size(); j++){
            _vertex3f verticeActual;

            verticeActual=rotaPorEjeYMatricial(perfilActual[j]);
            perfilAux.push_back(verticeActual);


        }

        perfilesAlmacenados.push_back(perfilAux);

        perfilActual=perfilAux;

        perfilAux.clear();
        cuenta+=grados;

        }


    //cargamos todos los vertices almacenados en perfilesAlmacenados en vertices
    vector<_vertex3f> verticesNuevos;
    vector<_vertex3f> perfil;
    //primero añadimos el los vertices q1 antes al principio a vertices nuevos

    for (int i=0; i<getPefilQ1().size(); i++){
        verticesNuevos.push_back(getPefilQ1()[i]);
    }
    for (int i=0; i<perfilesAlmacenados.size(); i++){
        perfil=perfilesAlmacenados[i];
        for (int j=0; j<perfil.size(); j++){

            verticesNuevos.push_back(perfil[j]);
        }

    }
    //asignamos al objeto actual los vertices revolucionarios

    //set_vertices(verticesNuevos);

    /*ahora debemos de calcular las caras del objeto según la formula siguiente:
    Las caras longitudinales del sólido (triángulos) se crean a partir de los vértices de dos
    perfiles consecutivos Qj y Qj+1. Tomando dos puntos adyacentes en cada uno de los
    dos perfiles Qj y Qj+1 y estando dichos puntos a la misma altura, se pueden crear
    dos triángulos. En la figura 2.3(a) se muestran los triángulos así obtenidos solamente
    para un lado longitudinal para una mejor visualización. Los vértices de los triángulos
    tienen que estar ordenados en el sentido contrario a las agujas del reloj.
    */
    vector<Triangle> caras;

    for (int i=0; i<perfilesAlmacenados.size()-1; i++){

        Triangle cara1;
        Triangle cara2;

        for (int j=0; j<perfilesAlmacenados[i].size()-1; j++){
            if(j==perfilesAlmacenados.size())
                continue;
            if(j==perfilesAlmacenados[i].size())
                continue;

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
/*
    //ahora añadimos la cara superior e inferior añadiendo dos vertices al principio
    //y al final a la altura del ultimo y primero punto y añadimos los triangulos a este.

    //añadimos los 2 vertices
    _vertex3f v1;
    v1.x=0;
    v1.y=VerticesQ1[0].y;
    v1.z=0;

    _vertex3f v2;
    v2.x=0;
    v2.y=VerticesQ1[VerticesQ1.size()-1].y;
    v2.z=0;

    //los añadimos

    add_single_vertex(v1);
    add_single_vertex(v2);

    // y ahora creamos los trianglulos en torno a a v1 y v2

    //parte baja (v1)
    for (int i=0; i<revoluciones-1; i++){

        Triangle t1;
        t1.set_point_1(perfilesAlmacenados[i][0]);
        t1.set_point_2(perfilesAlmacenados[i+1][0]);
        t1.set_point_3(v1);
        caras.push_back(t1);
    }

    //parte alta (v2)

    for (int i=0; i<revoluciones-1; i++){

        Triangle t1;
        int position= perfilesAlmacenados[i].size();
        t1.set_point_1(perfilesAlmacenados[i][position-1]);
        t1.set_point_2(perfilesAlmacenados[i+1][position-1]);
        t1.set_point_3(v2);
        caras.push_back(t1);
    }

    */
    set_vertices(verticesNuevos);
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

_vertex3f figuraRevolucion::rotaPorEjeYMatricialInicial(_vertex3f vertice){
    _vertex3f result;

    double grados2 = gradosARadianes(gradosInical);

    result.x=vertice.x*cos(grados2)+vertice.y*0+vertice.z*sin(grados2);
    result.y=vertice.y;
    result.z=vertice.x*-sin(grados2)+vertice.y*0+vertice.z*cos(grados2);
    return result;

}
