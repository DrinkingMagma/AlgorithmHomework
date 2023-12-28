#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#define N 82
using namespace std;
string a,b;
int i,j,la,lb,f[N][N],f1[N][N],f2[N][N];
vector<string> v;
void dfs(int x,int y,string s,int l)
{
    if(x<0||y<0) return;
    if(l<=0){
        v.push_back(s);
        return;
    }
    for(int i=0;i<26;i++){
        int p1=f1[i][x],p2=f2[i][y];
        if(f[p1][p2]>=l){
            char c='a'+i;
            dfs(p1-1,p2-1,c+s,l-1);
        }
    }
}
int main()
{
    cin>>a>>b;
    la=a.length();
    lb=b.length();
    for(i=la;i>=1;i--) a[i]=a[i-1];
    for(i=lb;i>=1;i--) b[i]=b[i-1];
    for(i=1;i<=la;i++){
        for(j=1;j<=lb;j++){
            f[i][j]=max(f[i-1][j],f[i][j-1]);
            if(a[i]==b[j]) f[i][j]=max(f[i][j],f[i-1][j-1]+1);
        }
    }
    for(i=0;i<26;i++){
        for(j=1;j<=la;j++){
            if(a[j]=='a'+i) f1[i][j]=j;
            else f1[i][j]=f1[i][j-1];
        }
        for(j=1;j<=lb;j++){
            if(b[j]=='a'+i) f2[i][j]=j;
            else f2[i][j]=f2[i][j-1];
        }
    }
    int len=f[la][lb];
    dfs(la,lb,"",len);
    sort(v.begin(),v.end());
    for(i=0;i<v.size();i++) cout<<v[i]<<endl;
    return 0;
}