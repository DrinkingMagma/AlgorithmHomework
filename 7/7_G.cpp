#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int M = 110;
int mp[M][M];
int book[M][M];
int nx[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
struct node
{
    int x;
    int y;
    int step;
    int a[M];
    int b[M];
} qq[M];
int main()
{
    int i, j, k, l, m, n, s = 0;
    node u, v, w;
    queue<node> q;
    memset(book, 0, sizeof(book));
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            cin >> mp[i][j];
    u.x = 0;
    u.y = 0;
    u.step = 0;
    u.a[0] = 0;
    u.b[0] = 0;
    book[u.x][u.y] = 1;
    q.push(u);
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        if (v.x == 4 && v.y == 4)
        {
            for (i = 0; i <= v.step; i++)
                cout << "(" << v.a[i] << ", " << v.b[i] << ")" << endl;
            break;
        }
        w = v;
        for (i = 0; i < 4; i++)
        {
            w.x = v.x + nx[i][0];
            w.y = v.y + nx[i][1];
            if (w.x >= 0 && w.x < 5 && w.y >= 0 && w.y < 5 && book[w.x][w.y] == 0 && mp[w.x][w.y] != 1)
            {
                book[w.x][w.y] = 1;
                w.step = v.step + 1;
                w.a[w.step] = w.x;
                w.b[w.step] = w.y;
                q.push(w);
            }
        }
    }
    return 0;
}