// #include <iostream>
// using namespace std;
// int main()
// {
//     int a[50] = {0, 2, 3};
//     for (int i = 3; i < 50; i++)
//         a[i] = a[i - 1] + a[i - 2];
//     int ci;
//     cin >> ci;
//     for (int i = 1; i <= ci; i++)
//     {
//         int n;
//         cin >> n;
//         cout << "Scenario #" << i << ":" << endl;
//         cout << a[n] << endl;
//         cout << endl;
//     }
//     return 0;
// }

// 超时
// #include <iostream>
// using namespace std;

// int get_result(int num, int a)
// {
//     --num;
//     if(num)
//     {
//         if (a)
//             return get_result(num, 0);
//         else
//             return get_result(num, 1) + get_result(num, 0);

//     }
//      return 1;
// }

// int main(){
//     int all_nums, num;
//     cin >> all_nums;
//     for(int i = 0; i < all_nums; ++i)
//     {
//         cin >> num;

//         cout << "Scenario #" << i + 1 << ":" << endl;
//         cout << get_result(num, 1) + get_result(num, 0) << endl;
//         cout << endl;
//     }

//     return 0;
// }

#include <iostream>
using namespace std;

int main()
{
    int result[50];
    result[1] = 2;
    result[2] = 3;

    for (int i = 3; i < sizeof(result) / sizeof(result[0]); ++i)
    {
        result[i] = result[i - 1] + result[i-2];
    }

    int all_nums, num;
    cin >> all_nums;

    for (int i = 1; i <= all_nums; ++i)
    {
        cin >> num;
        cout << "Scenario #" << i << ":" << endl;
        cout << result[num] << endl;
        cout << endl;
    }

    return 0;
}