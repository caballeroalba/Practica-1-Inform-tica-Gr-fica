#include "tetraedro.h"
#include <GL/glut.h>
#include <vector>


Tetraedro::Tetraedro()
{



    //Tetraedro
          GLfloat VerticesTe[4][3]={{2,-1,1},{-2,-1,1},{0,-1,-2},{0,2,0}};






              vector<_vertex3f> listaV;
              _vertex3f Vertex1;
              int i;
              for (i=0; i<=3; i++){
                  Vertex1.x=VerticesTe[i][0];
                  Vertex1.y=VerticesTe[i][1];
                  Vertex1.z=VerticesTe[i][2];
                  listaV.insert(listaV.begin(),Vertex1);
                 // Vertices[i]=Vertex1;

              }
              this->set_vertices(listaV);


             //aristas;
             int EdgesT[6][2];
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


             int Caras[4][3];
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

             vector<Triangle> listaT;
             for (int i=0; i<=3; i++){

                 _vertex3f v1;
                 _vertex3f v2;
                 _vertex3f v3;
                 Triangle aux;
                 vector<_vertex3f> lVertices=get_vertices();

                 aux.set_point_1(lVertices[Caras[i][0]]);
                 aux.set_point_2(lVertices[Caras[i][1]]);
                 aux.set_point_3(lVertices[Caras[i][2]]);
                 listaT.insert(listaT.begin(),aux);

             }
             this->set_caras(listaT);

}


