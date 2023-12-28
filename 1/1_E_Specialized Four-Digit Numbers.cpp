#include <iostream>

using namespace std;

int baseResult(int number, int base)
{
    int sum = 0;
    while (number > 0)
    {
        sum += number % base;
        number = number / base;
    }
    return sum;
}

void homework15()
{
    for (int i = 1000; i <= 9999; ++i)
    {
        if (baseResult(i, 10) == baseResult(i, 12) && baseResult(i, 12) == baseResult(i, 16))
            cout << i << endl;
    }
}

int main()
{
    homework15();

    return 0;
}