#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define MAX 105

char str[MAX];
int dp[MAX][MAX];
int len;

inline int max(int a,int b)
{
 return a > b ? a : b;
}

int main()
{
// freopen("input.txt","r",stdin);
 while(scanf("%s",str) != EOF)
 {
  if(strcmp(str,"end") == 0)
   break;

  memset(dp,0,sizeof(dp));
  len = strlen(str);
  for(int p = 0; p < len; ++p)
  {
   for(int i = 0, j = p; j < len; ++i, ++j)
   {
    if( (str[i] == '(' && str[j] == ')') || (str[i] == '[' && str[j] == ']') )
     dp[i][j] = max(dp[i][j],dp[i+1][j-1]+2);
    for(int k = i; k < j; ++k)
     dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+1][j]);
   }
  }
  printf("%d\n",dp[0][len-1]);
 }
 return 0;
}