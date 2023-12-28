#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
const int MAX = 0x7fffffff;
int map[1005][1005];
struct p
{
    int p, shests, shestt; // p是点的序号，shests和shestt分别是到s,t的最短路径
} p[1005];
int min(int a, int b)
{
    return a < b ? a : b;
}
bool cmp(struct p a, struct p b)
{
    if (a.shests != b.shests)
        return a.shests < b.shests;
    return a.shestt < b.shestt;
}
int main()
{
    vector<int> jc;
    int i, j, n, m, s, t, u, v, k, x, ans, sum(0);
    cin >> n >> m >> s >> t;
    for (i = 0; i <= n; i++)
    {
        p[i].shests = MAX;
        p[i].shestt = MAX;
        p[i].p = i;
    } // 初始化
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        map[u][v] = 1;
        map[v][u] = 1;
    }                // 读入，用邻接矩阵储存两个点的相连关系
    jc.push_back(s); // Dijkstra
    p[s].shests = 0;
    for (x = 0, k = 1; k != x; x++)
    {
        i = jc[x];
        for (j = 1; j <= n; j++)
            if (map[i][j] && (p[j].shests > p[i].shests + 1))
                p[j].shests = p[i].shests + 1, jc.push_back(j), k++;
    }
    jc.clear();
    jc.push_back(t); // 再一次Dijkstra
    p[t].shestt = 0;
    for (x = 0, k = 1; k != x; x++)
    {
        i = jc[x];
        for (j = 1; j <= n; j++)
            if (map[i][j] && (p[j].shestt > p[i].shestt + 1))
                p[j].shestt = p[i].shestt + 1, jc.push_back(j), k++;
    }
    //    sort(p+1,p+n+1,cmp);
    /*    cout<<endl;
        for(i=1;i<=n;i++) cout<<p[i].p<<" "<<p[i].shests<<" "<<p[i].shestt<<endl;
        cout<<endl;*/

    ans = p[t].shests;

    for (i = 1; i < n; i++)
    {
        for (j = i + 1; j <= n; j++) // 检查每一个点对
            if (!map[p[i].p][p[j].p] && (p[i].shests + p[j].shestt + 1 < ans || p[i].shestt + p[j].shests + 1 < ans))
            { //        cout<<p[i].p<<" "<<p[j].p<<endl;
                sum++;
            }
    } //    cout<<sum<<endl;
    cout << n * (n - 1) / 2 - m - sum << endl;
    return 0;
}