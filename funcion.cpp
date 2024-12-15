#include <iostream>
#include <string>
#include <vector>
#include "funcion.h"

using namespace std;

void ingresocomponentes(float* numerocomp, string componentes[3], int& contador) {
    int continuar = 1;

    while (contador < 3 && continuar) {
        cout << "Ingrese el nombre del componente numero " << contador + 1 << " que tenemos en stock: (maximo 3): ";
        cin.ignore();
        getline(cin, componentes[contador]);

        cout << "Ingrese la cantidad de " << componentes[contador] << " que se tiene en stock: ";
        cin >> numerocomp[contador];

        contador++;

        if (contador < 3) {
            cout << "Desea ingresar otro componente? (0 = No, 1 = Si): ";
            cin >> continuar;
            while (continuar != 0 && continuar != 1) {
                cout << "Valor ingresado incorrecto. Ingrese 0 o 1: ";
                cin >> continuar;
            }
        }
    }
}

void ingresoProductos(string productos[5], float* tiempo, float cantidadcom[5][3], int contador, string componentes[3]) {
    cout << "Por favor, ingrese los 5 productos:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Ingrese el producto numero " << i + 1 << ": ";
        cin.ignore();
        getline(cin, productos[i]);

        cout << "Ingrese el tiempo necesario para la creacion de " << productos[i] << ": ";
        cin >> tiempo[i];

        for (int j = 0; j < contador; j++) {
            cout << "Cuantos " << componentes[j] << " necesita para su fabricacion?: ";
            cin >> cantidadcom[i][j];
        }
    }
}

void buscarProducto(string productos[5], float tiempo[5], float cantidadcom[5][3], string componentes[3], int contador) {
    string productoBuscado;
    bool encontrado = false;

    cout << "Que producto desea buscar? Ingrese el nombre: ";
    cin.ignore();
    getline(cin, productoBuscado);

    for (int i = 0; i < 5; i++) {
        if (productos[i] == productoBuscado) {
            encontrado = true;
            cout << "El tiempo de elaboracion del producto " << productos[i] << " es: " << tiempo[i] << " horas\n";
            cout << "Los componentes necesarios para " << productos[i] << " son:\n";
            for (int j = 0; j < contador; j++) {
                cout << "- " << componentes[j] << ": " << cantidadcom[i][j] << " unidades\n";
            }
            break;
        }
    }

    if (!encontrado) {
        cout << "Producto no encontrado.\n";
    }
}

void editarProducto(string productos[5], float tiempo[5], float cantidadcom[5][3], string componentes[3], int contador) {
    string productoBuscado;
    int encontrado = -1;

    cout << "Ingrese el nombre del producto a editar: ";
    cin.ignore();
    getline(cin, productoBuscado);

    for (int i = 0; i < 5; i++) {
        if (productos[i] == productoBuscado) {
            encontrado = i;
            break;
        }
    }

    if (encontrado != -1) {
        cout << "Producto encontrado: " << productos[encontrado] << "\n";

        cout << "Ingrese el nuevo nombre del producto: ";
        getline(cin, productos[encontrado]);

        cout << "Ingrese el nuevo tiempo de produccion: ";
        cin >> tiempo[encontrado];

        for (int j = 0; j < contador; j++) {
            cout << "Ingrese la nueva cantidad de " << componentes[j] << " necesaria: ";
            cin >> cantidadcom[encontrado][j];
        }

        cout << "Producto actualizado correctamente.\n";
    } else {
        cout << "Producto no encontrado.\n";
    }
}

void eliminarProducto(string productos[5], float tiempo[5], float cantidadcom[5][3], int& contadorProductos) {
    string productoEliminar;
    int encontrado = -1;

    cout << "Ingrese el nombre del producto que desea eliminar: ";
    cin.ignore();
    getline(cin, productoEliminar);

    for (int i = 0; i < contadorProductos; i++) {
        if (productos[i] == productoEliminar) {
            encontrado = i;
            break;
        }
    }

    if (encontrado != -1) {
        for (int i = encontrado; i < contadorProductos - 1; i++) {
            productos[i] = productos[i + 1];
            tiempo[i] = tiempo[i + 1];
            for (int j = 0; j < 3; j++) {
                cantidadcom[i][j] = cantidadcom[i + 1][j];
            }
        }
        contadorProductos--;
        cout << "Producto eliminado correctamente.\n";
    } else {
        cout << "Producto no encontrado.\n";
    }
}

void productosPedir(string productos[5], float cantidadcom[5][3], float numerocomp[3], string componentes[3], int contador) {
    int n, cantidadPedido;
    cout << "\nCual producto desea de nuestro inventario?\n";
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << "- " << productos[i] << "\n";
    }

    cout << "Ingrese el numero del producto que desea: ";
    cin >> n;

    if (n < 1 || n > 5) {
        cout << "Producto no valido.\n";
        return;
    }

    cout << "\nPor favor ingrese cuantos '" << productos[n - 1] << "' desea: ";
    cin >> cantidadPedido;

    bool posible = true;
    cout << "\nVerificando disponibilidad de componentes para '" << productos[n - 1] << "':\n";

    for (int i = 0; i < contador; i++) {
        float componentesNecesarios = cantidadPedido * cantidadcom[n - 1][i];
        if (numerocomp[i] < componentesNecesarios) {
            cout << "- No hay suficientes '" << componentes[i] << "'. Necesita " << componentesNecesarios << ", pero solo hay " << numerocomp[i] << ".\n";
            posible = false;
        } else {
            cout << "- '" << componentes[i] << "': Disponible (necesita " << componentesNecesarios << ", hay " << numerocomp[i] << ").\n";
        }
    }

    if (posible) {
        cout << "\nEl pedido es posible. Procesando...\n";
        cout << "Pedido procesado exitosamente.\n";
    } else {
        cout << "\nNo es posible realizar el pedido debido a la falta de componentes.\n";
    }
}
