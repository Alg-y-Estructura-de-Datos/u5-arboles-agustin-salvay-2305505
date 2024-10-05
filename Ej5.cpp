#include <iostream>
#include "Arbol/ArbolBinario.h"

void menu() {
    std::cout << "\n--- Sistema de Gestión de Paquetes ---\n";
    std::cout << "1. Agregar un paquete\n";
    std::cout << "2. Eliminar un paquete entregado\n";
    std::cout << "3. Verificar si un paquete está en tránsito\n";
    std::cout << "4. Imprimir el estado actual de los paquetes (en forma de árbol)\n";
    std::cout << "5. Salir\n";
    std::cout << "Seleccione una opción: ";
}

int main() {
    ArbolBinario<int> paquetes;
    int opcion, paquete;

    // Inicialmente agregamos los números de seguimiento mencionados en el ejercicio
    paquetes.put(1001);
    paquetes.put(5002);
    paquetes.put(3003);
    paquetes.put(2004);
    paquetes.put(4500);
    paquetes.put(7005);
    paquetes.put(8006);

    while (true) {
        menu();
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            std::cout << "Ingrese el número de seguimiento del paquete a agregar: ";
            std::cin >> paquete;
            try {
                paquetes.put(paquete);
                std::cout << "Paquete " << paquete << " agregado correctamente.\n";
            } catch (int e) {
                std::cout << "Error: El paquete ya está registrado en el sistema.\n";
            }
            break;

        case 2:
            std::cout << "Ingrese el número de seguimiento del paquete entregado: ";
            std::cin >> paquete;
            try {
                paquetes.remove(paquete);
                std::cout << "Paquete " << paquete << " eliminado correctamente.\n";
            } catch (int e) {
                std::cout << "Error: No se pudo encontrar el paquete para eliminarlo.\n";
            }
            break;

        case 3:
            std::cout << "Ingrese el número de seguimiento del paquete a verificar: ";
            std::cin >> paquete;
            try {
                paquetes.search(paquete);
                std::cout << "El paquete " << paquete << " está en tránsito.\n";
            } catch (int e) {
                std::cout << "El paquete " << paquete << " no está en tránsito.\n";
            }
            break;

        case 4:
            std::cout << "Estado actual de los paquetes (árbol):\n";
            paquetes.print();
            std::cout << "\n";
            break;

        case 5:
            std::cout << "Saliendo del sistema de gestión de paquetes...\n";
            return 0;

        default:
            std::cout << "Opción no válida. Intente nuevamente.\n";
            break;
        }
    }

    return 0;
}
