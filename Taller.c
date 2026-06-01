#include <stdio.h>

int main() {
    int n;
    
    // Solicitar cantidad de estudiantes
    printf("Ingrese la cantidad de estudiantes: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: Debe ingresar un numero entero positivo.\n");
        return 1;
    }
    
