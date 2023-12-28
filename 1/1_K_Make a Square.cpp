#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, num1, num2;
string str1, str2;

int main()
{
	scanf("%d", &n);
	num1 = 0;
	int INF = -1;
	for (int k = 1; k * k <= n; k++)
	{
		int ans = k * k;
		str2 = to_string(ans);
		str1 = to_string(n);
		int i = 0, j = 0;
		int flag = 0;
		while (i < str2.size())
		{
			while (j < str1.size() && str1[j] != str2[i])
			{
				j++;
			}
			if (j == str1.size())
				flag = 1;
			i++;
			j++;
		}
		if (!flag)
			INF = str1.size() - str2.size();
	}
	if (INF == -1)
		cout << "-1" << endl;
	else
		cout << INF << endl;
	return 0;
}