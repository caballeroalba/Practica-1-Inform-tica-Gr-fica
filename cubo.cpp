#include "cubo.h"
#include <GL/glut.h>




Cubo::Cubo()
{

    //vectores




    //Cubo
    GLfloat VerticesCubo[8][3]={{-2,2,2},{2,2,2},{-2,-2,2},{2,-2,2},{-2,2,-2},{2,2,-2},{-2,-2,-2},{2,-2,-2}};




    _vertex3f Vertex1;
    int i;
    for (i=0; i<8; i++){
        Vertex1.x=VerticesCubo[i][0];
        Vertex1.y=VerticesCubo[i][1];
        Vertex1.z=VerticesCubo[i][2];

        Vertices[i]=Vertex1;

    }

    //Aristas

   // int Edges[8][2];


    Edges[0][0]=0;
    Edges[0][1]=1;

    Edges[1][0]=0;
    Edges[1][1]=2;

    Edges[2][0]=2;
    Edges[2][1]=3;

    Edges[3][0]=1;
    Edges[3][1]=3;

    Edges[4][0]=0;
    Edges[4][1]=4;

    Edges[5][0]=4;
    Edges[5][1]=5;


    Edges[6][0]=5;
    Edges[6][1]=7;


    Edges[7][0]=6;
    Edges[7][1]=7;

    Edges[8][0]=4;_vertex3f Vertex_1;
    _vertex3f Vertex_2;
    _vertex3f Vertex_3;

    Edges[8][1]=6;


    Edges[9][0]=2;
    Edges[9][1]=6;

    Edges[10][0]=1;
    Edges[10][1]=5;

    Edges[11][0]=3;
    Edges[11][1]=7;


    //caras

    CarasC[0][0]=0;
    CarasC[0][1]=1;
    CarasC[0][2]=2;

    CarasC[1][0]=1;
    CarasC[1][1]=2;
    CarasC[1][2]=3;

    CarasC[2][0]=4;
    CarasC[2][1]=5;
    CarasC[2][2]=6;

    CarasC[3][0]=5;
    CarasC[3][1]=6;
    CarasC[3][2]=7;

    CarasC[4][0]=0;
    CarasC[4][1]=4;
    CarasC[4][2]=5;

    CarasC[5][0]=5;
    CarasC[5][1]=1;
    CarasC[5][2]=0;

    CarasC[6][0]=1;
    CarasC[6][1]=5;
    CarasC[6][2]=3;

    CarasC[7][0]=5;
    CarasC[7][1]=7;
    CarasC[7][2]=3;

    CarasC[8][0]=0;
    CarasC[8][1]=4;
    CarasC[8][2]=6;

    CarasC[9][0]=2;
    CarasC[9][1]=0;
    CarasC[9][2]=6; //4


    CarasC[10][0]=6;
    CarasC[10][1]=7;
    CarasC[10][2]=2;

    CarasC[11][0]=7;
    CarasC[11][1]=3;
    CarasC[11][2]=2;

}

void Cubo::dibuja_cubo(int modo){

    if( modo == 0){
        dibuja_cubo_puntos();
    }else if (modo == 1){

        dibuja_cubo_aristas();
    }else if (modo == 2){

        dibuja_cubo_solido();
    } else if (modo == 3){

        dibuja_cubo_ajedrez();
    }else if ( modo== 4){

        dibuja_cubo_todo();
    }



}

void Cubo::dibuja_cubo_puntos(){
    glBegin(GL_POINTS);
    int i;
    for (i=0;i<8;i++){

        glVertex3f(Vertices[i].x,Vertices[i].y,Vertices[i].z);
        }
    glEnd();

}


void Cubo::dibuja_cubo_aristas(){


    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

    glColor3f(255,2,0);
    glBegin(GL_TRIANGLES);
    for (int i=0; i<12; i++){

         Vertex_1 = Vertices[CarasC[i][0]];
         Vertex_2 = Vertices[CarasC[i][1]];
         Vertex_3 = Vertices[CarasC[i][2]];

        glVertex3f(Vertex_1.x,Vertex_1.y,Vertex_1.z);
        glVertex3f(Vertex_2.x,Vertex_2.y,Vertex_2.z);
         glVertex3f(Vertex_3.x,Vertex_3.y,Vertex_3.z);
    }
    glEnd();

}

void Cubo::dibuja_cubo_solido(){


    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

    glColor3f(0,2,0);
    glBegin(GL_TRIANGLES);
    for (int i=0; i<12; i++){

         Vertex_1 = Vertices[CarasC[i][0]];
         Vertex_2 = Vertices[CarasC[i][1]];
         Vertex_3 = Vertices[CarasC[i][2]];

        glVertex3f(Vertex_1.x,Vertex_1.y,Vertex_1.z);
        glVertex3f(Vertex_2.x,Vertex_2.y,Vertex_2.z);
         glVertex3f(Vertex_3.x,Vertex_3.y,Vertex_3.z);
    }
    glEnd();
}

void Cubo::dibuja_cubo_ajedrez(){
    glBegin(GL_TRIANGLES);
    for (int i=0; i<12; i++){

        if (i % 2 == 0)
            glColor3f(0,2,0);

        else
            glColor3f(1,8,0);

         Vertex_1 = Vertices[CarasC[i][0]];
         Vertex_2 = Vertices[CarasC[i][1]];
         Vertex_3 = Vertices[CarasC[i][2]];

        glVertex3f(Vertex_1.x,Vertex_1.y,Vertex_1.z);
        glVertex3f(Vertex_2.x,Vertex_2.y,Vertex_2.z);
         glVertex3f(Vertex_3.x,Vertex_3.y,Vertex_3.z);
    }
    glEnd();

}

void Cubo::dibuja_cubo_todo(){

    glColor3f(255,0,0);
    dibuja_cubo_puntos();

    dibuja_cubo_aristas();
    dibuja_cubo_solido();
}




