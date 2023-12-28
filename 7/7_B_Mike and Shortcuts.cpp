// #include <iostream>
// #include <cstring>
// #include <queue>
// using namespace std;
// const int maxn = 2e5 + 10;
// int n, d[maxn], vis[maxn];
// struct node
// {
//     int num1, num2, num3, self;
// }e[maxn];
// void bfs(node s)
// {
//     queue<node> q;
//     q.push(s);
//     vis[1] = 1;
//     node n;
//     while (!q.empty())
//     {
//         n = q.front();
//         q.pop();
//         if (!vis[n.num1])
//         {
//             q.push(e[n.num1]);
//             vis[n.num1] = 1;
//             d[n.num1] = d[n.self] + 1;
//         }
//         if (!vis[n.num2])
//         {
//             q.push(e[n.num2]);
//             vis[n.num2] = 1;
//             d[n.num2] = d[n.self] + 1;
//         }
//         if (n.num3 && !vis[n.num3])
//         {
//             q.push(e[n.num3]);
//             vis[n.num3] = 1;
//             d[n.num3] = d[n.self] + 1;
//         }
//     }
// }
// int main()
// {
//     while (cin >> n)
//     {
//         int x;
//         memset(vis, 0, sizeof(vis));
//         for (int i = 1; i <= n; i++)
//         {
//             e[i].num1 = i - 1;
//             e[i].num2 = i + 1;
//             e[i].num3 = 0;
//             e[i].self = i;
//             cin >> x;
//             if (x != i)
//                 e[i].num3 = x;
//         }
//         bfs(e[1]);
//         for (int i = 1; i <= n; i++)
//         {
//             cout << d[i] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 2e5 + 10;

struct node
{
    int num1, num2, num3, self;
};

void bfs(node e[], int n, int vis[])
{
    queue<node> q;
    q.push(e[1]);
    int d[maxn] = {0};
    vis[1] = 1;
    node m;
    while (!q.empty())
    {
        m = q.front();
        q.pop();
        if (!vis[m.num1])
        {
            q.push(e[m.num1]);
            vis[m.num1] = 1;
            d[m.num1] = d[m.self] + 1;
        }
        if (!vis[m.num2])
        {
            q.push(e[m.num2]);
            vis[m.num2] = 1;
            d[m.num2] = d[m.self] + 1;
        }
        if (m.num3 && !vis[m.num3])
        {
            q.push(e[m.num3]);
            vis[m.num3] = 1;
            d[m.num3] = d[m.self] + 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    while (cin >> n)
    {
        node e[maxn];
        memset(e, 0, sizeof(e));
        int vis[maxn] = {0};
        for (int i = 1; i <= n; i++)
        {
            e[i].num1 = i - 1;
            e[i].num2 = i + 1;
            e[i].num3 = 0;
            e[i].self = i;
            int x;
            cin >> x;
            if (x != i)
                e[i].num3 = x;
        }
        bfs(e, n, vis);
    }
    return 0;
}
