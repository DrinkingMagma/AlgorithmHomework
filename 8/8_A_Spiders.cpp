// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #include <algorithm>
// using namespace std;
// const int maxn = 300;
// struct Node
// {
//     int t;
//     int next;
// };
// Node G[maxn];
// int p[maxn];
// int l;
// void init()
// {
//     l = 0;
//     memset(p, -1, sizeof(p));
// }
// void addedge(int u, int t)
// {
//     G[l].t = t;
//     G[l].next = p[u];
//     p[u] = l++;
// }
// int _max;
// int du[maxn];
// int max1[maxn], max2[maxn];
// int tmp[4];
// void dfs(int u, int fath)
// {
//     max1[u] = max2[u] = -(1 << 25);
//     if (du[u] == 1 && u != 1)
//     {
//         max1[u] = 0;
//         max2[u] = -(1 << 25);
//         return;
//     }
//     for (int i = p[u]; i != -1; i = G[i].next)
//     {
//         int t = G[i].t;
//         if (t == fath)
//             continue;
//         dfs(t, u);
//         tmp[0] = max1[u], tmp[1] = max2[u];
//         tmp[2] = 1 + max1[t];
//         sort(tmp, tmp + 3);
//         max1[u] = tmp[2], max2[u] = tmp[1];
//     }
//     _max = max(_max, max1[u]);
//     _max = max(_max, max1[u] + max2[u]);
// }
// int main()
// {
//     int ci;
//     while (scanf("%d", &ci) == 1)
//     {
//         int ans = 0;
//         while (ci--)
//         {
//             int n;
//             scanf("%d", &n);
//             init();
//             memset(du, 0, sizeof(du));
//             for (int i = 0; i < n - 1; i++)
//             {
//                 int u, v;
//                 scanf("%d%d", &u, &v);
//                 addedge(u, v);
//                 addedge(v, u);
//                 du[u]++, du[v]++;
//             }
//             _max = 0;
//             dfs(1, -1);
//             ans += _max;
//         }
//         printf("%d\n", ans);
//     }
//     return 0;
// }




#include <iostream>
using namespace std;

const int MX=101;
int result, num, sum = 0;

int get_first_edge(int matrix[MX][MX], int node)
{
    for(int i = 1; i <= num; i++)
    {
        if(matrix[node][i] == 1)
        {   
            return i;
        }
    }
    return -1;
}

int get_next_edge(int matrix[MX][MX], int node, int node2)
{
    for(int i = node2 + 1; i <= num; i++)
    {
        if(matrix[node][i] == 1)
        {
            return i;
        }
    }
    return -1;
}

int dfs(int matrix[MX][MX], int visited[], int node)
{
    if(visited[node] == 0)
    {
        visited[node] = 1;
        int deepth = 0;
        for(int i = get_first_edge(matrix, node); i >= 0; i = get_next_edge(matrix, node, i))
        {
            if(visited[i] == 0)
            {
                int len  = dfs(matrix, visited, i);
                if (len > deepth)
                {
                    deepth = len;
                }
            }
        }
        return deepth + 1;
    }

    return 0;
}

void print_matrix(int matrix[MX][MX])
{
    for(int i = 1; i <= num; i++)
    {
        for(int j = 1; j <= num; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int matrix[MX][MX] = {0}, max = 0;

        int node1, node2;
        cin >> num;
        for(int i = 1; i < num; i++)
        {
            cin >> node1 >> node2;

            matrix[node1][node2] = 1;
            matrix[node2][node1] = 1;
        }

        // print_matrix(matrix);

        for(int i = 1; i <= num; i++)
        {
            int visited[num+1] = {0};
            int len = dfs(matrix, visited, i);
            if(len > max)
            {
                max = len;

            }
        }
        sum = sum + max - 1;
        // cout << "max: " << max - 1 << endl;
    }

    cout << sum;

   return 0;
}