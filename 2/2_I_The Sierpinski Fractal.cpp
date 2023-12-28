#include <iostream>
#include <cstring>
#include <cstdio>
#include <math.h>
using namespace std;
const int maxn = 2050;
char trian[maxn][maxn];
void solve(int n, int x, int y)
{
    if (n == 1)
    {
        trian[x][y] = trian[x + 1][y - 1] = '/';
        trian[x][y + 1] = trian[x + 1][y + 2] = '\\';
        trian[x + 1][y] = trian[x + 1][y + 1] = '_';
        return;
    }
    int _n = 1 << (n - 1);
    solve(n - 1, x, y);
    solve(n - 1, x + _n, y - _n);
    solve(n - 1, x + _n, y + _n);
}

int main()
{
    int n;
    while (~scanf("%d", &n) && n)
    {
        int h = (1 << n);
        int w = (1 << (n + 1));
        for (int i = 1; i <= h; i++)
            for (int j = 1; j <= w; j++)
                trian[i][j] = ' ';

        solve(n, 1, 1 << n);
        int k = (1 << n) + 1;
        for (int i = 1; i <= h; i++)
        {
            trian[i][k + i] = '\0';
            cout << trian[i] + 1 << endl;
        }
        puts(""); // puts()自动换行
    }
    return 0;
}