#include<bits/stdc++.h>
using namespace std;
const int MX = 2 * 1e5 +5;

struct node{
    int x,y,z;// x表示折扣前的价格，y表示打折后的价格 z表示折扣前-打折后
}a[MX];

bool cmp(node a,node b)
{
    return a.z<b.z;
}

int main()
{
    int n,k,num=0,sum=0;
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i].x;
    }
    for(int i=1; i<=n; i++)
    {
        cin>>a[i].y;
    }
    for(int i=1; i<=n; i++)
    {
        a[i].z = a[i].x - a[i].y;
        if(a[i].z<0) num++; //记录折扣为负的个数
    }
    sort(a+1,a+n+1,cmp);//按z从小到大排序

    if(num >= k)//折扣为负的数大于等于最小先购买数，先把折扣为负的都买了
    {
        for(int i=1; i<=num; i++)
        {
            sum +=a[i].x;
        }
        for(int i=num+1; i<=n; i++)
        {
            sum +=a[i].y;
        }
    }
    else
    {
        for(int i=1; i<=k; i++)
        {
            sum +=a[i].x;
        }
        for(int i=k+1; i<=n; i++)
        {
            sum +=a[i].y;
        }
    }
    cout<<sum<<endl;
}
