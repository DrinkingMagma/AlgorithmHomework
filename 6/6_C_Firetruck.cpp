#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 21;
int map[25][25], dis[25][25];
int vis[25];
int t;
int cnt;
int k;
int a[25];
void dfs(int x, int num)
{
    if (x == t)
    {
        printf("%d", a[0]);
        for (int i = 1; i < k; i++)
            printf(" %d", a[i]);
        printf("\n");
        cnt++;
        return;
    }
    for (int i = 1; i < maxn; i++)
    {
        if (map[x][i] || map[i][x])
        {
            if (vis[i] == 0 && dis[i][t] != maxn)
            {
                vis[i] = 1;
                a[k++] = i;
                dfs(i, num + 1);
                k--;
                vis[i] = 0;
            }
        }
    }
}
int main()
{
    int count = 0;
    while (scanf("%d", &t) != EOF)
    {
        int x, y;
        memset(map, 0, sizeof(map));
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i < maxn; i++)
            for (int j = 1; j < maxn; j++)
            {
                dis[i][j] = maxn;
            }
        scanf("%d%d", &x, &y);
        while (x != 0 && y != 0)
        {
            map[x][y] = map[y][x] = 1;
            dis[x][y] = dis[y][x] = 1;
            scanf("%d%d", &x, &y);
        }
        cnt = 0;
        printf("CASE %d:\n", ++count);
        for (int kk = 1; kk < maxn; kk++)
            for (int i = 1; i < maxn; i++)
                for (int j = 1; j < maxn; j++)
                {
                    if (dis[i][kk] + dis[kk][j] < dis[i][j])
                        dis[i][j] = dis[i][kk] + dis[kk][j];
                }
        for (int i = 2; i < maxn; i++)
        {
            if (map[1][i] && dis[1][t] != maxn)
            {
                //  cout<<i<<endl;
                memset(vis, 0, sizeof(vis));
                a[0] = 1;
                a[1] = i;
                k = 2;
                vis[1] = vis[i] = 1;
                dfs(i, 1);
            }
        }
        printf("There are %d routes from the firestation to streetcorner %d.\n", cnt, t);
    }
    return 0;
}

