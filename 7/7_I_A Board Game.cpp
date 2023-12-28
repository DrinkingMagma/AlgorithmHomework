#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
char start[5][5], result[5][5];
int mmove[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
char bw[2] = {'w', 'b'};
bool success()
{
    int i, j;
    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 4; ++j)
            if (start[i][j] != result[i][j])
            {
                return false;
            }
    }
    return true;
}
bool ok(int x, int y)
{
    if (x >= 0 && x < 4 && y >= 0 && y < 4)
        return true;
    else
        return false;
}
bool dfs(int step, int n, int num)
{
    if (step == n)
    {
        if (success())
            return true;
        else
            return false;
    }
    int i, j;
    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            if (start[i][j] != bw[num])
                continue;
            for (int k = 0; k < 8; ++k)
            {
                int x = i, y = j;
                while (ok(x + mmove[k][0], y + mmove[k][1]) && start[(x + mmove[k][0])][(y + mmove[k][1])] == '*')
                {
                    x += mmove[k][0];
                    y += mmove[k][1];
                }
                if (x == i && y == j)
                    continue;
                start[x][y] = bw[num];
                start[i][j] = '*';
                if (dfs(step + 1, n, 1 - num))
                {
                    return true;
                }
                start[i][j] = bw[num];
                start[x][y] = '*';
            }
        }
    }
    return false;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int i;
        for (i = 0; i < 4; ++i)
            scanf("%s", start[i]);
        for (i = 0; i < 4; ++i)
            scanf("%s", result[i]);
        int ans = 0;
        while (1)
        {
            if (dfs(0, ans, 0))
            {
                printf("%d\n", ans);
                break;
            }
            ans++;
        }
    }
    return 0;
}