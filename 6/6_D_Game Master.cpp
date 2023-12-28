// #define inf 0x3f3f3f3f
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 2e5 + 10;
// typedef long long ll;
// struct node
// {
// 	int a, b, inx, w;
// 	bool operator<(const node &x) const
// 	{
// 		return a < x.a;
// 	}
// } p[N];
// int a[N], b[N];
// int A[N], B[N];
// bool cmp(node &a, node &b)
// {
// 	return a.inx < b.inx;
// }
// int main()
// {
// 	int t;
// 	cin >> t;
// 	while (t--)
// 	{
// 		int n;
// 		cin >> n;
// 		for (int i = 1; i <= n; i++)
// 			p[i].w = 0;
// 		for (int i = 1; i <= n; i++)
// 			cin >> a[i], A[i] = a[i];
// 		for (int i = 1; i <= n; i++)
// 			cin >> b[i], B[i] = b[i];
// 		sort(A + 1, A + n + 1);
// 		sort(B + 1, B + 1 + n);
// 		int index1 = unique(A + 1, A + n + 1) - A - 1;
// 		int index2 = unique(B + 1, B + n + 1) - B - 1;
// 		for (int i = 1; i <= n; i++)
// 		{
// 			p[i].inx = i;
// 			p[i].a = lower_bound(A + 1, A + 1 + index1, a[i]) - A;
// 			p[i].b = lower_bound(B + 1, B + 1 + index2, b[i]) - B;
// 		}
// 		sort(p + 1, p + 1 + n);
// 		int ans1 = 0, ans2 = 0;
// 		int f = 1;

// 		for (int i = 1; i < n; i++)
// 		{
// 			ans1 += p[i].a;
// 			ans2 += p[i].b;
// 			if (ans1 == ans2)
// 				f = i + 1;
// 		}
// 		for (int i = f; i <= n; i++)
// 		{
// 			p[i].w = 1;
// 		}
// 		sort(p + 1, p + 1 + n, cmp);
// 		for (int i = 1; i <= n; i++)
// 			cout << p[i].w;
// 		cout << endl;
// 	}
// 	return 0;
// }

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 2e5 + 10;

struct Node
{
    int a, b, index, w;
};

bool cmp(const Node &a, const Node &b)
{
    return a.index < b.index;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n + 1), b(n + 1);
    vector<int> A(n + 1), B(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], A[i] = a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i], B[i] = b[i];

    sort(A.begin() + 1, A.end());
    sort(B.begin() + 1, B.end());

    auto it1 = unique(A.begin() + 1, A.end());
    auto it2 = unique(B.begin() + 1, B.end());

    int index1 = distance(A.begin(), it1) - 1;
    int index2 = distance(B.begin(), it2) - 1;

    vector<Node> p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        p[i].index = i;
        p[i].a = lower_bound(A.begin() + 1, A.begin() + index1 + 1, a[i]) - A.begin();
        p[i].b = lower_bound(B.begin() + 1, B.begin() + index2 + 1, b[i]) - B.begin();
    }

    sort(p.begin() + 1, p.end(), [](const Node &a, const Node &b) {
        return a.a < b.a;
    });

    int ans1 = 0, ans2 = 0;
    int f = 1;

    for (int i = 1; i < n; i++)
    {
        ans1 += p[i].a;
        ans2 += p[i].b;
        if (ans1 == ans2)
            f = i + 1;
    }

    for (int i = f; i <= n; i++)
    {
        p[i].w = 1;
    }

    sort(p.begin() + 1, p.end(), cmp);

    for (int i = 1; i <= n; i++)
        cout << p[i].w;

    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
