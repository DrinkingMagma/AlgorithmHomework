#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
double a[10001], pi = acos(-1.0);
int f, n;
int dao(double size)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += int(a[i] / size);
    }
    if (sum >= f + 1)
        return 1;
    else
        return 0;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        double low, high, mid, ans = -1, v = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lf", &a[i]);
            a[i] = a[i] * a[i] * pi;
            v += a[i];
        }
        low = 0;
        high = v / (f + 1);
        while (high - low > 0.000001)
        {
            mid = (high + low) / 2;
            if (dao(mid))
            {
                low = mid;
            }
            else
                high = mid;
        }
        printf("%.4lf\n", mid);
    }
    return 0;
}