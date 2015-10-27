#include "cubo.h"
#include <GL/glut.h>




Cubo::Cubo()
{

    //vectores




    //Cubo
    GLfloat VerticesCubo[8][3]={{-2,2,2},{2,2,2},{-2,-2,2},{2,-2,2},{-2,2,-2},{2,2,-2},{-2,-2,-2},{2,-2,-2}};



    vector<_vertex3f> listaV;
    _vertex3f Vertex1;
    int i;
    for (i=0; i<8; i++){
        Vertex1.x=VerticesCubo[i][0];
        Vertex1.y=VerticesCubo[i][1];
        Vertex1.z=VerticesCubo[i][2];
        listaV.insert(listaV.begin(),Vertex1);
       // Vertices[i]=Vertex1;

    }
    this->set_vertices(listaV);
    //Aristas

   // int Edgess[8][2];

    int Edgess[11][2];
    Edgess[0][0]=0;
    Edgess[0][1]=1;

    Edgess[1][0]=0;
    Edgess[1][1]=2;

    Edgess[2][0]=2;
    Edgess[2][1]=3;

    Edgess[3][0]=1;
    Edgess[3][1]=3;

    Edgess[4][0]=0;
    Edgess[4][1]=4;

    Edgess[5][0]=4;
    Edgess[5][1]=5;


    Edgess[6][0]=5;
    Edgess[6][1]=7;


    Edgess[7][0]=6;
    Edgess[7][1]=7;

    Edgess[8][0]=4;

    Edgess[8][1]=6;


    Edgess[9][0]=2;
    Edgess[9][1]=6;

    Edgess[10][0]=1;
    Edgess[10][1]=5;

    Edgess[11][0]=3;
    Edgess[11][1]=7;
     vector<Edge> lista;
    for (int i=0; i<=11; i++){

        _vertex3f v1;
        _vertex3f v2;

        Edge e;

        e.set_point_1(v1);
        e.set_point_2(v2);
        lista.insert(lista.begin(),e);


    }
    this->set_Edges(lista);
    //caras
   int  arrayCaras[11][3];
    arrayCaras[0][0]=0;
    arrayCaras[0][1]=1;
    arrayCaras[0][2]=2;

    arrayCaras[1][0]=1;
    arrayCaras[1][1]=2;
    arrayCaras[1][2]=3;

    arrayCaras[2][0]=4;
    arrayCaras[2][1]=5;
    arrayCaras[2][2]=6;

    arrayCaras[3][0]=5;
    arrayCaras[3][1]=6;
    arrayCaras[3][2]=7;

    arrayCaras[4][0]=0;
    arrayCaras[4][1]=4;
    arrayCaras[4][2]=5;

    arrayCaras[5][0]=5;
    arrayCaras[5][1]=1;
    arrayCaras[5][2]=0;

    arrayCaras[6][0]=1;
    arrayCaras[6][1]=5;
    arrayCaras[6][2]=3;

    arrayCaras[7][0]=5;
    arrayCaras[7][1]=7;
    arrayCaras[7][2]=3;

    arrayCaras[8][0]=0;
    arrayCaras[8][1]=4;
    arrayCaras[8][2]=6;

    arrayCaras[9][0]=2;
    arrayCaras[9][1]=0;
    arrayCaras[9][2]=6; //4


    arrayCaras[10][0]=6;
    arrayCaras[10][1]=7;
    arrayCaras[10][2]=2;

    arrayCaras[11][0]=7;
    arrayCaras[11][1]=3;
    arrayCaras[11][2]=2;

    vector<Triangle> listaT;
    for (int i=0; i<=11; i++){

        _vertex3f v1;
        _vertex3f v2;
        _vertex3f v3;

        Triangle aux;
        vector<_vertex3f> lVertices=get_vertices();
        aux.set_point_1(lVertices[arrayCaras[i][0]]);
        aux.set_point_2(lVertices[arrayCaras[i][1]]);
        aux.set_point_3(lVertices[arrayCaras[i][2]]);
        listaT.insert(listaT.begin(),aux);

    }
    set_caras(listaT);
}





