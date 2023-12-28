// #include <stdio.h>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// int a[100005], b[100005];
// int n, x, s = -1;
// int main()
// {
// 	ios::sync_with_stdio(false);
// 	int i, j, k;
// 	cin >> n >> x;
// 	while (n--)
// 	{
// 		cin >> k;
// 		if (a[k] != 0)
// 		{
// 			s = 0;
// 		}
// 		if (s != 0 && (a[k & x] != 0 || b[k] != 0))
// 		{
// 			s = 1;
// 		}
// 		if (s == -1 && b[k & x])
// 		{
// 			s = 2;
// 		}
// 		a[k]++;
// 		b[k & x]++;
// 	}
// 	cout << s << endl;
// 	return 0;
// }

#include <iostream>
using namespace std;

const int MAXN = 100005;
int a[MAXN], b[MAXN];

int main() {
    ios::sync_with_stdio(false);
    int n, x;
    cin >> n >> x;

    int s = -1;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        if (a[k] != 0) {
            s = 0;
        }
        if (s != 0 && (a[k & x] != 0 || b[k] != 0)) {
            s = 1;
        }
        if (s == -1 && b[k & x]) {
            s = 2;
        }
        a[k]++;
        b[k & x]++;
    }

    cout << s << endl;
    return 0;
}
