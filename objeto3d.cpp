﻿#include "objeto3d.h"
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

    glColor3f(255,0,0);
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

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

    glColor3f(0,2,0);
    glBegin(GL_TRIANGLES);
    for (int i=0; i<CarasC.size(); i++){

        if(i % 2 == 0)
            glColor3f(0,2,0);
        else
            glColor3f(9,0,0);

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

void Objeto3D::dibuja_todo(){

    dibuja_puntos();
    dibuja_aristas();
    dibuja_solido();


}

void Objeto3D::set_vertices(vector<_vertex3f> Vertices){

    this->Vertices=Vertices;
}

void Objeto3D::set_caras(vector<Triangle> CarasC){

    this->CarasC=CarasC;

}

void Objeto3D::set_Edges(vector<Edge> Edges){

    this->Edges=Edges;
}
vector<_vertex3f> Objeto3D::get_vertices(){

    return Vertices;
}

void Objeto3D::clear_vertices(){

    this->Vertices.clear();
}


void Objeto3D::add_single_vertex(_vertex3f vertice){

    Vertices.push_back(vertice);
}
