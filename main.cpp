#include "Herramientas.h"
#include <iostream>

using namespace std;

int main() {

    int opc;

    do {
        cout << "\n---MENU PRINCIPAL---\n" << "1. Crear Lista Vacia" << endl<< "2. Buscar Herramienta" << endl << "3. Agregar Herramienta" << endl << "4. Modificar Herramienta" <<endl<<  "5. Eliminar Herramienta"   <<  endl << "6. Imprimir Lista de Herramientas" << endl << "0 Salir" << endl<< "Ingrese opcion: ";;
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
            default:break;
        }
    } while (opc != 0);
}