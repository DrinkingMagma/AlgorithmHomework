#include<math.h>
#include<stdio.h> 
#include<string.h>
 
int N,Fence[45];
 
bool F[805][805];
 
int inline IntMax(int A,int B)
{
	return A>B?A:B;
}
 
bool inline ConsTrig(int A,int B,int C)
{
	return (A+B>C)&&(A+C>B)&&(B+C>A);
}
 
int inline TrigArea(int A,int B,int C)
{
	double p=(A+B+C)/2.00;
	double s=sqrt(p*(p-A)*(p-B)*(p-C));
	return (int)(s*100);
}
 
int main()
{
	while(scanf("%d",&N)==1)
	{
		//读取数据
		int sum=0;
		for(int i=0;i<N;++i)
		{
			scanf("%d",&Fence[i]);
			sum+=Fence[i];
		}
		int half=((sum+1)>>1);
		//背包DP
		memset(F,0,sizeof(F));
		F[0][0]=1;
		for(int i=0;i<N;++i)
		{
			for(int j=half;j>=0;--j)
			{
				for(int k=j;k>=0;--k) 
				{
					F[j][k]=((F[j][k])||(j>=Fence[i]&&F[j-Fence[i]][k]));
					F[j][k]=((F[j][k])||(k>=Fence[i]&&F[j][k-Fence[i]]));					
				}
			}
		}
		//获取答案
		int ans=-1;
		for(int i=1;i<=half;++i)
		{
			for(int j=half-i+1;j<=i;++j) 
			{
				int k=sum-i-j;
				if(F[i][j]&&ConsTrig(i,j,k)) 
				{
					ans=IntMax(ans,TrigArea(i,j,k));
				}
			}
		}
		printf("%d\n",ans);
	}  
	return 0;
}