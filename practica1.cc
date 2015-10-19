//**************************************************************************
// Práctica 1
//
// Domingo Martin Perandres 2013-2016
//
// GPL
//**************************************************************************

#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include <vertex.h>
#include <unistd.h>



void modo_triangulo();


// tamaño de los ejes
const int AXIS_SIZE=5000;


// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Window_width,Window_height,Front_plane,Back_plane;

// variables que determninan la posicion y tamaño de la ventana X
int UI_window_pos_x=50,UI_window_pos_y=50,UI_window_width=900,UI_window_height=900;



//var para determinar el objeto, tetraedro o cubo

// 0 = cubo
// 1 = tetra

int objeto=1;

// var para determinar el tipo de dibujado, puntos, trianglulos, etc.

// 0 = puntos
// 1 = alambre
// 2 = solido
// 3 = ajedrez

int modo=0;

_vertex3f Vertex;

_vertex2i Edge;


//variables del cubo

_vertex3f Verticess[8];
int Edges[12][2];
int CarasC[12][3];



//Variables del tetraedro

_vertex3f VerticesT[4];
int EdgesT[6][2];
int Caras[4][3];


//variables globales de  los puntos

_vertex3f Vertex_1;
_vertex3f Vertex_2;
_vertex3f Vertex_3;


void cambio_objeto(){

    if(objeto==0) //cambio a tetra
        objeto=1;

    else if(objeto == 1) //cambio a cubo
            objeto=0;


}




void modo_alambre(){


}

void modo_ajedrez(){


}

void modo_puntos(){


}

void cambio_modo(unsigned char Tecla1){

    if (toupper(Tecla1)=='S')//solido
        modo=2;
    if(toupper(Tecla1)=='P') //puntos
        modo=0;
    if(toupper(Tecla1)=='A') // aristas
        modo=1;
    if(toupper(Tecla1)=='C') //ajedrez
        modo=3;

    if(toupper(Tecla1)=='T') // todo a la vez
        modo=4;


}

void carga_triangulo(){

  //Tetraedro
        GLfloat VerticesTe[4][3]={{2,0,1},{-2,0,1},{0,0,-2},{0,4,0}};





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

void carga_cubo(){

    //vectores

    //Cubo
    GLfloat VerticesCubo[8][3]={{-2,2,2},{2,2,2},{-2,-2,2},{2,-2,2},{-2,2,-2},{2,2,-2},{-2,-2,-2},{2,-2,-2}};




    _vertex3f Vertex1;
    int i;
    for (i=0; i<8; i++){
        Vertex1.x=VerticesCubo[i][0];
        Vertex1.y=VerticesCubo[i][1];
        Vertex1.z=VerticesCubo[i][2];

        Verticess[i]=Vertex1;

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

    Edges[8][0]=4;
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




//**************************************************************************
//
//***************************************************************************

void clear_window()
{

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void change_projection()
{

glMatrixMode(GL_PROJECTION);
glLoadIdentity();

// formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
//  Front_plane>0  Back_plane>PlanoDelantero)
glFrustum(-Window_width,Window_width,-Window_height,Window_height,Front_plane,Back_plane);
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void change_observer()
{

// posicion del observador
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}

//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void draw_axis()
{
glBegin(GL_LINES);
// eje X, color rojo
glColor3f(1,0,0);
glVertex3f(-AXIS_SIZE,0,0);
glVertex3f(AXIS_SIZE,0,0);
// eje Y, color verde
glColor3f(0,1,0);
glVertex3f(0,-AXIS_SIZE,0);
glVertex3f(0,AXIS_SIZE,0);
// eje Z, color azul
glColor3f(0,0,1);
glVertex3f(0,0,-AXIS_SIZE);
glVertex3f(0,0,AXIS_SIZE);
glEnd();
}


//**************************************************************************
// Funcion que dibuja los objetos
//***************************************************************************

void draw_objects()
{



int i=0;

glColor3f(0,1,0);
glPointSize(4);
glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);


    if (objeto == 1){


        if(modo == 2){


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
        } else if (modo ==0){

            glBegin(GL_POINTS);
            for (i=0;i<4;i++){

                glVertex3f(VerticesT[i].x,VerticesT[i].y,VerticesT[i].z);
                }
            glEnd();


        } else if (modo == 1){
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
        } else if (modo == 3){

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
        } else if (modo == 4){



            // modo puntos
            glBegin(GL_POINTS);
            for (i=0;i<4;i++){

                glVertex3f(VerticesT[i].x,VerticesT[i].y,VerticesT[i].z);
                }
            glEnd();


            // modo alambre

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

            glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
            //modo solido
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
    }else if ( objeto == 0){



        if ( modo ==0){
            glBegin(GL_POINTS);
            for (i=0;i<8;i++){

                glVertex3f(Verticess[i].x,Verticess[i].y,Verticess[i].z);
                }
            glEnd();


        } else if ( modo == 1){


            glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

            glBegin(GL_TRIANGLES);
            for (int i=0; i<12; i++){


                 Vertex_1 = Verticess[CarasC[i][0]];
                 Vertex_2 = Verticess[CarasC[i][1]];
                 Vertex_3 = Verticess[CarasC[i][2]];

                glVertex3f(Vertex_1.x,Vertex_1.y,Vertex_1.z);
                glVertex3f(Vertex_2.x,Vertex_2.y,Vertex_2.z);
                 glVertex3f(Vertex_3.x,Vertex_3.y,Vertex_3.z);

                //modo para hacerlo con lineas
               /*  Vertex_1 = Verticess[Edges[i][0]];
                 Vertex_2 = Verticess[Edges[i][1]];

                glVertex3f(Vertex_1.x,Vertex_1.y,Vertex_1.z);
                glVertex3f(Vertex_2.x,Vertex_2.y,Vertex_2.z);
                */
            }
            glEnd();

        } else if ( modo == 2){


            glBegin(GL_TRIANGLES);
            for (int i=0; i<12; i++){

                 Vertex_1 = Verticess[CarasC[i][0]];
                 Vertex_2 = Verticess[CarasC[i][1]];
                 Vertex_3 = Verticess[CarasC[i][2]];

                glVertex3f(Vertex_1.x,Vertex_1.y,Vertex_1.z);
                glVertex3f(Vertex_2.x,Vertex_2.y,Vertex_2.z);
                 glVertex3f(Vertex_3.x,Vertex_3.y,Vertex_3.z);
            }
            glEnd();

        }else if ( modo == 3){



            glBegin(GL_TRIANGLES);
            for (int i=0; i<12; i++){

                if (i % 2 == 0)
                    glColor3f(0,2,0);

                else
                    glColor3f(1,8,0);

                 Vertex_1 = Verticess[CarasC[i][0]];
                 Vertex_2 = Verticess[CarasC[i][1]];
                 Vertex_3 = Verticess[CarasC[i][2]];

                glVertex3f(Vertex_1.x,Vertex_1.y,Vertex_1.z);
                glVertex3f(Vertex_2.x,Vertex_2.y,Vertex_2.z);
                 glVertex3f(Vertex_3.x,Vertex_3.y,Vertex_3.z);
            }
            glEnd();



        }else if (modo == 4){



            //puntos

            glBegin(GL_POINTS);
            for (i=0;i<8;i++){

                glVertex3f(Verticess[i].x,Verticess[i].y,Verticess[i].z);
                }
            glEnd();

            //alambre

            glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

            glBegin(GL_TRIANGLES);
            for (int i=0; i<12; i++){


                 Vertex_1 = Verticess[CarasC[i][0]];
                 Vertex_2 = Verticess[CarasC[i][1]];
                 Vertex_3 = Verticess[CarasC[i][2]];

                glVertex3f(Vertex_1.x,Vertex_1.y,Vertex_1.z);
                glVertex3f(Vertex_2.x,Vertex_2.y,Vertex_2.z);
                 glVertex3f(Vertex_3.x,Vertex_3.y,Vertex_3.z);


            }
            glEnd();

            glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);


            glBegin(GL_TRIANGLES);
            for (int i=0; i<12; i++){

                 Vertex_1 = Verticess[CarasC[i][0]];
                 Vertex_2 = Verticess[CarasC[i][1]];
                 Vertex_3 = Verticess[CarasC[i][2]];

                glVertex3f(Vertex_1.x,Vertex_1.y,Vertex_1.z);
                glVertex3f(Vertex_2.x,Vertex_2.y,Vertex_2.z);
                 glVertex3f(Vertex_3.x,Vertex_3.y,Vertex_3.z);
            }
            glEnd();



        }

    }


/*
//Trapezoid
glVertex3f(-0.7f, -1.5f, -5.0f);
glVertex3f(0.7f, -1.5f, -5.0f);
glVertex3f(0.4f, -0.5f, -5.0f);
glVertex3f(-0.4f, -0.5f, -5.0f);

*/
//glEnd();



}


//**************************************************************************
//
//***************************************************************************

void draw_scene(void)
{

clear_window();
change_observer();
draw_axis();
draw_objects();
glutSwapBuffers();
}



//***************************************************************************
// Funcion llamada cuando se produce un cambio en el tamaño de la ventana
//
// el evento manda a la funcion:
// nuevo ancho
// nuevo alto
//***************************************************************************

void change_window_size(int Ancho1,int Alto1)
{
change_projection();
glViewport(0,0,Ancho1,Alto1);
glutPostRedisplay();
}


//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla normal
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton
//***************************************************************************

void normal_keys(unsigned char Tecla1,int x,int y)
{

if (toupper(Tecla1)=='Q') exit(0);
if (toupper(Tecla1)=='S') cambio_modo(Tecla1);
if (toupper(Tecla1)=='O') cambio_objeto();
if (toupper(Tecla1)=='P') cambio_modo(Tecla1);
if (toupper(Tecla1)=='C') cambio_modo(Tecla1);
if (toupper(Tecla1)=='A') cambio_modo(Tecla1);
if (toupper(Tecla1)=='T') cambio_modo(Tecla1);





}

//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla especial
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton

//***************************************************************************

void special_keys(int Tecla1,int x,int y)
{

switch (Tecla1){
	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
	}
glutPostRedisplay();
}






//***************************************************************************
// Funcion de incializacion
//***************************************************************************

void initialize(void)
{
// se inicalizan la ventana y los planos de corte
Window_width=5;
Window_height=5;
Front_plane=10;
Back_plane=1000;

// se inicia la posicion del observador, en el eje z
Observer_distance=2*Front_plane;
Observer_angle_x=0;
Observer_angle_y=0;

// se indica cual sera el color para limpiar la ventana	(r,v,a,al)
// blanco=(1,1,1,1) rojo=(1,0,0,1), ...
glClearColor(1,1,1,1);

// se habilita el z-bufer
glEnable(GL_DEPTH_TEST);
//
change_projection();
//
glViewport(0,0,UI_window_width,UI_window_height);
}


//***************************************************************************
// Programa principal
//
// Se encarga de iniciar la ventana, asignar las funciones e comenzar el
// bucle de eventos
//***************************************************************************

int main(int argc, char **argv)
{






carga_cubo();

carga_triangulo();
// se llama a la inicialización de glut
glutInit(&argc, argv);

// se indica las caracteristicas que se desean para la visualización con OpenGL
// Las posibilidades son:
// GLUT_SIMPLE -> memoria de imagen simple
// GLUT_DOUBLE -> memoria de imagen doble
// GLUT_INDEX -> memoria de imagen con color indizado
// GLUT_RGB -> memoria de imagen con componentes rojo, verde y azul para cada pixel
// GLUT_RGBA -> memoria de imagen con componentes rojo, verde, azul y alfa para cada pixel
// GLUT_DEPTH -> memoria de profundidad o z-bufer
// GLUT_STENCIL -> memoria de estarcido
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

// posicion de la esquina inferior izquierdad de la ventana
glutInitWindowPosition(UI_window_pos_x,UI_window_pos_y);

// tamaño de la ventana (ancho y alto)
glutInitWindowSize(UI_window_width,UI_window_height);

// llamada para crear la ventana, indicando el titulo (no se visualiza hasta que se llama
// al bucle de eventos)
glutCreateWindow("Práctica 1");

// asignación de la funcion llamada "dibujar" al evento de dibujo
glutDisplayFunc(draw_scene);
// asignación de la funcion llamada "cambiar_tamanio_ventana" al evento correspondiente
glutReshapeFunc(change_window_size);
// asignación de la funcion llamada "tecla_normal" al evento correspondiente
glutKeyboardFunc(normal_keys);
// asignación de la funcion llamada "tecla_Especial" al evento correspondiente
glutSpecialFunc(special_keys);

// funcion de inicialización
initialize();

// inicio del bucle de eventos
glutMainLoop();



return 0;
}


