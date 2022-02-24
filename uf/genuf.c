#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	int i;

	if (argc != 2) {
		printf("Usage: a.out N\n");
		return 0;
	}

	int N = atoi(argv[1]);

	printf("%d\n", N);

	srand(time(NULL));
	
	for (i = 0; i < N; i++) {
		int p = (int) (random() % N);
		int q = (int) (random() % N);

		printf("%d %d\n", p, q);
	}

	return 0;
}
