// #include <bits/stdc++.h>
// using namespace std;
// int f[1000000000001], v[100000000000001], w[100000000001];
// int method(int n, int m)
// {
// 	for (int i = 1; i <= n; i++)
// 		for (int j = m; j >= w[i]; j--)
// 			f[j] = max(f[j], f[j - w[i]] + v[i]);
// 	return f[m];
// }
// int main()
// {
// 	int n, m;
// 	cin >> n >> m;
// 	for (int i = 1; i <= n; i++)
// 		cin >> w[i] >> v[i];
// 	cout << method(n, m);
// 	return 0;
// }

#include <iostream>
#include <algorithm>

const int MAXN = 1000010;

int w[MAXN], v[MAXN];
int f[MAXN];

int method(int n, int m)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= w[i]; j--)
        {
            f[j] = std::max(f[j], f[j - w[i]] + v[i]);
        }
    }
    return f[m];
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> w[i] >> v[i];
    }
    std::cout << method(n, m);
    return 0;
}
