#include "tetraedro.h"
#include <GL/glut.h>


Tetraedro::Tetraedro()
{



    //Tetraedro
          GLfloat VerticesTe[4][3]={{2,-1,1},{-2,-1,1},{0,-1,-2},{0,2,0}};





              int i;
              _vertex3f Vertex2;
              for (i=0; i<4; i++){

                  Vertex2.x=VerticesTe[i][0];
                  Vertex2.y=VerticesTe[i][1];
                  Vertex2.z=VerticesTe[i][2];

                  VerticesT[i]=Vertex2;


              }


             //aristas;

             EdgesT[0][0]=0;
             EdgesT[0][1]=1;
             EdgesT[1][0]=0;
             EdgesT[1][1]=2;
             EdgesT[2][0]=1;
             EdgesT[2][1]=2;
             EdgesT[3][0]=0;
             EdgesT[3][1]=3;
             EdgesT[4][0]=1;
             EdgesT[4][1]=3;
             EdgesT[5][0]=2;
             EdgesT[5][1]=3;
      // Caras (con triangulos)



             Caras[0][0]=0;
             Caras[0][1]=1;
             Caras[0][2]=3;
             Caras[1][0]=0;
             Caras[1][1]=2;
             Caras[1][2]=3;
             Caras[2][0]=1;
             Caras[2][1]=2;
             Caras[2][2]=3;
             Caras[3][0]=0;
             Caras[3][1]=1;
             Caras[3][2]=2;

}


void Tetraedro::dibuja_tetraedro(int modo){


    if( modo == 0){
        dibuja_tetraedro_puntos();
    }else if (modo == 1){

        dibuja_tetraedro_aristas();
    }else if (modo == 2){

        dibuja_tetraedro_solido();
    } else if (modo == 3){

        dibuja_tetraedro_ajedrez();
    }else if ( modo== 4){

        dibuja_tetraedro_todo();
    }


}

void Tetraedro::dibuja_tetraedro_puntos(){

    glBegin(GL_POINTS);
    int i;
    for (i=0;i<4;i++){

        glVertex3f(VerticesT[i].x,VerticesT[i].y,VerticesT[i].z);
        }
    glEnd();
}

void Tetraedro::dibuja_tetraedro_aristas(){

    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

    glBegin(GL_TRIANGLES);
    for (int i=0; i<4; i++){

         Vertex_1 = VerticesT[Caras[i][0]];
         Vertex_2 = VerticesT[Caras[i][1]];
         Vertex_3 = VerticesT[Caras[i][2]];

        glVertex3f(Vertex_1.x,Vertex_1.y,Vertex_1.z);
        glVertex3f(Vertex_2.x,Vertex_2.y,Vertex_2.z);
         glVertex3f(Vertex_3.x,Vertex_3.y,Vertex_3.z);
    }
    glEnd();
}

void Tetraedro::dibuja_tetraedro_solido(){

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

    glColor3f(0,2,0);
    glBegin(GL_TRIANGLES);
    for (int i=0; i<4; i++){

         Vertex_1 = VerticesT[Caras[i][0]];
         Vertex_2 = VerticesT[Caras[i][1]];
         Vertex_3 = VerticesT[Caras[i][2]];

        glVertex3f(Vertex_1.x,Vertex_1.y,Vertex_1.z);
        glVertex3f(Vertex_2.x,Vertex_2.y,Vertex_2.z);
         glVertex3f(Vertex_3.x,Vertex_3.y,Vertex_3.z);
    }
    glEnd();
}


void Tetraedro::dibuja_tetraedro_ajedrez(){

    glBegin(GL_TRIANGLES);
    for (int i=0; i<4; i++){
         if (i % 2 == 0)
             glColor3f(0,2,0);

         else
             glColor3f(1,8,0);

         Vertex_1 = VerticesT[Caras[i][0]];
         Vertex_2 = VerticesT[Caras[i][1]];
         Vertex_3 = VerticesT[Caras[i][2]];

        glVertex3f(Vertex_1.x,Vertex_1.y,Vertex_1.z);
        glVertex3f(Vertex_2.x,Vertex_2.y,Vertex_2.z);
         glVertex3f(Vertex_3.x,Vertex_3.y,Vertex_3.z);
    }
    glEnd();
}

void Tetraedro::dibuja_tetraedro_todo(){

    glColor3f(255,0,0);
    dibuja_tetraedro_puntos();
    dibuja_tetraedro_aristas();
    dibuja_tetraedro_solido();
}
