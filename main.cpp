#include <iostream>
#include <string>
#include "actividad.h"
using namespace std;


int main() {
    int opcion;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Notas de estudiantes\n";
        cout << "2. Encuesta cine\n";
        cout << "3. Secuencia ascendente\n";
        cout << "4. Tienda con descuentos\n";
        cout << "5. Primer caracter no repetido\n";
        cout << "6. Fibonacci\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) ejercicio1();
        else if (opcion == 2) ejercicio2();
        else if (opcion == 3) ejercicio3();
        else if (opcion == 4) ejercicio4();
        else if (opcion == 5) ejercicio5();
        else if (opcion == 6) ejercicio6();
        else if (opcion == 0) cout << "Saliendo...\n";
        else cout << "Opcion invalida\n";

    } while (opcion != 0);

    return 0;
}

void ejercicio1() {
    float nota, suma = 0;
    int aprobados = 0, reprobados = 0, excelentes = 0;

    for (int i = 1; i <= 8; i++) {
        cout << "Ingrese la nota del estudiante " << i << ": ";
        cin >> nota;
        suma = suma + nota;

        if (nota >= 3.0) {
            aprobados = aprobados + 1;
        } else {
            reprobados = reprobados + 1;
        }

        if (nota >= 4.5) {
            excelentes = excelentes + 1;
        }
    }

    cout << "Aprobados: " << aprobados << endl;
    cout << "Reprobados: " << reprobados << endl;
    cout << "Excelentes: " << excelentes << endl;
    cout << "Promedio: " << suma / 8 << endl;
}

void ejercicio2() {
    int edad, total = 0, jovenes = 0, perfectos = 0;
    float calificacion, suma = 0;

    cout << "Ingrese la edad (0 para terminar): ";
    cin >> edad;

    while (edad != 0) {
        cout << "Ingrese calificacion (1 a 10): ";
        cin >> calificacion;

        total = total + 1;
        suma = suma + calificacion;

        if (edad >= 18 && edad <= 25) {
            jovenes = jovenes + 1;
        }
        if (calificacion == 10) {
            perfectos = perfectos + 1;
        }

        cout << "Ingrese la edad (0 para terminar): ";
        cin >> edad;
    }

    if (total > 0) {
        cout << "Total encuestados: " << total << endl;
        cout << "Promedio: " << suma / total << endl;
        cout << "Jovenes (18-25): " << jovenes << endl;
        cout << "Nota perfecta: " << perfectos << endl;
    } else {
        cout << "No se ingresaron datos.\n";
    }
}

void ejercicio3() {
    int n, num, anterior, i;
    bool asc = true;

    cout << "Cuantos numeros va a ingresar: ";
    cin >> n;

    cout << "Ingrese el primer numero: ";
    cin >> anterior;

    for (i = 2; i <= n; i++) {
        cout << "Ingrese el siguiente numero: ";
        cin >> num;
        if (num <= anterior) {
            asc = false;
        }
        anterior = num;
    }

    if (asc) {
        cout << "La secuencia es ascendente.\n";
    } else {
        cout << "La secuencia NO es ascendente.\n";
    }
}

void ejercicio4() {
    float precio, total;
    int cantidad;
    float descuento = 0;

    cout << "Ingrese precio unitario: ";
    cin >> precio;
    cout << "Ingrese cantidad: ";
    cin >> cantidad;

    if (cantidad >= 11 && cantidad <= 20) {
        descuento = 0.05;
    } else if (cantidad >= 21 && cantidad <= 50) {
        descuento = 0.10;
    } else if (cantidad > 50) {
        descuento = 0.15;
    }

    total = precio * cantidad;
    total = total - (total * descuento);

    cout << "Total a pagar: " << total << endl;
}

void ejercicio5() {
    string palabra;
    cout << "Ingrese una palabra en minusculas: ";
    cin >> palabra;

    bool encontrado = false;

    for (int i = 0; i < palabra.length(); i++) {
        char letra = palabra[i];
        int cont = 0;

        for (int j = 0; j < palabra.length(); j++) {
            if (palabra[j] == letra) {
                cont = cont + 1;
            }
        }

        if (cont == 1) {
            cout << "Primer caracter no repetido: " << letra << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Todos los caracteres se repiten.\n";
    }
}

void ejercicio6() {
    int n, a = 0, b = 1, c;
    cout << "Ingrese n: ";
    cin >> n;

    cout << "Fibonacci: ";
    for (int i = 1; i <= n; i++) {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }
    cout << endl;
}
