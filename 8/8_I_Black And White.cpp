#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,k,flag,col[100];
int Map[10][10];
int dir[4][2]= {0,1,1,0,0,-1,-1,0};
bool check(int c,int x,int y)
{
    for(int i=0; i<4; i++)
    {
        int tx=x+dir[i][0];
        int ty=y+dir[i][1];
        if(c==Map[tx][ty])
            return false;
    }
    return true;
}
void dfs(int x,int y,int step)
{
    if(flag)return;
    if(step==n*m)
    {
        flag=1;
        printf("YES\n");
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<m; j++)
                printf("%d ",Map[i][j]);
            printf("%d\n",Map[i][m]);
        }
        return;
    }
    for(int i=1; i<=k; i++) //如果到达这个状态的时候，有些颜色剩余过多就不能完成完整的染色
    {
        //如果还剩颜色a（5个），那么最少还需其他颜色（3个）才能保证a不会相邻
        if(col[i]>(n*m-step+1)/2)
            return;
    }
    for(int i=1; i<=k; i++)
    {
        if(col[i]>0&&check(i,x,y))
        {
            int tx=x;
            int ty=y+1;
            if(ty>m){tx++,ty=1;}
            Map[x][y]=i;
            col[i]--;
            dfs(tx,ty,step+1);
            Map[x][y]=-1;
            col[i]++;
        }
    }
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        memset(Map,-1,sizeof(Map));
        for(int i=1; i<=k; i++)
            scanf("%d",&col[i]);
        flag=0;
        printf("Case #%d:\n",cas++);
        dfs(1,1,0);
        if(!flag)printf("NO\n");
    }
    return 0;
}