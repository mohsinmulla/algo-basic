#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

#include "uf.h"

int is_open(unsigned char *slots, int p) {
	return slots[p] == 1;
}

void open(unsigned char *slots, int p) {
	slots[p] = 1;
}

void setl(struct uf *uf, unsigned char *slots, int N, int p) {
	if (p % N == 1) {
		return;
	}
	int l = p - 1;

	if (!is_open(slots, l)) {
		return;
	}

	uni(uf, p, l);
}

void setr(struct uf *uf, unsigned char *slots, int N, int p) {
	if (p % N == 0) {
		return;
	}
	int r = p + 1;

	if (!is_open(slots, r)) {
		return;
	}

	uni(uf, p, r);
}

void setu(struct uf *uf, unsigned char *slots, int N, int p) {
	if (p <= N) {
		return;
	}
	int u = p - N;

	if (!is_open(slots, u)) {
		return;
	}

	uni(uf, p, u);
}

void setd(struct uf *uf, unsigned char *slots, int N, int p) {
	if (p >= (N * (N-1))) {
		return;
	}
	int d = p + N;

	if (!is_open(slots, d)) {
		return;
	}

	uni(uf, p, d);
}


int main(int argc, char *argv[]) {

	if (argc != 3) {
		printf("Usage: a.out gridsize trials\n");
		return 0;
	}

	int N = atoi(argv[1]);
	int trials = atoi(argv[2]);
	double total = 0.0;

	printf("Perc for gridsize %d for %d trials\n", N, trials);

	int total_cells = N * N + 2;

	unsigned char *slots = malloc(total_cells);
	assert(slots);
	memset(slots, 0, total_cells);

	struct uf *uf = init(total_cells);

	srand(time(NULL));

	for (int i = 0; i < trials; i++) {
		reset(uf);
		for (int i = 1; i <= N; i++) {
			uni(uf, 0, i);
			uni(uf, total_cells - 1, total_cells - 1 - i);
		}
		memset(slots, 0, total_cells);

		int open_cells = 0;
		while (!find(uf, 0, total_cells - 1)) {
			int r = (rand() % (N * N)) + 1;
			if (is_open(slots, r)) {
				continue;
			}
			open(slots, r);
			open_cells += 1;

			setl(uf, slots, N, r);
			setr(uf, slots, N, r);
			setu(uf, slots, N, r);
			setd(uf, slots, N, r);
		}

		total += ((open_cells * 1.0) / (N * N)); 

	}

	printf("Percolation probability: %f\n", total / trials);

	return 0;
}
