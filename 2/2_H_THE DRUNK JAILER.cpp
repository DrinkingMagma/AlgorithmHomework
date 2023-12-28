// #include <iostream>
// #include <cstring>
// using namespace std;

// int main()
// {
//     char s[200];
//     int k;
//     cin >> k;
//     while (k--)
//     {
//         int n = 0, ans = 0;
//         // cin.ignore();
//         cin >> n;
//         memset(s, 0, sizeof(s));
//         for (int i = 1; i <= n; i++) // n个回合，1表示开，0表示关
//         {
//             for (int j = i; j <= n; j += i)
//             {
//                 s[j] = 1 - s[j];
//             }
//         }

//         for (int i = 1; i <= n; i++)
//         {
//             if (s[i])
//                 ans++;
//         }
//         cout << ans << endl;
//     }
// }

// 模拟实际操作
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int all_nums, num;
    cin >> all_nums;

    while (all_nums--)
    {
        int result = 0;

        cin >> num;

        char c[num + 1];
        memset(c, 0, sizeof(c));

        for (int i = 1; i <= num; ++i)
        {
            for (int j = i; j <= num; j += i)
            {
                c[j] = 1 - c[j];
            }
        }

        for (int i = 1; i <= num; ++i)
        {
            if (c[i])
                ++result;
        }
        
        cout << result << endl;
    }

    return 0;
}
