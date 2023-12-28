#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int getResult(vector<int> &a, int s)
{
	int start = 0, end = 0, sum = 0, len = a.size(), minlen = len + 1;
	while (end < len)
	{
		sum += a[end];
		while (sum >= s)
		{
			minlen = min(minlen, end - start + 1);
			sum -= a[start];
			start++;
		}
		end++;
	}
	if (minlen > len)
		return 0;
	return minlen;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, s;
		cin >> n >> s;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int res = getResult(a, s);
		printf("%d\n", res);
	}
	return 0;
}
