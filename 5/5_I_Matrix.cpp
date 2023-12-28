#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <limits.h>
#include <math.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
ll k, n, m;
bool Ok(ll mid)
{
	ll sum = 0;
	for (ll j = 1; j <= n; j++)
	{
		ll left = 0, right = n;
		while (left < right)
		{
			ll i = left + (right - left) / 2;
			if (i * i + 100000 * i + j * j - 100000 * j + i * j >= mid)
			{
				right = i;
			}
			else
			{
				left = i + 1;
			}
		}
		if (left * left + 100000 * left + j * j - 100000 * j + left * j > mid)
		{
			sum += max(0LL, left - 1);
		}
		else
		{
			sum += left;
		}
	}
	return sum >= m;
}
int main()
{
	while (scanf("%lld", &k) != EOF)
	{
		while (k--)
		{
			scanf("%lld%lld", &n, &m);
			ll L = (ll)-1e12, R = (ll)1e12;
			while (L < R)
			{
				ll mid = L + (R - L) / 2;
				if (Ok(mid))
				{
					R = mid;
				}
				else
				{
					L = mid + 1;
				}
			}
			printf("%lld\n", R);
		}
	}
	return 0;
}
