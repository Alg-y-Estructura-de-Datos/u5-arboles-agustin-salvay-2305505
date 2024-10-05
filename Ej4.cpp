#include <iostream>
#include "Arbol/ArbolBinario.h"

void menu() {
    std::cout << "\n--- Sistema de Reservas de Mesas ---\n";
    std::cout << "1. Agregar una reserva\n";
    std::cout << "2. Eliminar una reserva\n";
    std::cout << "3. Verificar si una mesa está reservada\n";
    std::cout << "4. Imprimir el estado actual de reservas (en forma de árbol)\n";
    std::cout << "5. Salir\n";
    std::cout << "Seleccione una opción: ";
}

int main() {
    ArbolBinario<int> reservas;
    int opcion, mesa;

    // Inicialmente agregamos las mesas mencionadas en el ejercicio
    reservas.put(15);
    reservas.put(10);
    reservas.put(20);
    reservas.put(5);
    reservas.put(12);
    reservas.put(18);
    reservas.put(25);

    while (true) {
        menu();
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            std::cout << "Ingrese el número de mesa a reservar: ";
            std::cin >> mesa;
            try {
                reservas.put(mesa);
                std::cout << "Mesa " << mesa << " reservada correctamente.\n";
            } catch (int e) {
                std::cout << "Error: La mesa ya está reservada.\n";
            }
            break;

        case 2:
            std::cout << "Ingrese el número de mesa a cancelar: ";
            std::cin >> mesa;
            try {
                reservas.remove(mesa);
                std::cout << "Mesa " << mesa << " eliminada correctamente.\n";
            } catch (int e) {
                std::cout << "Error: No se pudo encontrar la mesa para cancelar la reserva.\n";
            }
            break;

        case 3:
            std::cout << "Ingrese el número de mesa a verificar: ";
            std::cin >> mesa;
            try {
                reservas.search(mesa);
                std::cout << "La mesa " << mesa << " está reservada.\n";
            } catch (int e) {
                std::cout << "La mesa " << mesa << " no está reservada.\n";
            }
            break;

        case 4:
            std::cout << "Estado actual de las reservas (árbol):\n";
            reservas.print();
            std::cout << "\n";
            break;

        case 5:
            std::cout << "Saliendo del sistema de reservas...\n";
            return 0;

        default:
            std::cout << "Opción no válida. Intente nuevamente.\n";
            break;
        }
    }

    return 0;
}
