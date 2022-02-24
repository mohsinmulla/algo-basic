#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "uf.h"

struct uf {
	int N;
	int *block;
	int *sz;
};

struct uf *init(int N) {
	int i;
	struct uf *uf = malloc(sizeof(struct uf));
	assert(uf);

	uf->N = N;

	uf->block = malloc(N * sizeof(int));
	assert(uf->block);

	uf->sz = malloc(N * sizeof(int));
	assert(uf->sz);

	for (i = 0; i < N; i++) {
		uf->block[i] = i;
		uf->sz[i] = 1;
	}
	return uf;
}

void deinit(struct uf *uf) {
	free(uf->block);
	free(uf->sz);
	free(uf);
}

void reset(struct uf *uf) {
	for (int i = 0; i < uf->N; i++) {
		uf->block[i] = i;
		uf->sz[i] = 1;
	}
}

int root(struct uf *uf, int p) {
	while (p != uf->block[p]) {
		uf->block[p] = uf->block[uf->block[p]];
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

	if (uf->sz[pr] < uf->sz[qr]) {
		uf->block[pr] = uf->block[qr];
		uf->sz[qr] += uf->sz[pr];
	} else {
		uf->block[qr] = uf->block[pr];
		uf->sz[pr] += uf->sz[qr];
	}
}

