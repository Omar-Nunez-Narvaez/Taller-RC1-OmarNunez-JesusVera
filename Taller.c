#include <stdio.h>

// Función para ingresar y validar notas
void ingresarNotas(float *notas, int n) {
    for (int i = 0; i < n; i++) {
        printf("\n--- Estudiante %d ---\n", i + 1);

        for (int j = 0; j < 3; j++) {
            do {
                printf("Nota asignatura %d (0-10): ", j + 1);
                scanf("%f", (notas + i * 3 + j));

                if (*(notas + i * 3 + j) < 0 ||
                    *(notas + i * 3 + j) > 10) {
                    printf("  -> Invalida. Ingrese un valor entre 0 y 10.\n");
                }

            } while (*(notas + i * 3 + j) < 0 ||
                     *(notas + i * 3 + j) > 10);
        }
    }
}

// Resultados por estudiante
void resultadosEstudiante(float *notas, int n) {
    printf("\n=== RESULTADOS POR ESTUDIANTE ===\n");

    for (int i = 0; i < n; i++) {
        float suma = 0;
        float max = *(notas + i * 3);
        float min = *(notas + i * 3);

        for (int j = 0; j < 3; j++) {
            float valor = *(notas + i * 3 + j);

            suma += valor;

            if (valor > max)
                max = valor;

            if (valor < min)
                min = valor;
        }

        printf("Estudiante %d -> Promedio: %.2f | Max: %.2f | Min: %.2f\n",
               i + 1, suma / 3.0, max, min);
    }
}

// Resultados por asignatura
void resultadosAsignatura(float *notas, int n) {
    printf("\n=== RESULTADOS POR ASIGNATURA ===\n");

    for (int j = 0; j < 3; j++) {
        float suma = 0;
        float max = *(notas + j);
        float min = *(notas + j);

        int aprobados = 0;
        int reprobados = 0;

        for (int i = 0; i < n; i++) {
            float valor = *(notas + i * 3 + j);

            suma += valor;

            if (valor > max)
                max = valor;

            if (valor < min)
                min = valor;

            if (valor >= 6.0)
                aprobados++;
            else
                reprobados++;
        }

        printf("Asignatura %d -> Promedio: %.2f | Max: %.2f | Min: %.2f | "
               "Aprobados: %d | Reprobados: %d\n",
               j + 1, suma / n, max, min, aprobados, reprobados);
    }
}

int main() {
    int n;

    printf("Ingrese la cantidad de estudiantes: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: Debe ingresar un numero entero positivo.\n");
        return 1;
    }

    float notas[n][3];

    ingresarNotas(&notas[0][0], n);
    resultadosEstudiante(&notas[0][0], n);
    resultadosAsignatura(&notas[0][0], n);

    return 0;
}