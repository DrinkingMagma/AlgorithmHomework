#include <iostream>
using namespace std;

void homework1_3(int n)
{
    int x, y, z, num = 0;
    for (x = 0; x < n / 5; ++x)
    {
        /*
        x+y+z=n
        5x+3y+z/3=n
        */
        if ((n - 7 * x) % 4 != 0)
            continue;
        y = (n - 7 * x) / 4;

        if (y < 0)
            continue;
        z = n - x - y;
        if ((z % 3 == 0) && (x + y + z == n))
        {
            ++num;
            // printf("%d %d %d\n", x, y, z);
            // printf("%d+%d+%d=%d\n", x, y, z, n);
        }
    }
    if (num)
        cout << num << endl;
    else
        printf("No Answer.");
    // printf("total num: %d\n", num);
}

int main()
{
    int n;
    cin >> n;
    homework1_3(n);

    // system("pause");
    return 0;
}