#include <iostream>
using namespace std;

void homework1_2(int n)
{
    bool existence = false;
    int x, y, z;
    for (x = 0; x < n / 5; ++x)
    {
        for (y = 0; y < n / 3; ++y)
        {
            z = n - x - y;
            if ((z % 3 == 0) && (5 * x + 3 * y + z / 3 == n))
            {
                existence = true;
                printf("%d %d %d\n", x, y, z);
            }
        }
    }
    if (!existence)
        printf("No Answer.");
}

int main()
{
    int n;
    cin >> n;
    homework1_2(n);
    return 0;
}