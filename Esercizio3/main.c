#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* print_phrase(void* args)
{
	sleep(rand() % 3);
	printf("%s\n", (char*)args);
}

int main() {
	srand(time(NULL));

	pthread_t p1, p2, p3;

	pthread_create(&p1, NULL, &print_phrase, "Din");
	pthread_join(p1, NULL);
	pthread_create(&p2, NULL, &print_phrase, "Don");
	pthread_join(p2, NULL);
	pthread_create(&p3, NULL, &print_phrase, "Dan");
	pthread_join(p3, NULL);

	return 0;
}