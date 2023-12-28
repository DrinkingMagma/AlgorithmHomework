#include <bits/stdc++.h>
using namespace std;
int f[1000000000001], v[100000000000001], w[100000000001]; 
int method(int n,int m){//取函数名不要像我一样随便用人名取
	for(int i=1;i<=n;i++)
		for(int j=m;j>=w[i];j--)
			f[j]=max(f[j],f[j-w[i]]+v[i]);
		return f[m];
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>w[i]>>v[i];
	cout<<method(n,m);
	return 0;
}