// #include<iostream>
// #include<cstdio>
// #include<vector>
// #include<cstring>
// using namespace std;
 
// const int maxn=1000+5;
// int k,n;
// vector<int> edge[maxn],Nobe[maxn];
// int fa[maxn];
// bool covered[maxn];
 
// void dfs(int u,int f,int d)
// {
// 	fa[u]=f;
// 	if(edge[u].size()==1&&d>k) Nobe[d].push_back(u);
// 	for(int i=0;i<edge[u].size();i++)
// 	{
// 		int v=edge[u][i];
// 		if(v!=f) dfs(v,u,d+1);
// 	}
// }
// void dfs1(int u,int f,int d)
// {
// 	for(int i=0;i<edge[u].size();i++)
// 	{
// 		int v=edge[u][i];
// 		if(d<k&&v!=f)
// 		{
// 			covered[v]=true;
// 			dfs1(v,u,d+1);
// 		}
// 	}
// }
// int check()
// {
// 	int ans=0;
// 	memset(covered,0,sizeof(covered));
// 	for(int i=n-1;i>k;i--)
// 		for(int j=0;j<Nobe[i].size();j++)
// 		{
// 			int u=Nobe[i][j];
// 			if(covered[u]) continue;
// 			int k1=k;
// 			while(k1--) u=fa[u];
// 			dfs1(u,-1,0);
// 			ans++;
// 		}
// 	return ans;
// }
// int main()
// {
// 	int T;
// 	cin>>T;
// 	while(T--)
// 	{
// 		int s,a,b;
// 		scanf("%d%d%d",&n,&s,&k);
// 		for(int i=1;i<=n;i++)
// 		{
// 			edge[i].clear();
// 			Nobe[i].clear();
// 		}
// 		for(int i=0;i<n-1;i++)
// 		{
// 			scanf("%d%d",&a,&b);
// 			edge[a].push_back(b);
// 			edge[b].push_back(a);
// 		}
// 		dfs(s,-1,0);
// 		printf("%d\n",check());
// 	}
// 	return 0;
// }

#include <iostream>
#include <vector>
#include <cstring>

const int maxn = 1000 + 5;

std::vector<int> edge[maxn], Nobe[maxn];
int fa[maxn];
bool covered[maxn];

void dfs(int u, int f, int d, int k) {
    fa[u] = f;
    if (edge[u].size() == 1 && d > k) {
        Nobe[d].push_back(u);
    }
    for (int v : edge[u]) {
        if (v != f) {
            dfs(v, u, d + 1, k);
        }
    }
}

void dfs1(int u, int f, int d, int k) {
    for (int v : edge[u]) {
        if (d < k && v != f) {
            covered[v] = true;
            dfs1(v, u, d + 1, k);
        }
    }
}

int check(int n, int k) {
    int ans = 0;
    std::memset(covered, 0, sizeof(covered));
    for (int i = n - 1; i > k; i--) {
        for (int u : Nobe[i]) {
            if (covered[u]) {
                continue;
            }
            int k1 = k;
            while (k1--) {
                u = fa[u];
            }
            dfs1(u, -1, 0, k);
            ans++;
        }
    }
    return ans;
}

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int s, a, b;
        int n, k;
        std::cin >> n >> s >> k;

        for (int i = 1; i <= n; i++) {
            edge[i].clear();
            Nobe[i].clear();
        }

        for (int i = 0; i < n - 1; i++) {
            std::cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }

        dfs(s, -1, 0, k);
        std::cout << check(n, k) << std::endl;
    }
    return 0;
}
