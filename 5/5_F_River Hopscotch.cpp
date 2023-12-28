#include <cstdio>
#include <iostream>
#include <algorithm>

int N, M, L;
int d[50005];

int main()
{
	scanf("%d%d%d", &L, &N, &M);
	d[0] = 0;
	d[N + 1] = L;
	for (int i = 1; i <= N; i++)
		scanf("%d", d + i);
	std::sort(d + 1, d + N + 1);
	int l, r, cnt, mid, last;
	l = 0;
	r = L;
	while (l <= r)
	{
		last = 0, mid = (l + r) >> 1, cnt = 0;
		for (int i = 1; i <= N + 1; i++)
		{
			if (mid >= d[i] - d[last])
				cnt++;
			else
				last = i;
		}
		if (cnt > M)
			r = mid - 1;
		else
			l = mid + 1;
	}
	printf("%d\n", l);
	return 0;
}
