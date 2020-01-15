#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct a {
	int aN;
	int an[];
}arr;

void main(void)
{
	int TASKS, N, P, W, H, S;
	int i, j, sum = 0, size = 0, k = 0;
	struct a* n = NULL, * answer = NULL;
	scanf_s("%d", &TASKS);
	answer = (arr*)malloc(sizeof(arr) + TASKS * sizeof(int));
	for (i = 0; i < TASKS; i++)
	{
		scanf_s("%d %d %d %d", &N, &P, &W, &H);
		n = (arr*)malloc(sizeof(arr) + N * sizeof(int));
		for (j = 0; j < N; j++)
		{
			scanf_s("%d", &n->an[j]);
		}
		S = W;
		while (S > 1)
		{
			for (j = 0; j < N; j++)
			{
				size = (int)W / S;
				sum = sum + (int)n->an[j] / size + ceil((double)(n->an[j] % size) / size);
			}
			if (sum <= P * (int)(H / S))
			{
				answer->an[k++] = S;
				break;
			}
			else
			{
				S--;
				sum = 0;
			}
		}
	}
	for (k = 0; k < TASKS; k++)
	{
		printf("%d ", answer->an[k]);
	}
	free(answer);
	answer = NULL;
	free(n);
	n = NULL;
}