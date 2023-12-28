#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int dp[100005],a[105],N,cash;
int main()
{
	while(cin>>cash>>N)
	{
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		int m=0;
		for(int i=1;i<=N;i++)
		{
			int nk,dk;
			scanf("%d%d",&nk,&dk);
			for(int k=1;k<=nk;k*=2)
        	{
            	nk-=k;
            	a[m++]=k*dk;
        	}
        	if(nk>0) a[m++]=nk*dk;
		}
		
		for(int i=0;i<m;i++)
		{
			for(int j=cash;j>=0;j--)//在这里只能从大到小枚举，具体原因见多重背包问题
			{
                if (j >= a[i])
                	dp[j] = max(dp[j - a[i]] + a[i], dp[j]);
			}
		}
		printf("%d\n",dp[cash]);
	}
	return 0;
}
