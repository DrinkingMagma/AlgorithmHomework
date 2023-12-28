#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int MX = 1e5 + 5;

struct node
{
    int x, num, ans;
} a[MX];

bool cmp1(node a, node b)
{
    return a.x < b.x;
}

bool cmp2(node a, node b)
{
    return a.num < b.num;
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int need = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i].x);
        a[i].num = i;
        need += (a[i].x + 1) / 2;
    }
    if (need > k)
    {
        printf("-1\n");
        return 0;
    }
    sort(a + 1, a + n + 1, cmp1);
    for (int i = 1; i <= n; i++)
    {
        a[i].ans = (a[i].x + 1) / 2;
        k -= a[i].ans;
    }
    // cout << k << endl;
    for (int i = n; i >= 1; i--)
    {
        if (k >= (a[i].x - a[i].ans))
        {
            k -= (a[i].x - a[i].ans);
            a[i].ans = a[i].x;
        }
        else
        {
            a[i].ans += k;
            break;
        }
    }
    sort(a + 1, a + 1 + n, cmp2);
    printf("%d", a[1].ans);
    for (int i = 2; i <= n; i++)
    {
        printf(" %d", a[i].ans);
    }
    printf("\n");
    return 0;
}