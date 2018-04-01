//
// Created by Hedmon lopez on 01/04/2018.
//

#ifndef TAREA3_0PROGRA3_1_HERRAMIENTAS_H
#define TAREA3_0PROGRA3_1_HERRAMIENTAS_H

struct Herramienta {
    int codigo;
    char nombre[30];
    int cant;
    float precio;

};

void creararchivo();
int EspacioVacio(int);
void agregar();
void buscar();
void modificar();
void eliminar();
void imprimirlista();

#endif //TAREA3_0PROGRA3_1_HERRAMIENTAS_H
