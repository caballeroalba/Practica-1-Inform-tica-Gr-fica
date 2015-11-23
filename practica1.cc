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
#include "cubo.h"
#include "tetraedro.h"
#include "file_ply_stl.h"
#include <QString>
#include <qinputdialog.h>
#include "figuraply.h"
#include <string>
#include "figurarevolucion.h"
//#include "file_ply_stl.hpp"




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

int objeto=0;

// var para determinar el tipo de dibujado, puntos, trianglulos, etc.

// 0 = puntos
// 1 = alambre
// 2 = solido
// 3 = ajedrez

int modo=0;

_vertex3f Vertex;

_vertex2i Edge;


//variables del cubo

Cubo cubo;

Objeto3D c;


//Variables del tetraedro

Tetraedro tetraedro;

//variables de figura revolución

figuraRevolucion FiguraRevolucionaria;
bool estaRevolucionada=false;



//perfiles de prueba para la practica

figuraRevolucion figuraR1(30,180,45);
figuraRevolucion figuraR2(30,180,45);
figuraRevolucion figuraR3(30,180,45);
figuraRevolucion figuraR4(30,180,45);
figuraRevolucion figuraR5(30,180,45);



//variable del fichero ply

FiguraPLy Fply;



void cambio_objeto(unsigned char Tecla1){

    switch (Tecla1) {
    case '0':
        objeto=0;
        break;
    case '1':
        objeto=1;
        break;
    case '2':
        objeto=2;
        break;
    case '3':
        objeto=3;
        break;
    case '4':
        objeto=4;
        break;
    case '5':
        objeto=5;
        break;
    case '6':
        objeto=6;
        break;
    case '7':
        objeto=7;
        break;
    case '8':
        objeto=8;
        break;
    case '9':
        objeto=9;
        break;
    default:
        break;
    }


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

glColor3f(1,0,0);



glColor3f(0,1,0);
glPointSize(9);
glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);


switch (objeto) {
case 0://cubo
    cubo.dibuja(modo);
    break;
case 1://tetraedro
    tetraedro.dibuja(modo);
    break;
case 2: //*

    break;

case 3: //Figura Rev 1
   // FiguraRevolucionaria.dibuja(modo);
    figuraR1.dibuja(modo);
    break;
case 4:
    figuraR2.dibuja(modo);
    break;

case 5:
    figuraR3.dibuja(modo);
    break;
case 6:
    figuraR4.dibuja(modo);
    break;
case 7:
    figuraR5.dibuja(modo);
    break;
case 8: //Figura ply 1;
    Fply.dibuja(modo);
    break;
case 9:
    FiguraRevolucionaria.dibuja(modo);
}

if (objeto==0){
    //tetraedro.dibuja(modo);
}else if (objeto==1){
  //  cubo.dibuja(modo);
  //  cubo.dibuja_cubo(modo);
}

//Fply.dibuja(1);
//Fply.dibuja_perfil(0);







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

    cout << (int)Tecla1;
if (toupper(Tecla1)=='Q') exit(0);
if (toupper(Tecla1)=='S') cambio_modo(Tecla1);
if (toupper(Tecla1) <='9' && toupper(Tecla1) >= '0') cambio_objeto(Tecla1);
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
Window_width=0.5;
Window_height=0.5;
Front_plane=1;
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



    FiguraRevolucionaria.carga_fichero_ply("/home/caballeroalba/compilar_qtcreator/modelos_ply/perfil2.ply");
    //FiguraRevolucionaria.calculaPuntosDesdePerfilQ1();
   Fply.carga_fichero_ply("/home/caballeroalba/compilar_qtcreator/modelos_ply/armadillo.ply");


    //perfiles de prueba para la practica:
    //figura 1
    vector<_vertex3f> verticesF1;

    _vertex3f pf1;
    pf1.x=2;
    pf1.y=1;
    pf1.z=0;

    _vertex3f pf2;
    pf2.x=2;
    pf2.y=-1;
    pf2.z=0;

    verticesF1.push_back(pf1);
    verticesF1.push_back(pf2);
    figuraR1.set_vertices(verticesF1);
    figuraR1.calculaPuntosDesdePerfilQ1();

    //figura 2

    _vertex3f pf12;
    pf12.x=0;
    pf12.y=-1;
    pf12.z=0;

    _vertex3f pf22;
    pf22.x=2;
    pf22.y=-1;
    pf22.z=0;

    _vertex3f pf32;
    pf32.x=3;
    pf32.y=1;
    pf32.z=0;

    vector<_vertex3f> verticesF2;
    verticesF2.push_back(pf12);
    verticesF2.push_back(pf22);
    verticesF2.push_back(pf32);
    figuraR2.set_vertices(verticesF2);
    figuraR2.calculaPuntosDesdePerfilQ1();


    //figura 3:

    _vertex3f pf13;
    pf13.x=2;
    pf13.y=-1;
    pf13.z=0;

    _vertex3f pf23;
    pf23.x=1;
    pf23.y=1;
    pf23.z=0;
    _vertex3f pf33;
    pf33.x=0;
    pf33.y=1;
    pf33.z=0;


    vector<_vertex3f> verticesF3;
    verticesF3.push_back(pf13);
    verticesF3.push_back(pf23);
    verticesF3.push_back(pf33);
    figuraR3.set_vertices(verticesF3);
    figuraR3.calculaPuntosDesdePerfilQ1();


    //figura 4;
    _vertex3f pf14;
    pf14.x=0;
    pf14.y=-1;
    pf14.z=0;
    _vertex3f pf24;
    pf24.x=1;
    pf24.y=-1;
    pf24.z=0;
    _vertex3f pf34;
    pf34.x=1;
    pf34.y=1;
    pf34.z=0;
    _vertex3f pf44;
    pf44.x=0;
    pf44.y=1;
    pf44.z=0;
    vector<_vertex3f> verticesF4;
    verticesF4.push_back(pf14);
    verticesF4.push_back(pf24);;
    verticesF4.push_back(pf34);
    verticesF4.push_back(pf44);
    figuraR4.set_vertices(verticesF4);;
    figuraR4.calculaPuntosDesdePerfilQ1();

    //figura 5;
    _vertex3f f15;
    f15.x=0;
    f15.y=-1;
    f15.z=0;
    _vertex3f f25;
    f25.x=1;
    f25.y=-1;
    f25.z=0;
    _vertex3f f35;
    f35.x=0;
    f35.y=1;
    f35.z=0;
    vector<_vertex3f> verticesF5;
    verticesF5.push_back(f15);
    verticesF5.push_back(f25);
    verticesF5.push_back(f35);
    figuraR5.set_vertices(verticesF5);
    figuraR5.calculaPuntosDesdePerfilQ1();



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


