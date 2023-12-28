#include <stdio.h>
#include <string.h>
int n = 9;
int t[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char a[15][15];
int vis[15][15];
int ff(int x, int y)
{
    int i, xx, yy;
    for (i = 0; i < 4; i++)
    {
        xx = x + t[i][0];
        yy = y + t[i][1];
        if (xx >= 0 && xx < 9 && yy >= 0 && yy < 9 && vis[xx][yy] == 0)
        {
            vis[xx][yy] = 1;
            if (a[xx][yy] == '.')
                return 1;
            else if (a[xx][yy] == 'o' && ff(xx, yy))
                return 1;
        }
    }
    return 0;
}
int f(int x, int y)
{
    int i, xx, yy;
    for (i = 0; i < 4; i++)
    {
        xx = x + t[i][0];
        yy = y + t[i][1];
        if (xx >= 0 && xx < 9 && yy >= 0 && yy < 9 && a[xx][yy] == 'o')
        {
            memset(vis, 0, sizeof(vis));
            if (ff(xx, yy) == 0)
                return 1;
        }
    }
    return 0;
}
int main()
{
    int t, i, j, num, ans;
    scanf("%d", &t);
    getchar();
    num = 0;
    while (t--)
    {
        for (i = 0; i < n; i++)
        {
            scanf("%s", a[i]);
        }

        ans = 0;
        memset(vis, 0, sizeof(vis));
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (a[i][j] == '.')
                {
                    a[i][j] = 'x';
                    if (f(i, j))
                    {
                        ans = 1;
                        break;
                    }
                    a[i][j] = '.';
                }
            }
        }
        if (ans)
            printf("Case #%d: Can kill in one move!!!\n", ++num);
        else
            printf("Case #%d: Can not kill in one move!!!\n", ++num);
    }
    return 0;
}