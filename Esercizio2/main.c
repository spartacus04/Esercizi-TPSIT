#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

#define NUM1 3
#define NUM2 7
#define NUM3 9
#define NUM4 3


int main() {
	int pid = fork();

	// f1

	if(pid == 0) {
		exit(sum(NUM1, NUM2));
	}

	int sum1;
	wait(&sum1);
	sum1 /= 256;

	// f2

	int sum2 = division(NUM3, NUM4);

	// f3
	printf("%d\n", multiplication(sum1, sum2));
}



int sum(int n1, int n2) {
	return n1 + n2;
}

int division(int n1, int n2) {
	return n1 / n2;
}

int multiplication(int n1, int n2) {
	return n1 * n2;
}