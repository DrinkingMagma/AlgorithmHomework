#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
char str[100];
bool cmp(int a, int b)
{
	if (tolower(a) == tolower(b))
		return a < b; // 从小到大排序
	else
		return tolower(a) < tolower(b); // 按小写字母从小到大排序
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> str;
		sort(str, str + strlen(str), cmp);
		do
		{
			cout << str << endl;
		} while (next_permutation(str, str + strlen(str), cmp));
	}

	return 0;
}