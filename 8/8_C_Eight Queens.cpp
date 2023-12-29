#include <stdio.h>
int place[8] = {0};											// 皇后位置
int flag[8] = {1, 1, 1, 1, 1, 1, 1, 1};						// 定义列
int d1[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; // 定义上对角线（共有15个对角线,
// 因此定义一个长度为15的数组，初值为1代表该对角线没有被皇后占领，
// 若被皇后占领则赋值为0
int d2[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; // 定义下对角线
int count = 0;												// 记录输出次数
void print()												// 定义输出函数
{
	int i, j;
	count++; // 每调用一次输出函数number自加一次，记录摆放方法个数
	printf("No.%2d\n", count);
	int table[8][8] = {0}; // 设置一个8*8的棋盘
	for (i = 0; i < 8; i++)
	{
		table[i][place[i]] = 1; // 将每一行皇后所在位置赋值为1
	}
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			printf("%d ", table[i][j]);
		}
		printf("\n");
	}
}
int queen(int n) // 定义递归回溯函数
{
	int col;
	for (col = 0; col < 8; col++)
	{
		if (flag[col] && d1[n - col + 7] && d2[n + col]) // 判断皇后是否冲突
		{
			place[n] = col; // 放置皇后
			flag[col] = 0;
			d1[n - col + 7] = 0;
			d2[n + col] = 0; // 将该皇后所在的行、列、对角线设置为被占领
			if (n < 7)
			{
				queen(n + 1);
			} // 当行数小于7时；递归调用下一行
			else
			{
				print();
			}			   // 调用输出函数
			flag[col] = 1; // 回溯
			d1[n - col + 7] = 1;
			d2[n + col] = 1;
		}
	}
	return count;
}
int main()
{
	count = queen(0);			   // 从第0行开始摆放皇后
	// printf("共有%d种方法", count); // 输出摆放皇后的方法个数
	return 0;
}