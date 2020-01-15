#include <stdio.h>
#include <string.h>
int score(char p[], int num);

void main(void)
{
	char str[100][101] = { 0 };
	int T, i, num, sco[100];
	scanf_s("%d", &T);
	for (i = 0; i < T; i++)
	{
		scanf_s("%s", str[i], 101);
		num = strlen(str[i]);
		sco[i] = score(str[i], num);
	}
	for (i = 0; i < T; i++)
	{
		printf("%d\n", sco[i]);
	}
}

int score(char p[], int num)
{
	int i, j=0, n, ret = 0, res, x = num/2 + 1, k;
	char ch, temp[101] = {0}, insert[101];
	for (k = 65; k <= 67; k++)
	{
		for (n = 0; n < num; n++)
		{
			strncpy(insert, p, n);
			insert[n] = (char)k;
			strncpy((insert + n + 1), (p + n), (num - n));
			for (x = (num / 2 + 1); x >= 0; x--)
			{
				for (i = 0; i < (num + 1); i++)
				{
					ch = insert[i];
					if (i == 0 && ch != insert[1])
						temp[j++] = ch;
					else if (i == (strlen(insert) - 1) && ch != insert[i - 1])
						temp[j++] = ch;
					else if (ch != insert[i - 1] && ch != insert[i + 1])
						temp[j++] = ch;
				}
				j = 0;
				strncpy(insert, temp, 101);
				res = (num + 1) - strlen(temp);
				memset(temp, '\0', 101);
				if (res == (num + 1))
					return res;
				else if (res > ret)
					ret = res;
			}
		}
		
	}
	return ret;
}
