#include <stdio.h>

void main()
{
	int missing[101] = { 0 }, T, N[10], M[10], i, j, k, answmer[10] = { 0 }, num;
	scanf("%d", &T);
	for (i = 0; i < T; i++)
	{
		scanf("%d %d", &N[i], &M[i]);
		for (j = 1; j <= N[i]; j++)
		{
			scanf("%d", &missing[j]);
		}
		if (M[i] >= N[i])
			answmer[i] = 100;
		else
		{
			num = N[i] - M[i];
			for (k = 1; k <= (N[i] - M[i] + 1); k++)
			{
				if (answmer[i] < missing[M[i] + k] - missing[k - 1] - 1)
					answmer[i] = missing[M[i] + k] - missing[k - 1] - 1;
			}
		}
	}
	for ( i = 0; i < T; i++)
	{
		printf("%d\n", answmer[i]);
	}
}
