// #include <stdio.h>
// #include <cstring>
// #include <algorithm>
// using namespace std;
// typedef __int64 LL;

// int main()
// {
// 	LL n, k;
// 	scanf("%I64d %I64d", &n, &k);
// 	LL ans = 1;
// 	while (k % 2 == 0)
// 	{
// 		k /= 2;
// 		ans++;
// 	}
// 	printf("%I64d\n", ans);
// 	return 0;
// }

#include <iostream>
using namespace std;

int main()
{
	long long n, k, result = 1;
	cin >> n >> k;

	while((k & 1) == 0)
	{
		k = k >> 1;
		++result;
	}
	cout << result;

   return 0;
}


// 超时
// 等比数列前n项和：S_n = (a_1*(1-q^n)) / (1-q)
// #include <iostream>
// #include <cmath>
// using namespace std;

// int main()
// {
// 	int n, k;
// 	cin >> n >> k;

// 	while (true)
// 	{
// 		int temp = pow(2, n);
// 		temp = temp >> 1;
// 		if (k == temp)
// 		{
// 			cout << n;
// 			break;
// 		}
// 		if (k > temp)
// 			k = k - temp;
// 		--n;
// 	}

// 	return 0;
// }
