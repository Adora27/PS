#include <cstdio>
#define max(x,y) x>y?x:y

using namespace std;

const int N = 100005;

int main()
{
	int t, n, ar[2][N] = { 0 };

	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &ar[0][i]);
		for (int i = 1; i <= n; i++)
			scanf("%d", &ar[1][i]);
		for (int i = 1; i <= n; i++) {
			ar[0][i] = max(ar[0][i - 1], ar[1][i - 1] + ar[0][i]);
			ar[1][i] = max(ar[1][i - 1], ar[0][i - 1] + ar[1][i]);
		}
		printf("%d\n", max(ar[0][n], ar[1][n]));
	}

	return 0;
}
