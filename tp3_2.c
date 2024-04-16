#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 5
#define COLUMNAS 12

int main() {
    int matriz[FILAS][COLUMNAS];
    int i, j, max, min, maxAnio, maxMes, minAnio, minMes;
    double promedio, suma;

    srand(time(NULL));

    for(i = 0; i < FILAS; i++) {
        for(j = 0; j < COLUMNAS; j++) {
            matriz[i][j] = 10000 + rand() % 40001;
        }
    }

    printf("Valores cargados en la matriz:\n");
    for(i = 0; i < FILAS; i++) {
        for(j = 0; j < COLUMNAS; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nPromedio de ganancia por año:\n");
    for(i = 0; i < FILAS; i++) {
        suma = 0;
        for(j = 0; j < COLUMNAS; j++) {
            suma += matriz[i][j];
        }
        promedio = suma / COLUMNAS;
        printf("Año %d: %.2f\n", i+1, promedio);
    }

    max = min = matriz[0][0];
    maxAnio = maxMes = minAnio = minMes = 1;
    for(i = 0; i < FILAS; i++) {
        for(j = 0; j < COLUMNAS; j++) {
            if(matriz[i][j] > max) {
                max = matriz[i][j];
                maxAnio = i+1;
                maxMes = j+1;
            }
            if(matriz[i][j] < min) {
                min = matriz[i][j];
                minAnio = i+1;
                minMes = j+1;
            }
        }
    }
    printf("\nValor máximo: %d (Año: %d, Mes: %d)\n", max, maxAnio, maxMes);
    printf("Valor mínimo: %d (Año: %d, Mes: %d)\n", min, minAnio, minMes);

    return 0;
}
