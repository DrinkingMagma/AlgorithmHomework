// #include <cstdio>
// #include <cstring>
// #include <algorithm>
// #include <cmath>
// #include <iostream>
// #include <queue>
// using namespace std;
// const int MAX = 120022, M = 11111;
// long long dp[1001][1001];
// long long ans[MAX];
// long long a[MAX];
// int main()
// {
// 	int n;
// 	while (cin >> n && n)
// 	{
// 		memset(a, 0, sizeof(a));
// 		memset(ans, 0, sizeof(ans));
// 		for (int i = 0; i < n; i++)
// 			cin >> a[i];
// 		int num = 1;
// 		ans[1] = a[0];
// 		for (int i = 1; i < n; i++)
// 		{
// 			if (a[i] > ans[num])
// 			{
// 				ans[++num] = a[i];
// 			}
// 			else // 替换ans[i],使它尽量小些
// 			{
// 				int l = 0, r = num, mid;
// 				while (l <= r)
// 				{
// 					mid = (l + r) / 2;
// 					if (ans[mid] < a[i])
// 						l = mid + 1;
// 					else
// 						r = mid - 1;
// 				}
// 				ans[l] = a[i];
// 			}
// 		}
// 		cout << num << endl;
// 	}
// 	return 0;
// }


#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MX = 100010;
int dp[MX];

int binarySearch(int array[], int len, int target) {
    int left = 0, right = len - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (dp[mid] == target) return mid;
        else if (dp[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return left;
}

int main() {
    int n;
    int array[MX];
    while (cin >> n && n) {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            cin >> array[i];
        }

        int len = 1;
        dp[0] = array[0];

        for (int i = 1; i < n; i++) {
            if (array[i] > dp[len - 1]) {
                dp[len++] = array[i];
            } 
			else 
			{
                int pos = binarySearch(dp, len, array[i]);
                dp[pos] = array[i];
            }
        }

        cout << len << endl;
    }

    return 0;
}
