#include <cstdio>
#include <queue>
#define Ty int
#define MAXN 102
#define FOR(i, a, b) for (Ty i = a; i <= b; i++)
#define fOR(i, a, b) for (Ty i = a; i < b; i++)
#define ROF(i, a, b) for (Ty i = a; i >= b; i--)
#define rOF(i, a, b) for (Ty i = a; i > b; i--)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int _abs(int a) { return a < 0 ? -a : a; }
ll maxn(ll a, ll b) { return a > b ? a : b; }
int qr()
{
	char ch = getchar();
	int s = 0, x = 1;
	for (; ch < '0' || ch > '9'; ch = getchar())
		if (ch == '-')
			x = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar())
		s = s * 10 + ch - '0';
	return x * s;
}
int n, m, u, v, head[MAXN], nxt[MAXN * MAXN], to[MAXN * MAXN], dis1[MAXN], disn[MAXN], nw;
ll cnt1[MAXN], cntn[MAXN], ans;
queue<int> q;
void addedge(int u, int v, int id)
{
	nxt[id] = head[u];
	to[head[u] = id] = v;
}
int main()
{
	fOR(i, 0, MAXN) dis1[i] = disn[i] = -1;
	n = qr();
	m = qr();
	cnt1[1] = cntn[n] = 1;
	dis1[1] = disn[n] = 0;
	FOR(i, 1, m)
	{
		u = qr();
		v = qr();
		addedge(u, v, i << 1);
		addedge(v, u, i << 1 | 1);
	}
	q.push(1);
	while (q.size())
	{
		nw = q.front();
		q.pop();
		for (int i = head[nw]; i; i = nxt[i])
		{
			if (dis1[to[i]] == -1)
			{
				dis1[to[i]] = dis1[nw] + 1;
				cnt1[to[i]] = cnt1[nw];
				q.push(to[i]);
			}
			else if (dis1[to[i]] == dis1[nw] + 1)
				cnt1[to[i]] += cnt1[nw];
		}
	}
	q.push(n);
	while (q.size())
	{
		nw = q.front();
		q.pop();
		for (int i = head[nw]; i; i = nxt[i])
		{
			if (disn[to[i]] == -1)
			{
				disn[to[i]] = disn[nw] + 1;
				cntn[to[i]] = cntn[nw];
				q.push(to[i]);
			}
			else if (disn[to[i]] == disn[nw] + 1)
				cntn[to[i]] += cntn[nw];
		}
	}
	fOR(i, 2, n) if (dis1[i] + disn[i] == dis1[n]) ans = maxn(ans, cnt1[i] * cntn[i]);
	ans <<= 1;
	if (ans < cnt1[n])
		printf("1");
	else
		printf("%.8lf", (double)ans / cnt1[n]);
	return 0;
}