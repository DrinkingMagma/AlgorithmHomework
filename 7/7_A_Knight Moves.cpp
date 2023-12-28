// #include <iostream>
// #include <queue>
// #include <cstring>
// using namespace std;
// // fx、fy初始坐标
// // lx、ly目标坐标
// // n 场景
// // m 棋盘大小
// int fx, fy, lx, ly, n, m;
// // map 距离；dis 访问标记
// int map[305][305], dis[305][305];
// int x[] = {1, -1, 1, -1, 2, -2, 2, -2};
// int y[] = {2, -2, -2, 2, 1, -1, -1, 1};
// void bfs()
// {
//     // 广度优先搜索需要使用队列保存结点
//     queue<int> q;
//     q.push(fx);
//     q.push(fy);

//     memset(map, 0, sizeof(map));
//     memset(dis, 0, sizeof(dis));
//     dis[fx][fy] = 1;

//     int vx, vy, tx, ty;
//     while (!q.empty())
//     {
//         vx = q.front();
//         q.pop();
//         vy = q.front();
//         q.pop();
//         // 遍历至目标结点
//         if (vx == lx && vy == ly)
//             break;

//         for (int i = 0; i < 8; i++)
//         {
//             tx = vx + x[i];
//             ty = vy + y[i];
//             if (!dis[tx][ty] && tx < m && tx >= 0 && ty < m && ty >= 0)
//             {
//                 q.push(tx);
//                 q.push(ty);
//                 dis[tx][ty] = 1;
//                 map[tx][ty] = map[vx][vy] + 1;
//             }
//         }
//     }
// }
// int main()
// {
//     cin >> n;
//     while (n--)
//     {
//         cin >> m;
//         cin >> fx >> fy >> lx >> ly;
//         bfs();
//         cout << map[lx][ly] << endl;
//     }
//     return 0;
// }

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MX = 305;
int visited[MX][MX], dist[MX][MX];
int origin_x, origin_y, target_x, target_y;
int n, m;
int mode_x[8] = {1, 2, 2, 1 ,-1 ,-2, -2, -1};
int mode_y[8] = {2 ,1, -1, -2, -2, -1, 1, 2};

int bfs()
{
    memset(visited, 0, sizeof(visited));
    memset(dist, 0, sizeof(dist));

    queue<int> q;
    q.push(origin_x);
    q.push(origin_y);
    visited[origin_x][origin_y] = 1;

    int cur_x, cur_y, next_x, next_y;
    while(!q.empty())
    {
        cur_x = q.front();
        q.pop();
        cur_y = q.front();
        q.pop();

        if(cur_x == target_x && cur_y == target_y)
            return dist[target_x][target_y];

        for(int i = 0; i < 8; i++)
        {
            next_x = cur_x + mode_x[i];
            next_y = cur_y + mode_y[i];

            if(next_x >= 0 && next_x < m && next_y >= 0 && next_y < m && !visited[next_x][next_y])
            {
                // cout << next_x << next_y << endl;
                visited[next_x][next_y] = 1;
                dist[next_x][next_y] = dist[cur_x][cur_y] + 1;
                    
                q.push(next_x);
                q.push(next_y);
            }
        }
    }
    return -1;
}

int main()
{
    cin >> n;
    while(n--)
    {
        cin >> m;
        cin >> origin_x >> origin_y >> target_x >> target_y;
        cout << bfs() << endl;
    }

   return 0;
}
