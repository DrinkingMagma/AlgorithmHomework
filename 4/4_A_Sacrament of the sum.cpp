#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MX = 1000000;
int arr[MX];

int main()
{
    int N1, N2, a, b;
    memset(arr, 0, sizeof(arr));
    scanf("%d", &N1);
    for (int i = 1; i <= N1; i++)
    {
        scanf("%d", &a);
        arr[a + 50000] = 1;
    }

    int num = 0;
    scanf("%d", &N2);
    for (int i = 1; i <= N2; i++)
    {
        scanf("%d", &b);
        if (arr[-b + 60000])
        {
            num++;
        }
    }

    if (num == 0)
        printf("NO");
    else
        printf("YES");
    return 0;
}