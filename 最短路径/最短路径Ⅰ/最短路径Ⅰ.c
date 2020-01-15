#include <stdio.h>
#include <stdlib.h>  

void Dijkstra(int n, int(*MAP)[1001], int s, int* DIS, int* PATH);

void main()
{
	int N, M, S, T, a, b, w, i, j;
	int(*map)[1001] = (int(*)[1001])malloc(sizeof(int) * 1001 * 1001);
	scanf("%d %d %d %d", &N, &M, &S, &T);
	int* dis = (int*)malloc(sizeof(int) * N);
	int* path = (int*)malloc(sizeof(int) * N);
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			map[i][j] = 65535;
			if (i == j)
				map[i][j] = 0;
		}
	}
	for (i = 0; i < M; i++)
	{
		scanf("%d %d %d", &a, &b, &w);
		if (w < map[a][b])
		{
			map[a][b] = w;
			map[b][a] = w;
		}
	}
	Dijkstra(N, map, S, dis, path);
	printf("%d\n", dis[T]);
}

void Dijkstra(int n, int (*MAP)[1001], int s, int* DIS, int* PATH)
{
	int S[1001], i, min = 65535, v, j;
	for (i = 1; i <= n; i++)
	{
		S[i] = 0;
		DIS[i] = MAP[s][i];
		if (DIS[i] < 65535)
			PATH[i] = s;
		else
			PATH[i] = 0;
	}
	PATH[s] = -1;
	S[s] = 1;
	for (i = 1; i <= n; i++)
	{
		min = 65535;
		for (j = 1; j <= n; j++)
		{
			if (S[j] != 1 && DIS[j] < min)
			{
				min = DIS[j];
				v = j;
			}
		}
		S[v] = 1;
		for (j = 1; j <= n; j++)
		{
			if (S[j] == 0 && DIS[v] + MAP[v][j] < DIS[j])
			{
				DIS[j] = DIS[v] + MAP[v][j];
				PATH[j] = v;
			}
		}
	}
}
