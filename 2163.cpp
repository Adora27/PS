#include <cstdio>

using namespace std;

const int N = 305;

int main()
{
	int n, m, dp[N][N] = { 0 };

	scanf("%d %d", &n, &m);
	dp[1][1] = 0;
	for (int i = 0; i < N; i++)
		dp[i][0] = dp[0][i] = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!(i & 1)) {
				dp[i][j] = dp[i / 2][j] * 2 + 1;
			}
			else if (!(j & 1)) {
				dp[i][j] = dp[i][j / 2] * 2 + 1;
			}
			else if (dp[j][i])
				dp[i][j] = dp[j][i];
			else {
				if(i<j)
					dp[i][j] = dp[i][j - 1] + dp[i][1] + 1;
				else
					dp[i][j] = dp[i-1][j] + dp[1][j] + 1;
			}
		}
	}

	printf("%d", dp[n][m]);
	return 0;
}
