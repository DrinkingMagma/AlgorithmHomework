#include <iostream>
using namespace std;

void homework1_1(int n)
{
    bool existence = false;
    int x, y, z;
    for (int x = 0; x < n / 5; ++x)
    {
        for (int y = 0; y < n / 3; ++y)
        {
            for (int z = 0; z < n; ++z)
            {
                if ((z % 3 == 0) && (x + y + z == n) && (5 * x + 3 * y + z / 3 == n))
                {
                    existence = true;
                    printf("%d %d %d\n", x, y, z);
                }
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
    homework1_1(n);
    // system("pause");
    return 0;
}