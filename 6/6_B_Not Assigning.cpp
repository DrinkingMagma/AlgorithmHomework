#include <iostream>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
const int N = 2e5 + 100;
typedef pair<int, int> PII;
int n;
int e[N], h[N], ne[N], w[N], idx;
bool st[N];

map<PII, int> mp;

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u, int t)
{
	st[u] = true;
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (!st[j])
		{
			st[j] = true;
			mp[{u, j}] = mp[{j, u}] = t;
			dfs(j, t ^ 1);
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		cin >> n;

		memset(st, false, sizeof st);
		vector<int> d(n + 1, 0);
		vector<PII> c;
		idx = 0;

		memset(h, -1, sizeof h);
		for (int i = 0; i < n - 1; i++)
		{
			int a, b;
			cin >> a >> b;
			add(a, b);
			add(b, a);
			c.push_back({a, b});
			d[a]++, d[b]++;
		}

		bool f = 0;
		for (int i = 1; i <= n; i++)
		{
			if (d[i] > 2)
			{
				f = 1;
				break;
			}
		}

		if (f)
		{
			cout << -1 << endl;
			continue;
		}

		for (int i = 1; i <= n; i++)
			if (d[i] == 1)
			{
				dfs(i, 2);
				break;
			}

		for (int i = 0; i < n - 1; i++)
		{
			int a = c[i].first, b = c[i].second;
			cout << mp[{a, b}] << " ";
		}
		cout << endl;
	}

	return 0;
}
