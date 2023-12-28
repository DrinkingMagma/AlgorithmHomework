#include <iostream>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << "2" << endl;
        if (n == 2)
            cout << "1"
                 << " "
                 << "2" << endl;
        else
        {
            cout << n - 2 << " " << n << endl;
            cout << n - 1 << " " << n - 1 << endl;
            for (int i = n; i >= 4; i--)
            {
                cout << i - 1 << " " << i - 3 << endl;
            }
        }
    }
    return 0;
}