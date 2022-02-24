#ifndef __UF_H__
#define __UF_H__

struct uf;

struct uf *init(int N);
void deinit(struct uf *uf);
int find(struct uf *uf, int p, int q);
void uni(struct uf *uf, int p, int q);

void reset(struct uf *uf);

#endif
