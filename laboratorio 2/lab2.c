#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Función para calcular la conjetura de Collatz
void collatz(int n) {
    printf("Número %d: ", n);
    while (n != 1) {
        printf("%d ", n);
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
    }
    printf("1\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s num1 num2 num3 ...\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        int num = atoi(argv[i]);
        if (num <= 0) {
            printf("El argumento %s no es un número entero positivo.\n", argv[i]);
            continue;
        }

        pid_t pid = fork();

        if (pid == 0) { // Proceso hijo
            collatz(num);
            exit(0);
        } else if (pid < 0) {
            printf("Error al crear el proceso hijo para el número %d.\n", num);
        }
    }

    // Espera a que todos los procesos hijos terminen
    int status;
    for (int i = 1; i < argc; i++) {
        wait(&status);
    }

    return 0;
}
