// #include <bits/stdc++.h>
// using namespace std;
// const int MAXN = 100000 + 10;
// char s[MAXN];

// int main()
// {
//     int flag = -1, t;
//     cin >> s;
//     int n = strlen(s); // 奇数正整数的长度
//     // cout<<n<<endl;
//     for (int i = 0; i < n; i++)
//     {
//         if (s[i] % 2 == 0)
//         {
//             flag = i; // 寻找最后一个偶数
//         }
//     }

//     for (int j = 0; j < n; j++)
//     {
//         if (s[j] % 2 == 0 && s[j] < s[n - 1]) // 偶数，且小于最后一个数，交换
//         {
//             t = s[j];
//             s[j] = s[n - 1];
//             s[n - 1] = t;
//             cout << s << endl;
//             break;
//         }

//         if (j == n - 1 && flag == -1) // 没有偶数
//             cout << "-1" << endl;
//         else if (j == n - 1 && flag != -1) // 有偶数，但都大于最后一个数，最后一个偶数与最后一个数交换
//         {
//             t = s[flag];
//             s[flag] = s[n - 1];
//             s[n - 1] = t;
//             cout << s << endl;
//         }
//     }
//     return 0;
// }

#include <iostream>
#include <cstring>
using namespace std;
const int N = 100001;

int main()
{
    char c[N];
    bool flag = false;
    bool isCout = false;
    cin >> c;
    int len = strlen(c);

    for(int i = 0; i < len; i++)
    {
        // 是否存在偶数
        if(!flag && (c[i] & 1) == 0)
        {
            flag = true;
        }

        // 从前往后遍历，当便利至第一个比尾数小的偶数时，说明找到交换的元素
        if((c[i] & 1) == 0 && c[i] < c[len - 1])
        {
            char t = c[i];
            c[i] = c[len - 1];
            c[len - 1] = t;
            cout << c << endl;
            isCout = true;
            break;
        }
    }

    // 若数组中没有偶数
    if(!flag)
    {
        cout << "-1" << endl;
    }

    // 若数组中没有找到比尾数小的偶数
    // 从后往前遍历，找到第一个偶数，进行交换
    if(!isCout)
    {
        for(int i = len - 1; i >= 0; i--)
        {
            if((c[i] & 1) == 0 && c[i] > c[len - 1])
            {
                char t = c[i];
                c[i] = c[len - 1];
                c[len - 1] = t;
                cout << c << endl;
                break;
            }
        }
    }

   return 0;
}
