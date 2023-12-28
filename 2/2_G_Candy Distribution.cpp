// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     while (cin >> n && n >= 2)
//     {
//         if ((n & (n - 1)) == 0)
//         {
//             cout << "YES" << endl;
//             continue;
//         }
//         else
//         {
//             cout << "NO" << endl;
//             continue;
//         }
//     }

//     return 0;
// }

// 若N为2的整数幂，则满足题目要求
#include <iostream>
using namespace std;

int main()
{
    long long N;

    while(cin >> N)
    {
        if(N & (N - 1) == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

   return 0;
}
