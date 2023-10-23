#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main (int argc, char *argv[]) {
	pid_t pid_calc, pid_nav, pidfin;
	int num;
	pid_calc = fork();
	if (pid_calc == 0) {
		execlp("gnome-calculator", "calculadora", NULL);
		printf("No se encuentra la aplicacion de calculadora\n");
		exit(0);
	}
	pid_nav = fork();
	if(pid_nav == 0) {
		execlp ("firefox", "navegador", NULL);
		printf("No se encuentra la aplicacion navegador\n");
		exit(0);
	}
	for (num = 0; num < 2; num++) {
		pidfin = wait(NULL);
		if (pidfin == pid_calc) {
			printf("Ha terminado calculadora\n");
		} else {
			printf("Ha terminado navegador\n");
		}
	}
	return 0;
}
