#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "uf.h"

struct uf {
	int N;
	int *block;
};

struct uf *init(int N) {
	int i;
	struct uf *uf = malloc(sizeof(struct uf));
	assert(uf);

	uf->N = N;

	uf->block = malloc(N * sizeof(int));
	assert(uf->block);

	for (i = 0; i < N; i++) {
		uf->block[i] = i;
	}
	return uf;
}

void deinit(struct uf *uf) {
	free(uf->block);
	free(uf);
}

int root(struct uf *uf, int p) {
	while (p != uf->block[p]) {
		p = uf->block[p];
	}
	return p;
}

int find(struct uf *uf, int p, int q) {
	return root(uf, p) == root(uf, q);
}

void uni(struct uf *uf, int p, int q) {
	int pr = root(uf, p);
	int qr = root(uf, q);

	uf->block[pr] = qr;
}

