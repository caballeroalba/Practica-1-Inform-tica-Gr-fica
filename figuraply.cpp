#include "figuraply.h"


FiguraPLy::FiguraPLy()
{

}



bool FiguraPLy::carga_fichero_ply(char *Ruta){

    int result=this->fply.open(Ruta);


    if (result == 0){
        carga_datos_ply();
        return true;
    }else{
        return false;
    }
}


void FiguraPLy::carga_datos_ply(){

    //cargamos los datos en las variables

    int result=fply.read(Vertices,faces);
    if (result != 0)
        cout << "error al leer el fichero ply";


    for (int i=0; i<Vertices.size(); i+=3){

        _vertex3f aux;
        aux.x=Vertices[i];
        aux.y=Vertices[i+1];
        aux.z=Vertices[i+2];
        //lista.insert(lista.begin(),aux);
        listaV.push_back(aux);


    }


    for (int i=0; i<faces.size(); i+=3){
        //cout << "\n" << faces[i] << "\n";
        _vertex3f p1;
        _vertex3f p2;
        _vertex3f p3;
        Triangle auxx;
        p1=listaV[faces[i]];
        p2=listaV[faces[i+1]];
        p3=listaV[faces[i+2]];

        auxx.set_point_1(p1);
        auxx.set_point_2(p2);
        auxx.set_point_3(p3);
        listaC.push_back(auxx);
        //listaC.insert(listaC.begin(),auxx);


    }

    this->set_vertices(listaV);
    this->set_caras(listaC);

}
