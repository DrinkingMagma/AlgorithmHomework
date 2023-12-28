#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
const ll maxn = 3e5 + 7;
ll id[maxn];
struct Node
{
    ll c, t;
    bool operator<(const Node &rhs) const
    {
        return c < rhs.c;
    }
} nodes[maxn];
priority_queue<Node> Q;

int main()
{
    ll n, k;
    scanf("%lld%lld", &n, &k);
    for (ll i = 1; i <= n; i++)
    {
        scanf("%lld", &nodes[i].c);
        nodes[i].t = i;
    }

    for (ll i = 1; i <= k; i++)
        Q.push(nodes[i]);

    ll ans = 0;
    for (ll i = k + 1; i <= n + k; i++)
    {
        if (i <= n)
            Q.push(nodes[i]);
        Node tmp = Q.top();
        Q.pop();
        ans += tmp.c * (i - tmp.t);
        id[tmp.t] = i;
    }
    printf("%lld\n", ans);
    for (ll i = 1; i <= n; i++)
        printf("%lld ", id[i]);
    return 0;
}
