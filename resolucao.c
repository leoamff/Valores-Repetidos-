#include <stdio.h>
#include <stdlib.h>

#define M 30
#define N 20

void preenchendoMatriz(int matriz[M][N]) {
    int valores[3][N] = {
        {4, 17, 23, 48, 36, 17, 52, 67, 89, 48, 29, 14, 75, 83, 38, 56, 17, 91, 64, 71},
        {17, 48, 23, 48, 36, 52, 67, 89, 75, 38, 14, 29, 91, 56, 48, 64, 17, 89, 75, 29},
        {48, 4, 67, 17, 91, 29, 64, 52, 75, 89, 36, 56, 48, 14, 17, 23, 48, 67, 17, 91},
    };

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = valores[i % 3][j];
        }
    }
}

void imprimindoMatriz(int matriz[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int contandoRepetidos(int arr[], int tamanho) {
    int repetidos[101] = {0};
    int count = 0;

    for (int i = 0; i < tamanho; i++) {
        repetidos[arr[i]]++;
    }

    for (int i = 1; i <= 100; i++) {
        if (repetidos[i] > 1) {
            count += repetidos[i] - 1;
        }
    }

    return count;
}

void maisRepetidos(int matriz[M][N]) {
    int max_repetidos = -1;
    int index = -1;
    char tipo = 'L';

    for (int i = 0; i < M; i++) {
        int repetidos = contandoRepetidos(matriz[i], N);
        if (repetidos > max_repetidos) {
            max_repetidos = repetidos;
            index = i;
            tipo = 'L';
        }
    }

    for (int j = 0; j < N; j++) {
        int coluna[M];
        for (int i = 0; i < M; i++) {
            coluna[i] = matriz[i][j];
        }
        int repetidos = contandoRepetidos(coluna, M);
        if (repetidos > max_repetidos) {
            max_repetidos = repetidos;
            index = j;
            tipo = 'C';
        }
    }

    if (tipo == 'L') {
        printf("A linha com mais números repetidos é: %d\n", index);
    } else {
        printf("A coluna com mais números repetidos é: %d\n", index);
    }
}

int main() {
    int matriz[M][N];

    preenchendoMatriz(matriz);

    printf("Matriz:\n");
    imprimindoMatriz(matriz);

    maisRepetidos(matriz);

    return 0;
}