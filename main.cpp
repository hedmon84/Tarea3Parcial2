#include "Herramientas.h"
#include <iostream>

using namespace std;

int main() {

    int opc;

    do {
        cout << "\n---MENU PRINCIPAL---\n" << endl;
        cout << "1. Crear Lista Vacia" << endl;
        cout << "2. Buscar Herramienta" << endl;
        cout << "3. Agregar Herramienta" << endl;
        cout << "4. Modificar Herramienta" << endl;
        cout << "5. Eliminar Herramienta" << endl;
        cout << "6. Imprimir Lista de Herramientas" << endl;
        cout << "7. Salir" << endl;
        cout << "Ingrese opcion: ";
        
        cin >> opc;
        switch (opc) {
            case 1:
                creararchivo();
                break;
            case 2:
                buscar();
                break;
            case 3:
                agregar();
                break;
            case 4:
                modificar();
                break;
            case 5:
                eliminar();
                break;
            case 6:
                imprimirlista();
                break;
        }
    } while (opc != 7);
}