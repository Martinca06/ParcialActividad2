#include <iostream>
#include <string>
#include "actividad.h"

// ------------------- Funciones de los Ejercicios -------------------

void ejecutarNotasEstudiantes() {
    std::cout << "\n--- Notas de 8 estudiantes ---" << std::endl;
    double calificacion;
    int aprobados = 0, reprobados = 0, excelentes = 0;
    double sumaNotas = 0.0;

    for (int i = 0; i < 8; ++i) {
        std::cout << "Ingresa la calificacion " << i + 1 << ": ";
        std::cin >> calificacion;

        sumaNotas += calificacion;
        if (calificacion >= 3.0) aprobados++;
        else reprobados++;
        if (calificacion >= 4.5) excelentes++;
    }

    std::cout << "\nAprobados: " << aprobados << std::endl;
    std::cout << "Reprobados: " << reprobados << std::endl;
    std::cout << "Excelentes: " << excelentes << std::endl;
    std::cout << "Promedio: " << sumaNotas / 8 << std::endl;
}

void ejecutarEncuestaCine() {
    std::cout << "\n--- Encuesta de cine ---" << std::endl;
    int edad, calificacion, totalPersonas = 0;
    double sumaCalificaciones = 0.0;
    int jovenes = 0, perfectas = 0;

    while (true) {
        std::cout << "Ingresa la edad (0 para salir): ";
        std::cin >> edad;
        if (edad == 0) break;

        std::cout << "Ingresa la calificacion (1-10): ";
        std::cin >> calificacion;

        totalPersonas++;
        sumaCalificaciones += calificacion;
        if (edad >= 18 && edad <= 25) jovenes++;
        if (calificacion == 10) perfectas++;
    }

    std::cout << "\nTotal encuestados: " << totalPersonas << std::endl;
    if (totalPersonas > 0) std::cout << "Promedio: " << sumaCalificaciones / totalPersonas << std::endl;
    std::cout << "Jovenes (18-25): " << jovenes << std::endl;
    std::cout << "Calificaciones perfectas (10): " << perfectas << std::endl;
}

void ejecutarSecuenciaAscendente() {
    std::cout << "\n--- Secuencia ascendente ---" << std::endl;
    int n;
    std::cout << "Cuantos numeros vas a ingresar? ";
    std::cin >> n;

    if (n <= 1) {
        std::cout << "Necesitas al menos 2 numeros." << std::endl;
        return;
    }

    int anterior, actual;
    bool esAscendente = true;
    std::cout << "Ingresa el primer numero: ";
    std::cin >> anterior;

    for (int i = 2; i <= n; ++i) {
        std::cout << "Ingresa el numero " << i << ": ";
        std::cin >> actual;
        if (actual <= anterior) esAscendente = false;
        anterior = actual;
    }

    if (esAscendente) std::cout << "La secuencia es estrictamente ascendente." << std::endl;
    else std::cout << "La secuencia NO es estrictamente ascendente." << std::endl;
}

void ejecutarDescuentosTienda() {
    std::cout << "\n--- Descuentos en la tienda ---" << std::endl;
    double precio, total, descuento = 0.0;
    int cantidad;

    std::cout << "Precio unitario: ";
    std::cin >> precio;
    std::cout << "Cantidad: ";
    std::cin >> cantidad;

    if (cantidad > 50) descuento = 0.15;
    else if (cantidad >= 21) descuento = 0.10;
    else if (cantidad >= 11) descuento = 0.05;

    total = (precio * cantidad) * (1 - descuento);
    std::cout << "Total a pagar: " << total << std::endl;
}

void ejecutarCaracterNoRepetido() {
    std::cout << "\n--- Caracter no repetido ---" << std::endl;
    std::string palabra;
    std::cout << "Ingresa una palabra: ";
    std::cin >> palabra;

    char resultado = '\0';
    for (int i = 0; i < palabra.length(); ++i) {
        bool seRepite = false;
        for (int j = 0; j < palabra.length(); ++j) {
            if (i != j && palabra[i] == palabra[j]) {
                seRepite = true;
                break;
            }
        }
        if (!seRepite) {
            resultado = palabra[i];
            break;
        }
    }

    if (resultado != '\0') std::cout << "El primer caracter unico es: " << resultado << std::endl;
    else std::cout << "Todos los caracteres se repiten." << std::endl;
}

void ejecutarSecuenciaFibonacci() {
    std::cout << "\n--- Secuencia de Fibonacci ---" << std::endl;
    int n;
    std::cout << "Cuantos numeros quieres ver? ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "El numero debe ser mayor a 0." << std::endl;
        return;
    }

    long long a = 0, b = 1;
    for (int i = 0; i < n; ++i) {
        std::cout << a << " ";
        long long temp = a;
        a = b;
        b = temp + b;
    }
    std::cout << std::endl;
}

// ------------------- Función principal del Menú -------------------

void mostrarMenu() {
    std::cout << "\n--- MENU ---" << std::endl;
    std::cout << "1. Notas de estudiantes" << std::endl;
    std::cout << "2. Encuesta de cine" << std::endl;
    std::cout << "3. Secuencia ascendente" << std::endl;
    std::cout << "4. Descuentos en tienda" << std::endl;
    std::cout << "5. Caracter no repetido" << std::endl;
    std::cout << "6. Secuencia de Fibonacci" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "------------" << std::endl;
}

void ejecutarProgramaCompleto() {
    int opcion;
    do {
        mostrarMenu();
        std::cout << "Elige una opcion (0 para salir): ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                ejecutarNotasEstudiantes();
                break;
            case 2:
                ejecutarEncuestaCine();
                break;
            case 3:
                ejecutarSecuenciaAscendente();
                break;
            case 4:
                ejecutarDescuentosTienda();
                break;
            case 5:
                ejecutarCaracterNoRepetido();
                break;
            case 6:
                ejecutarSecuenciaFibonacci();
                break;
            case 0:
                std::cout << "Saliendo del programa." << std::endl;
                break;
            default:
                std::cout << "Opcion no valida." << std::endl;
        }
    } while (opcion != 0);
}
