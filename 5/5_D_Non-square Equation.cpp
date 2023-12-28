#include <cmath>
#include <cstdio>
using namespace std;

int get(__int64 x)
{
    int sum = 0;
    while (x)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
int main()
{
    __int64 n, ans = -1;
    scanf("%I64d", &n);
    for (int i = 1; i <= 81; ++i)
    {
        __int64 x = sqrt(i * i / 4 + n) - i / 2;
        int sx = get(x);
        if (x * x + sx * x - n == 0)
        {
            ans = x;
            break;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}