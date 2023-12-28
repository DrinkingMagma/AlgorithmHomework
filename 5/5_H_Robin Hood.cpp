#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;

const int maxn = 5e5 + 5;

int a[maxn];
int n, k;

int main()
{
	scanf("%d %d", &n, &k);
	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}
	sort(a, a + n);
	int l = a[0], r = sum / n, mid;
	while (l <= r)
	{
		mid = l + r >> 1;
		ll tmp = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] < mid)
				tmp += mid - a[i];
			else
				break;
		}
		if (tmp > k)
			r = mid - 1;
		else
			l = mid + 1;
	}
	int ans1 = r;
	l = sum / n;
	if (sum % n != 0)
		++l;
	r = a[n - 1];
	while (l <= r)
	{
		mid = l + r >> 1;
		ll tmp = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (a[i] > mid)
				tmp += a[i] - mid;
			else
				break;
		}
		if (tmp > k)
			l = mid + 1;
		else
			r = mid - 1;
	}
	int ans2 = l;
	printf("%d\n", ans2 - ans1);
	return 0;
}
