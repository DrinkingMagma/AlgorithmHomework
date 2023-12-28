#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e6 + 1007;
int a[N];

int main()
{
    int n;
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        a[x]++;
    }
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (i == N - 1)
        {
            if (a[i] & 1)
                sum += a[i] + 1;
            else
                sum += a[i];
            break;
        }
        if (!a[i])
            continue;
        if (a[i] % 2 == 0)
        {
            int x = a[i] / 2;
            a[i + 1] += x;
        }
        else
        {
            int x = a[i] / 2;
            a[i + 1] += x;
            sum += 1;
        }
    }
    cout << sum << endl;
    return 0;
}

// 超时
// #include <iostream>
// using namespace std;
// const int N = 1e6 + 100;
// int a[N] = {0};

// int main()
// {
//     int all_nums, num, result = 0;
//     cin >> all_nums;

//     for (int i = 0; i < all_nums; ++i)
//     {
//         cin >> num;
//         a[num] += 1;
//     }

//     for (int i = 0; i < N; ++i)
//     {
//         if (!a[i])
//             continue;
//         if (a[i] & 1)
//         {
//             a[i + 1] += a[i] >> 1;
//             result += 1;
//         }
//         else
//         {
//             a[i + 1] += a[i] >> 1;
//         }
//     }
//     cout << result << endl;

//     return 0;
// }
