// 答案错误
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int mod = 1000007;
int n, m, a[120], f[120][120];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i <= n; i++)
		f[i][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int k = 0; k <= min(j, a[i]); k++)
				f[i][j] = (f[i][j] + f[i - 1][j - k]) % mod;
	cout << f[n][m];
	return 0;
}
