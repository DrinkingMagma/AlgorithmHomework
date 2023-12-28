#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int put[4010][10], sum1[16000010], sum2[16000010];
int main()
{
    int n, mid;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d %d %d", &put[i][0], &put[i][1], &put[i][2], &put[i][3]);
        }
        int first = 0, second = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sum1[first] = put[i][0] + put[j][1];
                first++;
                sum2[second] = put[i][2] + put[j][3];
                second++;
            }
        }
        sort(sum2, sum2 + second);
        int ans = 0;
        for (int i = 0; i < first; i++)
        {
            int left = 0;
            int right = second - 1;
            while (right >= left)
            {
                mid = (left + right) / 2;
                if (sum1[i] + sum2[mid] == 0)
                {
                    for (int j = mid; j < second; j++)
                    {
                        if (sum1[i] + sum2[j] != 0)
                            break;
                        else
                            ans++;
                    }
                    for (int j = mid - 1; j >= 0; j--)
                    {
                        if (sum1[i] + sum2[j] != 0)
                            break;
                        else
                            ans++;
                    }
                    break;
                }
                if (sum1[i] + sum2[mid] < 0)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
