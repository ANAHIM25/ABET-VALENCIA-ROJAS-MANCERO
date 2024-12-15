#include <iostream>
#include <string>
#include "funcion.h"

using namespace std;

int main() {
    string componentes[3];
    float numerocomp[3] = {0};
    int contadorComponentes = 0;

    string productos[5];
    float tiempo[5] = {0};
    float cantidadcom[5][3] = {{0}};
    int contadorProductos = 0;

    int opcion;

    do {
        cout << "\n========== MENU PRINCIPAL DE TARJETAS DE VIDEO ==========\n";
        cout << "1. Ingresar componentes\n";
        cout << "2. Ingresar productos\n";
        cout << "3. Buscar un producto\n";
        cout << "4. Editar un producto\n";
        cout << "5. Eliminar un producto\n";
        cout << "6. Pedir Producto\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                ingresocomponentes(numerocomp, componentes, contadorComponentes);
                break;

            case 2:
                if (contadorComponentes == 0) {
                    cout << "Primero debe ingresar componentes antes de agregar productos.\n";
                } else {
                    ingresoProductos(productos, tiempo, cantidadcom, contadorComponentes, componentes);
                    contadorProductos = 5; // Consideramos que se ingresan los 5 productos
                }
                break;

            case 3:
                if (contadorProductos == 0) {
                    cout << "No hay productos ingresados para buscar.\n";
                } else {
                    buscarProducto(productos, tiempo, cantidadcom, componentes, contadorComponentes);
                }
                break;

            case 4:
                if (contadorProductos == 0) {
                    cout << "No hay productos ingresados para editar.\n";
                } else {
                    editarProducto(productos, tiempo, cantidadcom, componentes, contadorComponentes);
                }
                break;

            case 5:
                if (contadorProductos == 0) {
                    cout << "No hay productos ingresados para eliminar.\n";
                } else {
                    eliminarProducto(productos, tiempo, cantidadcom, contadorProductos);
                }
                break;

            case 6:
                productosPedir(productos, cantidadcom, numerocomp, componentes, contadorComponentes);
                break;

            case 7:
                cout << "\nSaliendo del programa......\n";
                break;

            default:
                cout << "Opcion no Valida.....\n";
        }
    } while (opcion != 7);

    return 0;
}
