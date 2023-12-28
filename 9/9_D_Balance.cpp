#include<iostream>
#include<cstring>
using namespace std;
 
int dp[25][15001];
int pos[25],wei[25];
 
int main()
{
    int c,g;
    int i,j,k;
 
    while(cin>>c>>g)
    {
        for(i=1; i<=c; i++)
            cin>>pos[i];
        for(i=1; i<=g; i++)
            cin>>wei[i];
 
        memset(dp,0,sizeof(dp));
        dp[0][7500]=1;    //一个砝码也不挂
 
        for(i=1; i<=g; i++)   //g个砝码
            for(j=0; j<=15000; j++)
                if(dp[i-1][j])  //说明可以在往上面挂
                    for(k=1; k<=c; k++)   //c个位置
                        dp[i][j+wei[i]*pos[k]]+=dp[i-1][j];
 
        cout<<dp[g][7500]<<endl;
    }
    return 0;
}