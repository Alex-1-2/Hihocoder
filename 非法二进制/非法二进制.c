#include <stdio.h>

void main(void)
{
	int n, i;
	const long long mod = 1000000007;
	long long  dp[101][2], a = 2, answer;
	scanf("%d", &n);
	for (i = 2; i <= n; i++)
		a = (a * 2) % mod;
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (i = 2; i <= n; i++)
	{
		dp[i][1] = (dp[i - 1][0]);
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
	}
	answer = (a + mod - (dp[n][0] + dp[n][1]) % mod) % mod;
	printf("%lld\n", answer);
}