// #include <iostream>
// #include <cstring>
// using namespace std;

// int dp[25][15001];
// int pos[25], wei[25];

// int main()
// {
//     int c, g;
//     int i, j, k;

//     while (cin >> c >> g)
//     {
//         for (i = 1; i <= c; i++)
//             cin >> pos[i];
//         for (i = 1; i <= g; i++)
//             cin >> wei[i];

//         memset(dp, 0, sizeof(dp));
//         dp[0][7500] = 1; // 一个砝码也不挂

//         for (i = 1; i <= g; i++) // g个砝码
//             for (j = 0; j <= 15000; j++)
//                 if (dp[i - 1][j])            // 说明可以在往上面挂
//                     for (k = 1; k <= c; k++) // c个位置
//                         dp[i][j + wei[i] * pos[k]] += dp[i - 1][j];

//         cout << dp[g][7500] << endl;
//     }
//     return 0;
// }

#include <iostream>
#include <vector>
#include <cstring>

const int MAX_C = 25;
const int MAX_G = 25;
const int MAX_W = 15000;
const int OFFSET = 7500;

int dp[MAX_G + 1][2 * MAX_W + 1];
int pos[MAX_C];
int wei[MAX_G];

int calculateTotalCombinations(int c, int g) {
    memset(dp, 0, sizeof(dp));
    dp[0][OFFSET] = 1; // 一个砝码也不挂

    for (int i = 1; i <= g; i++) { // g个砝码
        for (int j = 0; j <= 2 * MAX_W; j++) {
            if (dp[i - 1][j]) { // 说明可以在往上面挂
                for (int k = 1; k <= c; k++) { // c个位置
                    dp[i][j + wei[i] * pos[k]] += dp[i - 1][j];
                }
            }
        }
    }

    return dp[g][OFFSET];
}

int main() {
    int c, g;

    while (std::cin >> c >> g) {
        for (int i = 1; i <= c; i++) {
            std::cin >> pos[i];
        }
        for (int i = 1; i <= g; i++) {
            std::cin >> wei[i];
        }

        int totalCombinations = calculateTotalCombinations(c, g);

        std::cout << totalCombinations << std::endl;
    }

    return 0;
}
