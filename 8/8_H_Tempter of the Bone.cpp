// #include <string.h>
// #include <stdio.h>
// #include <iostream>
// #include <stdlib.h>
// using namespace std;
// char maze[7][7];
// int direct[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// int n, m, t, dx, dy;
// bool flag;
// void dfs(int x, int y, int step)
// {
//     int i, p, x1, y1;
//     if (x <= 0 || x > n || y <= 0 || y > m)
//         return;
//     if (x == dx && y == dy && step == t)
//     {
//         flag = 1;
//         return;
//     }
//     p = (t - step) - abs(x - dx) - abs(y - dy);
//     if (p < 0 || p & 1)
//         return;
//     for (i = 0; i < 4; i++)
//     {
//         x1 = x + direct[i][0];
//         y1 = y + direct[i][1];
//         if (maze[x1][y1] != 'X')
//         {
//             maze[x1][y1] = 'X';
//             dfs(x1, y1, step + 1);
//             if (flag)
//                 return;
//             maze[x1][y1] = '.';
//         }
//     }
//     return;
// }
// int main()
// {
//     int i, j, sx, sy, wall;
//     while (scanf("%d%d%d", &n, &m, &t) && (m + n + t))
//     {
//         wall = 0;
//         for (i = 1; i <= n; i++)
//         {
//             for (j = 1; j <= m; j++)
//             {
//                 cin >> maze[i][j];
//                 if (maze[i][j] == 'S')
//                 {
//                     sx = i;
//                     sy = j;
//                 }
//                 else if (maze[i][j] == 'D')
//                 {
//                     dx = i;
//                     dy = j;
//                 }
//                 else if (maze[i][j] == 'X')
//                     wall++;
//             }
//         }
//         flag = 0;
//         maze[sx][sy] = 'X';
//         dfs(sx, sy, 0);
//         if (n * m - wall <= t)
//         {
//             printf("NO\n");
//             continue;
//         }
//         if (flag)
//             printf("YES\n");
//         else
//             printf("NO\n");
//     }
//     return 0;
// }

#include <iostream>
#include <cstring>

using namespace std;

const int N = 8;

char maze[N][N];
bool vis[N][N];
int n, m, t;
int sx, sy, dx, dy;
bool flag;

int direct[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int x, int y, int step)
{
    if (flag) return; // 找到通路，直接退出
    if (step > t) return; // 走的步数超过限制，退出
    if (x == dx && y == dy && step == t) // 到达终点，且步数恰好为t
    {
        flag = true;
        return;
    }
    int p = (t - step) - abs(x - dx) - abs(y - dy); // 计算剩余步数是否能从当前位置到达终点
    if (p < 0 || p & 1) return; // 剩余步数为负数或奇数，无法到达终点，退出
    for (int i = 0; i < 4; i++)
    {
        int x1 = x + direct[i][0], y1 = y + direct[i][1];
        if (x1 <= 0 || x1 > n || y1 <= 0 || y1 > m) continue; // 越界
        if (maze[x1][y1] == 'X' || vis[x1][y1]) continue; // 障碍物或已访问过
        vis[x1][y1] = true;
        dfs(x1, y1, step + 1);
        vis[x1][y1] = false;
    }
}

int main()
{
    while (scanf("%d%d%d", &n, &m, &t), n || m || t)
    {
        // 初始化
        memset(vis, false, sizeof vis);
        flag = false;
        
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                cin >> maze[i][j];
                if (maze[i][j] == 'S') sx = i, sy = j;
                else if (maze[i][j] == 'D') dx = i, dy = j;
                else if (maze[i][j] == 'X') cnt++;
            }

        // 特判
        if (n * m - cnt <= t) { printf("NO\n"); continue; } // 所有通路都被墙壁挡住或剩余步数无法到达终点

        vis[sx][sy] = true;
        dfs(sx, sy, 0);
        if (flag) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
