#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef struct Path
{
	int y;
	int x;
} Path;

Path path[1001];

bool isFound = false;
int p, q;
bool mark[51][51];

int dir[8][2] = {
	{-1, -2},
	{1, -2},
	{-2, -1},
	{2, -1},
	{-2, 1},
	{2, 1},
	{-1, 2},
	{1, 2},
};

// p * q
bool isInMap(int ny, int nx)
{

	if (nx >= 1 && nx <= q && ny >= 1 && ny <= p)
	{
		return 1;
	}
	return 0;
}

void dfs(int y, int x, int step)
{
	//	cout << "current:" << y <<" "<< x << endl;
	if (step == p * q)
	{
		//		cout << "out!!! :" << step << endl;
		for (int i = 1; i <= step; i++)
		{
			cout << char(path[i].x + 'A' - 1) << path[i].y;
		}
		cout << endl;
		isFound = 1;
		return;
	}

	int ny;
	int nx;

	for (int i = 0; i <= 7; i++)
	{
		ny = y + dir[i][0];
		nx = x + dir[i][1];

		if (isFound == 0)
		{
			if (isInMap(ny, nx) == 1 && mark[ny][nx] == 0)
			{
				path[step + 1].y = ny;
				path[step + 1].x = nx;
				mark[ny][nx] = 1;
				// dfs
				dfs(ny, nx, step + 1);
				// 回溯
				mark[ny][nx] = 0;
			}
		}
	}
}

int main()
{

	int caseNum;
	cin >> caseNum;
	for (int caseNo = 1; caseNo <= caseNum; caseNo++)
	{
		cin >> p >> q;
		isFound = false;

		for (int i = 1; i <= p; i++)
		{
			for (int j = 1; j <= q; j++)
			{
				mark[i][j] = 0;
			}
		}

		path[1].y = 1;
		path[1].x = 1;
		mark[1][1] = 1;

		cout << "Scenario #" << caseNo << ":" << endl;
		dfs(1, 1, 1);

		if (!isFound)
		{
			cout << "impossible" << endl
				 << endl;
		}
		else
		{
			cout << endl;
		}
	}
}