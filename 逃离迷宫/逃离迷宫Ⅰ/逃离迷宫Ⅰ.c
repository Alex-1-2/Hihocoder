#include <stdio.h>

void main(void)
{
	char maze[100][100];
	int N, M, K, a, b, c, d, key[5][2];
	int i, j;
	scanf("%d %d %d %d %d %d %d", &N, &M, &K, &a, &b, &c, &d);
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			scanf("%c", &maze[i][j]);
	for (i = 0; i < K; i++)
		scanf("%d %d", &key[i][0], &key[i][1]);
}