#include <iostream>
#include <cmath> //abs()
#include <algorithm>
#include <cstdio> //scanf()
using namespace std;
int main()
{
	int T;
	cin >> T;
	int a[10];
	while (T--)
	{
		int i = 0;
		char ch;
		int ans = 0x3f3f3f3f; // 差值最小 无穷大

		while (1)
		{ // 1.
			scanf("%d%c", &a[i++], &ch);
			if (ch == '\n')
				break; // 跳出while(1)
		}

		if (i == 2)
		{ // 2.
			cout << abs(a[0] - a[1]) << endl;
			continue; // 跳出本次while(T--)
		}

		int mid = i / 2; // 3.
		do
		{
			int p = a[0];
			int q = a[mid];
			if (a[0] == 0 || a[mid] == 0) // 5.
				continue;				  // 跳出本次do while
			for (int j = 1; j < mid; j++)
			{
				p = p * 10 + a[j];
			}
			for (int j = mid + 1; j < i; j++)
			{
				q = q * 10 + a[j];
			}
			ans = min(ans, abs(p - q));
		} while (next_permutation(a, a + i)); // 4.
		cout << ans << endl;
	}
	return 0;
}