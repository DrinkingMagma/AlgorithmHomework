// #include <iostream>
// #include <cstdio>
// #include <string>
// #include <cstring>
// using namespace std;
// int f[1100][1100];
// char s1[1000], s2[1000];
// int len1, len2;
// int main()
// {
//     while (scanf("%s %s", s1, s2) != EOF)
//     {
//         len1 = strlen(s1);
//         len2 = strlen(s2);
//         memset(f, 0, sizeof(f));
//         for (int i = 1; i <= len1; ++i)
//         {
//             for (int j = 1; j <= len2; ++j)
//             {
//                 if (s1[i - 1] == s2[j - 1])
//                     f[i][j] = f[i - 1][j - 1] + 1;
//                 else
//                 {
//                     f[i][j] = max(f[i - 1][j], f[i][j - 1]);
//                 }
//             }
//         }
//         cout << f[len1][len2] << endl;
//     }
//     return 0;
// }

#include <iostream>
#include <cstring>

const int MAX_LEN = 1000;
int f[MAX_LEN + 1][MAX_LEN + 1];

int LCSLength(const char* s1, const char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    memset(f, 0, sizeof(f));

    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = std::max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }

    return f[len1][len2];
}

int main() {
    char s1[MAX_LEN + 1];
    char s2[MAX_LEN + 1];

    while (scanf("%s %s", s1, s2) != EOF) {
        int result = LCSLength(s1, s2);
        std::cout << result << std::endl;
    }

    return 0;
}
