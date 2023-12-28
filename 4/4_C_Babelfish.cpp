// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #include <algorithm>
// using namespace std;
// const int MX = 100000 + 5;

// struct node
// {
//     char en[11], fl[11];
//     bool operator<(const node &b) const
//     {
//         return strcmp(fl, b.fl) < 0;
//     }
// } a[MX];

// int BinarySrearch(char temp[], int n)
// {
//     int l = 0, r = n - 1, mid;
//     while (l <= r)
//     {
//         mid = (l + r) >> 1;
//         if (strcmp(temp, a[mid].fl) == 0)
//             return mid;
//         else if (strcmp(temp, a[mid].fl) < 0)
//             r = mid - 1;
//         else
//             l = mid + 1;
//     }
//     return -1;
// }

// int main()
// {
//     char str[30];
//     int n = 0;
//     while (gets(str))
//     {
//         if (str[0] == '\0')
//             break;
//         sscanf(str, "%s %s", a[n].en, a[n].fl);
//         n++;
//     }
//     sort(a, a + n);

//     char temp[11];
//     int key;
//     while (gets(temp))
//     {
//         if (temp[0] == '\0')
//             break;
//         key = BinarySrearch(temp, n);
//         if (key == -1)
//             printf("eh\n");
//         else
//             printf("%s\n", a[key].en);
//     }

//     return 0;
// }

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MX = 100000 + 5;

struct node {
    char en[11], fl[11];
    bool operator<(const node &b) const {
        return strcmp(fl, b.fl) < 0;
    }
} a[MX];

int BinarySearch(char temp[], int n) {
    int l = 0, r = n - 1, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        int cmp = strcmp(temp, a[mid].fl);
        if (cmp == 0)
            return mid;
        else if (cmp < 0)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int main() {
    char str[30];
    int n = 0;

    while (cin.getline(str, 30) && str[0] != '\0') {
        sscanf(str, "%s %s", a[n].en, a[n].fl);
        n++;
    }
    sort(a, a + n);

    char temp[11];
    int key;
    while (cin.getline(temp, 11) && temp[0] != '\0') {
        key = BinarySearch(temp, n);
        if (key == -1)
            printf("eh\n");
        else
            printf("%s\n", a[key].en);
    }

    return 0;
}
