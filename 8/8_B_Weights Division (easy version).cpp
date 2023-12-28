#include <bits/stdc++.h>
using namespace std;
int t, n;
long long S;
struct edge
{
    int x, y, w, subsize;
} edges[100010];

vector<vector<pair<int, int>>> g;
void dfs(int i, int fa)
{
    if (g[i].size() == 1 && i)
    {
        edges[fa].subsize = 1;
        return;
    }
    for (auto &node : g[i])
    {
        if (node.second != fa)
        {
            dfs(node.first, node.second);
            if (fa != -1)
                edges[fa].subsize += edges[node.second].subsize;
        }
    }
}
long long ifremove(int i)
{
    return (edges[i].w - edges[i].w / 2) * (long long)edges[i].subsize;
}
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> S;
        memset(edges, 0, sizeof(edges));
        g = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());
        for (int i = 0; i < n - 1; i++)
        {
            int xi, yi, wi;
            scanf("%d %d %d", &xi, &yi, &wi);
            g[xi - 1].push_back({yi - 1, i});
            g[yi - 1].push_back({xi - 1, i});
            edges[i].x = xi;
            edges[i].y = yi;
            edges[i].w = wi;
        }
        dfs(0, -1);
        set<pair<long long, int>> se;
        long long sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            sum += (long long)edges[i].w * edges[i].subsize;
            se.insert({ifremove(i), i});
        }
        int res = 0;
        while (sum > S)
        {
            int removenode = se.rbegin()->second;
            se.erase(--(se.end()));
            sum -= ifremove(removenode);
            edges[removenode].w /= 2;
            se.insert({ifremove(removenode), removenode});
            res++;
        }
        cout << res << endl;
    }
    return 0;
}
