#include <unistd.h>
#include <stdio.h>

int main (int argc, char *argv[]) {
	execlp("gnome-calculator", "calculadora", NULL);
	printf("Se mostrara este mensaje?\n");
	execlp("firefox", "navegador", NULL);
	printf("Y este otro?\n");
	return 0;
}
