#include <cstdio>
#include <cstring>
using namespace std;

struct node
{
	int m[3][3];
};
node a, e;
node mult(node a, node b)
{
	node c;
	memset(c.m, 0, sizeof(c.m));
	for (int i = 1; i < 3; i++)
	{
		for (int j = 1; j < 3; j++)
		{
			for (int k = 1; k < 3; k++)
			{
				c.m[i][j] += (a.m[i][k] * b.m[k][j]) % 10000;
			}
		}
	}
	return c;
}
// 矩阵的快速幂
node cal(node a, int n)
{
	node res;
	res = e;
	while (n)
	{
		if (n % 2)
			res = mult(a, res);
		a = mult(a, a);
		n = n / 2;
	}
	return res;
}

int main()
{
	a.m[1][1] = 1;
	a.m[1][2] = 1;
	a.m[2][1] = 1;
	a.m[2][2] = 0;
	e.m[1][1] = 1;
	e.m[1][2] = 0;
	e.m[2][1] = 0;
	e.m[2][2] = 1;
	int n;
	while (~scanf("%d", &n) && n >= 0)
	{
		node ans;
		ans = cal(a, n);
		printf("%d\n", ans.m[1][2] % 10000);
	}
	return 0;
}