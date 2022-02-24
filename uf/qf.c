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

int find(struct uf *uf, int p, int q) {
	return uf->block[p] == uf->block[q];		
}

void uni(struct uf *uf, int p, int q) {
	int pid = uf->block[p];
	int qid = uf->block[q];

	int i;

	for (i = 0; i < uf->N; i++) {
		if (uf->block[i] == pid) {
			uf->block[i] = qid;
		}
	} 
}

