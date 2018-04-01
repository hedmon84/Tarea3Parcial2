//
// Created by Hedmon lopez on 01/04/2018.
//

#ifndef TAREA3_0PROGRA3_1_HERRAMIENTAS_H
#define TAREA3_0PROGRA3_1_HERRAMIENTAS_H

struct Herramienta {
    int codigo;			//4
    char nombre[30];	//30
    int catidad;		//4
    float precio;		//8
    //44
};

void creararchivo();
int retornoBytes_SigEspacioVacio(int);
void agregar();
void modificar();
void eliminar();
void buscar();
void imprimirlista();

#endif //TAREA3_0PROGRA3_1_HERRAMIENTAS_H
