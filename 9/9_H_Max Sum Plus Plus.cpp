#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int f[N], mx[N], a[N];
int main()
{
	int n, m;
	while (cin >> m >> n)
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), f[i] = mx[i] = 0;
		int mxx;
		for (int j = 1; j <= m; j++) // 分成j段
		{
			mxx = -0x3f3f3f3f; // 用于更新分成j段的mx数组，记录前i个数分成j段的mx数组的最大值
			for (int i = j; i <= n; i++)
			{
				f[i] = max(mx[i - 1], f[i - 1]) + a[i];
				mx[i - 1] = mxx;
				mxx = max(mxx, f[i]);
			}
		}
		cout << mxx << endl;
	}
	return 0;
}