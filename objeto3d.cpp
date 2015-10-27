#include "objeto3d.h"
#include <GL/glut.h>

Objeto3D::Objeto3D()
{

}

void Objeto3D::dibuja(int modo){

       if(modo == 0){
           dibuja_puntos();
       }else if (modo==1){
           dibuja_aristas();
       }else if (modo==2){
           dibuja_solido();
       }else if (modo==3){
           dibuja_ajedrez();
       }else if (modo ==4){
           dibuja_todo();
       }

}


void Objeto3D::dibuja_puntos(){

    glBegin(GL_POINTS);
    int i;
    for (i=0;i<Vertices.size(); i++){

        glVertex3f(Vertices[i].x,Vertices[i].y,Vertices[i].z);
        }
    glEnd();


}

void Objeto3D::dibuja_aristas(){

    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

    glColor3f(255,2,0);
    glBegin(GL_TRIANGLES);
    for (int i=0; i<Edges.size(); i++){


         Edge ed=Edges[i];
         Vertex_1 = ed.get_point_1();
         Vertex_2 = ed.get_point_2();
         Vertex_3 = ed.get_point_3();

        glVertex3f(Vertex_1.x,Vertex_1.y,Vertex_1.z);
        glVertex3f(Vertex_2.x,Vertex_2.y,Vertex_2.z);
         glVertex3f(Vertex_3.x,Vertex_3.y,Vertex_3.z);
    }
    glEnd();


}

void Objeto3D::dibuja_solido(){


    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

    glColor3f(0,2,0);
    glBegin(GL_TRIANGLES);
    for (int i=0; i<CarasC.size(); i++){

         Triangle t= CarasC[i];
         Vertex_1 = t.get_point_1();
         Vertex_2 = t.get_point_2();
         Vertex_3 = t.get_point_3();

        glVertex3f(Vertex_1.x,Vertex_1.y,Vertex_1.z);
        glVertex3f(Vertex_2.x,Vertex_2.y,Vertex_2.z);
         glVertex3f(Vertex_3.x,Vertex_3.y,Vertex_3.z);
    }
    glEnd();



}

void Objeto3D::dibuja_ajedrez(){

}

void Objeto3D::dibuja_todo(){


}

void Objeto3D::set_vertices(vector<_vertex3f> Vertices){

    this->Vertices=Vertices;
}

void Objeto3D::set_caras(vector<Triangle> CarasC){

    this->CarasC=CarasC;

}
