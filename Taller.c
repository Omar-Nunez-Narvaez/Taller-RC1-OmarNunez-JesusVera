#include <stdio.h>

int main() {
    int n;
    
    // Solicitar cantidad de estudiantes
    printf("Ingrese la cantidad de estudiantes: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: Debe ingresar un numero entero positivo.\n");
        return 1;
    }
float notas[n][3];

    // 1. Ingreso y validación de calificaciones
    for (int i = 0; i < n; i++) {
        printf("\n--- Estudiante %d ---\n", i + 1);
        for (int j = 0; j < 3; j++) {
            do {
                printf("Nota asignatura %d (0-10): ", j + 1);
                scanf("%f", &notas[i][j]);
                if (notas[i][j] < 0 || notas[i][j] > 10) {
                    printf("  -> Invalida. Ingrese un valor entre 0 y 10.\n");
                }
            } while (notas[i][j] < 0 || notas[i][j] > 10);
        }
    }
    
    printf("\n=== RESULTADOS POR ESTUDIANTE ===\n");
    for (int i = 0; i < n; i++) {
        float suma = 0, max = notas[i][0], min = notas[i][0];
        for (int j = 0; j < 3; j++) {
            suma += notas[i][j];
            if (notas[i][j] > max) max = notas[i][j];
            if (notas[i][j] < min) min = notas[i][j];
        }
        printf("Estudiante %d -> Promedio: %.2f | Max: %.2f | Min: %.2f\n", 
               i + 1, suma / n, max, min); 
    }