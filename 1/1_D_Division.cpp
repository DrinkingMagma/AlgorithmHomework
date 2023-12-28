#include <stdio.h>
#include <string.h>

int judge(char s[])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (s[i] == s[j])
				return 0;
		}
	}
	return 1;
}

int main()
{
	int n, fg = 1;
	while (scanf("%d", &n) && n != 0)
	{
		if (fg)
			fg = 0;
		else
			printf("\n");
		int flag = 0;
		char s[10] = {0};
		for (int i = 1234; i < 98765; i++)
		{
			int t = 9;
			int m = i;
			while (m) // ①
			{
				s[t--] = m % 10;
				m /= 10;
			}
			int k = n * i;
			if (k >= 100000)
				break;
			else
			{
				int q = 4;
				while (k)
				{
					s[q--] = k % 10;
					k /= 10;
				}
				// puts(s);
				if (judge(s))
				{
					flag = 1;
					for (int j = 0; j < 10; j++)
					{
						if (j == 5)
							printf(" / ");
						printf("%d", s[j]);
					}
					printf(" = %d\n", n);
				}
			}
		}
		if (!flag)
			printf("There are no solutions for %d.\n", n);
	}
	return 0;
}