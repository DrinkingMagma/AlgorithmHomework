#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
 
int dp[1015][105];
int a[105];
 
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	for(int j=0;j<=m;j++)
	{
		for(int k=0;k<=min(a[i],j);k++)
		dp[i][j]=(dp[i][j]+dp[i-1][j-k])%1000007;
	}
	cout<<dp[n][m]<<endl;
	return 0;
}