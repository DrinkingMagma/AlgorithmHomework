#include <iostream>
using namespace std;//最大m子段问题。
const int N = -0x3fffffff;
int num[100001], dp[100001];
int main()
{
	int n, max1, sum, s;
	while (scanf("%d", &n), n)
	{
		sum = 0, max1 = N;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &num[i]);
			sum += num[i];
			if (sum > max1)
				max1 = sum;
			dp[i] = max1;
			if (sum < 0)
				sum = 0;

		}//读数据时，正向一次dp，得到第i个元素的最大值
		dp[0] = s = max1=N;
		sum = 0;
		for (int i = n; i > 0; i--)//反向一次
		{
			sum += num[i];
			if (sum > max1)
				max1 = sum;
			if (s < max1 + dp[i - 1])
				s = max1 + dp[i - 1];//加上前面的得到最大值
			if (sum < 0)
				sum = 0;
		}
		printf("%d\n", s);
	}
}


