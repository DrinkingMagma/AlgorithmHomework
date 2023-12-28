#include <iostream>
using namespace std;
int a[105][105];
int maxsum = 0,n;
void dp(int num, int r)
{
     int cur_num = 0,cur_sum = 0;//记录当前高度，当前最大和。
     for(int j = 1; j <= n; j++){
        cur_num +=  a[r + num - 1][j]-a[ r - 1][j];
//找出以i为上顶，高度为high的最大矩阵，先得到s1，s2，s3.....Sn，其中，Sk=a[i+high-1][k] - a[i-1][k].
    if(cur_num > cur_sum)
         cur_sum = cur_num;  
    else if(cur_num < 0)
          cur_num = 0 ;
    }
    if(cur_sum > maxsum)
       maxsum = cur_sum; //更新最大和
}
int main(){
    int temp;
    while(scanf("%d",&n)!=EOF)
   {
     for(int i =1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                 scanf("%d",&temp);
                 a[i][j] = a[i - 1][j] + temp;
             }
      }
   //这里a[i][j]表示第i行前j列元素的和。  
      for(int i = 1;i <= n; i++){
            for(int j = 1;j <= n-i+1; j++){
                 dp(i,j);//以样例分析，如果高度为1 ，需要算出，以第一行到第4行为上顶的矩形和中最大的。......如果高度为4，只需要算出第1行为上顶的矩形和。
             }
      }
     
     printf("%d\n",maxsum);     
 }
    return 0;
}