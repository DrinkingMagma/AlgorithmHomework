#include <iostream>
#include <cstring>
using namespace std;

int sum, num;
int a[1000000];                                   // 储存某一个数字是否已经走出来过
int grid[5][5];                                   // 用于记录格子中每格的数据
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1}; // 用于上、下、左、右的移动

void dfs(int x, int y, int k)
{
    if (k == 6)
    {
        if (a[num] == 0)
        {
            sum++;
            a[num] = 1; // 已经走出来过该数字则记录该点状态值为1
            return;
        }
        else
            return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
        {
            num *= 10;
            num += grid[nx][ny];
            dfs(nx, ny, k + 1);
            num /= 10; // 此处注意把num变回来，因为还要进行下一次循环
        }
    }
    return;
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            cin >> grid[i][j];
    }

    memset(a, 0, sizeof(a));
    sum = 0, num = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            dfs(i, j, 0);
    }
    cout << sum << endl;
}
