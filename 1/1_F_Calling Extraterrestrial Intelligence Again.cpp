#include <iostream>
#include <cmath>
using namespace std;
int p[5000], m, a, b;

void pr()
{
	int i, j = 1, n = 3;
	p[1] = 2;
	while (j < 4999)
	{
		for (i = 1; p[i] * p[i] <= n; i++)
			if (n % p[i] == 0)
				break;
		if (p[i] * p[i] > n)
			p[++j] = n;
		n += 2;
	}
}
int find(int n)
{
	int i;
	for (i = 1; i < 5000 && p[i] <= n; i++)
		;
	return i - 1;
}
int main()
{
	pr();
	while (cin >> m >> a >> b && m)
	{
		int i, j, k, ma = 1, mb = 1;
		double B = double(a) / double(b);
		for (i = find(int(sqrt(double(m)))); i > 0; i--)
		{
			for (j = i; p[i] * p[j] <= m; j++)
			{
				if (p[i] * p[j] <= m && double(p[i]) / double(p[j]) >= B && p[i] * p[j] > ma * mb)
				{
					ma = p[i];
					mb = p[j];
				}
			}
		}
		cout << ma << ' ' << mb << endl;
	}
	return 0;
}
