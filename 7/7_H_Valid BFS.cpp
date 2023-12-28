#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int N = 2e5 + 10;
int n, a[N], b[N], p[N];
vector<int> G[N];
bool vis[N];
struct cmp
{
    bool operator()(const int x, const int y) { return p[x] < p[y]; }
};
void bfs()
{
    static queue<int> Q;
    int cnt = 0;
    Q.push(1);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        vis[u] = true;
        b[++cnt] = u;
        for (int i = 0, v; i < static_cast<int>(G[u].size()); ++i)
        {
            v = G[u][i];
            if (vis[v])
                continue;
            Q.push(v);
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        p[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
        sort(G[i].begin(), G[i].end(), cmp());
    bfs();
    for (int i = 1; i <= n; ++i)
        if (a[i] != b[i])
        {
            puts("No");
            return 0;
        }
    puts("Yes");
    return 0;
}