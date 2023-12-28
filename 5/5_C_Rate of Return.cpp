#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
#define exp 0.000001
double ans,dis[15],val;
int n,power[15],end;
double cal(double p)
{
    double ret=0;
    for(int i=0;i<n;i++)
        ret+=dis[i]*pow(p,end-power[i]+1);
    return ret;
}
double bin(double L,double R)
{
 
    if(R-L<exp) return L;
    double mid=(L+R)/2;
    double get=cal(mid);
    //printf("->%.5f %.5f %.5f\n",L,R,get);
    if(get>=val) return bin(L,mid);
    else return bin(mid,R);
}
int main()
{
    int cas=1;
    while(scanf("%d",&n) && n!=-1)
    {
        for(int i=0;i<n;i++)
            scanf("%d%lf",&power[i],&dis[i]);
        scanf("%d%lf",&end,&val);
        if(cas>1) printf("\n");
        printf("Case %d: %.05f\n",cas++,bin(1,2)-1);
    }
    return 0;
}