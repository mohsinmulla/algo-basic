#include <stdio.h>
#include "uf.h"

int main() {
	int N;
	char line[80];

	scanf("%d\n", &N);

	struct uf *uf = init(N);

	while(fgets(line, 80, stdin)) {
		int p, q;
		sscanf(line, "%d %d", &p, &q);
#ifdef DEBUG
		printf("Read: %d %d\n", p, q); 
#endif	
		if (!find(uf, p, q)) {
			printf("Joining %d %d\n", p, q);
			uni(uf, p, q);
		} else {
			printf("Already connected %d %d\n", p, q);
		}	
	}

	deinit(uf);

	return 0;
}
