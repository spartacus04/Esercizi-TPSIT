#include <stdio.h>
#include <sys/types.h>

int main() {
	int status;
	// Input del numero di fork
	int n;
	printf("Inserisci il numero di figli: ");
	scanf("%d", &n);

	// Tengo a mente il PID padre
	int father = getpid();
	printf("Il PID del padre originale è %d\n", father);

	// Crea i figli
	for(int i = 0; i < n; i++) {
		int pid = fork();
		if(pid == 0) {
			printf("Figlio numero %d: \n", (i + 1));
			break;
		}
		wait(&status);
	}

	// Controllo se il PID è quello del padre o del figlio
	if(father != getpid()) {
		printf("Il mio PID è %d e il PID del padre è %d\n", getpid(), getppid());
	}

	return 0;
}