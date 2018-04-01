//
// Created by Hedmon lopez on 23/03/2018.
//
#include "Herramientas.h"
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

void creararchivo()
{
    ofstream archivoOut("herramienta.dat", ios::out | ios::app | ios::binary);

    if (!archivoOut) {
        cout << "ERROR ARCHIVO" << endl;
        return;
    }



    for (int x = 0; x < 101; x++) {
        Herramienta nuevo;
        nuevo.codigo = -1;
        strcpy(nuevo.nombre, "");
        nuevo.catidad = -1;
        nuevo.precio = -1;

        archivoOut.write(reinterpret_cast<const char *>(&nuevo), sizeof(Herramienta));

    }
    cout << "Lista creada!" << endl;
    archivoOut.close();
}

int retornoBytes_SigEspacioVacio(int x)
{
    ifstream archivoIn("herramienta.dat", ios::in | ios::binary);

    if (!archivoIn) {
        cout << "ERROR ARCHIVO" << endl;
        return -1;
    }

    archivoIn.seekg(0,ios::beg);

    Herramienta actual;
    archivoIn.read(reinterpret_cast<char *>(&actual), sizeof(Herramienta));

    while (!archivoIn.eof())
    {
        if (actual.codigo == x)
        {
            int bytes = archivoIn.tellg();
            archivoIn.close();
            return bytes - sizeof(Herramienta);
        }
        archivoIn.read(reinterpret_cast<char *>(&actual), sizeof(Herramienta));
    }
    archivoIn.close();
    cout <<  "Codigo no existe" << endl;
    return -1;
}


void agregar()
{



    fstream archivoOut("herramienta.dat", ios::in | ios::out | ios::binary);
    if (!archivoOut) {
        cout << "ERROR ARCHIVO" << endl;
        return;
    }

    int pos = retornoBytes_SigEspacioVacio(-1);
    cout << pos << endl;

    archivoOut.seekp(pos, ios::beg);

    Herramienta nuevo;
    cout << "\nIngrese codigo: ";
    cin >> nuevo.codigo;
    cout << "Ingrese nombre: ";
    cin >> nuevo.nombre;
    cout << "Ingrese cantidad: ";
    cin >> nuevo.catidad;
    cout << "Ingrese precio: ";
    cin >> nuevo.precio;
    archivoOut.write(reinterpret_cast<const char *>(&nuevo), sizeof(Herramienta));
    cout << "HERRAMIENTA GUARDADA!" << endl;
    archivoOut.close();

}

void modificar()
{
    fstream modificarArchivo("herramienta.dat", ios::in | ios::out | ios::binary);

    if (!modificarArchivo) {
        cout << "ERROR ARCHIVO" << endl;
        return;
    }

    cout << "\nIngrese codigo de la herramienta: ";
    int cod;
    cin >> cod;

    int bytes = retornoBytes_SigEspacioVacio(cod);
    modificarArchivo.seekp(bytes, ios::beg);
    Herramienta nuevo;
    cout << "\nIngrese codigo: ";
    cin >> nuevo.codigo;
    cout << "Ingrese nombre: ";
    cin >> nuevo.nombre;
    cout << "Ingrese cantidad: ";
    cin >> nuevo.catidad;
    cout << "Ingrese precio: ";
    cin >> nuevo.precio;
    modificarArchivo.write(reinterpret_cast<const char *>(&nuevo), sizeof(Herramienta));
    cout << "HERRAMIENTA MODIFICADA!" << endl;
    modificarArchivo.close();
}

void eliminar()
{
    fstream eliminarHerramienta("herramienta.dat", ios::in | ios::out | ios::binary);

    if (!eliminarHerramienta) {
        cout << "ERROR ARCHIVO" << endl;
        return;
    }

    cout << "\nIngrese codigo de la herramienta: ";
    int cod; cin >> cod;

    int bytes = retornoBytes_SigEspacioVacio(cod);
    eliminarHerramienta.seekp(bytes, ios::beg);
    Herramienta nuevo;
    nuevo.codigo = -1;
    strcpy(nuevo.nombre, "");
    nuevo.catidad = -1;
    nuevo.precio = -1;

    eliminarHerramienta.write(reinterpret_cast<const char *>(&nuevo), sizeof(Herramienta));
    cout << "HERRAMIENTA ELIMINADA!" << endl;
    eliminarHerramienta.close();

}

void buscar()
{
    ifstream buscarHerramienta("herramienta.dat", ios::in | ios::binary);

    if (!buscarHerramienta) {
        cout << "ERROR ARCHIVO" << endl;
        return;
    }

    buscarHerramienta.seekg(0, ios::beg);

    cout << "\nIngrese codigo de la herramienta: ";
    int cod;
    cin >> cod;

    Herramienta actual;
    buscarHerramienta.read(reinterpret_cast<char *>(&actual), sizeof(Herramienta));
    while (!buscarHerramienta.eof())
    {
        if (actual.codigo == cod)
        {
            cout << "\nCodigo: " << actual.codigo << "  ";
            cout << "Nombre: " << actual.nombre << "  ";
            cout << "Cantidad: " << actual.catidad << "  ";
            cout << "Precio: " << actual.precio << "\n---------------------------------------------------------------------------------------------\n";
        }

        buscarHerramienta.read(reinterpret_cast<char *>(&actual), sizeof(Herramienta));
    }
    buscarHerramienta.close();


}

void imprimirlista()
{
    ifstream archivoIn("herramienta.dat", ios::in | ios::binary);

    if (!archivoIn) {
        cout << "ERROR ARCHIVO" << endl;
        return;
    }

    archivoIn.seekg(0, ios::beg);

    int tamano = sizeof(Herramienta);

    cout << "\n\n *** LISTA DE HERRAMIENTAS *** \n\n";
    Herramienta actual;
    archivoIn.read(reinterpret_cast<char *>(&actual), sizeof(Herramienta));

    while (!archivoIn.eof())
    {

        cout << "Codigo: " << actual.codigo << "  ";
        cout << "Nombre: " << actual.nombre << "  ";
        cout << "Cantidad: " << actual.catidad << "  ";
        cout << "Precio: " << actual.precio << "\n---------------------------------------------------------------------------------------------\n";

        archivoIn.read(reinterpret_cast<char *>(&actual), sizeof(Herramienta));
    }
    archivoIn.close();
}
