#include <iostream>
#include <string>
using namespace std;

int appx(string &word1, string &word2)
{
	int max, count;
	max = 0;
	count = 0;
	int len1 = word1.length();
	int len2 = word2.length();

	// 比较重复
	for (int i = 0; i < len1; i++)
	{
		count = 0;
		for (int j = 0; j < len2 && (i + j) < len1; j++)
		{
			if (word1[i + j] == word2[j])
				count++;
		}
		if (max < count)
			max = count;
	}

	return max;
}

int main()
{
	string word1;
	string word2;
	while (cin >> word1 && word1 != "-1")
	{
		cin >> word2;
		int len1 = word1.length();
		int len2 = word2.length();

		// 重复值，相反两次
		int app1 = appx(word1, word2);
		int app2 = appx(word2, word1);

		if (app1 < app2)
			app1 = app2;

		// 输出格式
		cout << "appx(";
		for (int i = 0; i < len1; i++)
			cout << word1[i];
		cout << ",";
		for (int i = 0; i < len2; i++)
			cout << word2[i];
		cout << ") = ";

		if (app1 == 0)
			cout << "0" << endl;
		else
		{
			app1 *= 2;
			len1 += len2;
			// 化简  (len1 < app1) ? len1:app1  取小
			for (int i = 2; i <= ((len1 < app1) ? len1 : app1); i++)
			{
				while (len1 % i == 0 && app1 % i == 0)
				{
					len1 /= i;
					app1 /= i;
				}
			}
			// 分数or整数
			if (app1 % len1 != 0)
				cout << app1 << "/" << len1 << endl;
			else
				cout << app1 / len1 << endl;
		}
	}
	return 0;
}