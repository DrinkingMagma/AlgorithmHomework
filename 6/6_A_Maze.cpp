#include <iostream>
#include <cstring>
#include <string>
using namespace std;
char mp[505][505];
int vis[505][505], n, m, k;
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0}; // 右 左 下 上
void dfs(int x, int y)
{
	if (k == 0)
		return;
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		// 若超出边界，则跳过
		if (xx < 1 || xx > n || yy < 1 || yy > m)
			continue;
		if (!vis[xx][yy] && mp[xx][yy] == '.')
		{
			vis[xx][yy] = 1;
			dfs(xx, yy);
			
			if (k)
			{
				mp[xx][yy] = 'X';
				k--;
			}
		}
	}
}
int main()
{
	while (~scanf("%d %d %d", &n, &m, &k))
	{
		memset(vis, 0, sizeof(vis));
		getchar();
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				scanf("%c", &mp[i][j]);
				if (mp[i][j] == '#')
					vis[i][j] = 1;
			}
			getchar();
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (mp[i][j] == '.')
				{
					vis[i][j] = 1;
					dfs(i, j);
					break;
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				printf("%c", mp[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}