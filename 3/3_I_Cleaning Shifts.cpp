// #include <cstdio>
// #include <cstring>
// #include <algorithm>
// using namespace std;
// const int M = 1e6 + 10;
// struct node
// {
//     int st;
//     int ed;
// } qq[M];
// bool cmp(node m, node n)
// {
//     if (m.st != n.st)
//         return m.st < n.st;
//     else
//         return m.ed < n.ed;
// }
// int main()
// {
//     int i, j, k, l, m, n, s = 0, t;
//     scanf("%d %d", &n, &t);
//     for (i = 1; i <= n; i++)
//         scanf("%d %d", &qq[i].st, &qq[i].ed);
//     sort(qq + 1, qq + 1 + n, cmp);
//     if (qq[1].st == 1 && qq[1].ed >= t)
//         printf("1\n");

//     else if (qq[1].st != 1)
//         printf("-1\n");
//     else
//     {

//         k = qq[1].ed;
//         s++;
//         int p = 2;
//         while (k < t && p <= n)
//         {
//             s++;
//             if (qq[p].st > k + 1)
//             {
//                 printf("-1\n");
//                 return 0;
//             }

//             int q = k;

//             while (p <= n && qq[p].st <= k + 1)
//             {

//                 q = max(q, qq[p].ed);
//                 p++;
//             }

//             k = q;
//         }

//         if (k < t)
//             printf("-1\n");
//         else
//             printf("%d\n", s);
//     }
//     return 0;
// }

#include <cstdio>
#include <algorithm>
using namespace std;

const int M = 1e6 + 10;

struct Interval {
    int start;
    int end;
};

bool compareIntervals(Interval a, Interval b) {
    if (a.start != b.start)
        return a.start < b.start;
    else
        return a.end < b.end;
}

int main() {
    int n, t;
    scanf("%d %d", &n, &t);

    Interval intervals[M];
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &intervals[i].start, &intervals[i].end);

    sort(intervals + 1, intervals + 1 + n, compareIntervals);

    if (intervals[1].start == 1 && intervals[1].end >= t) {
        printf("1\n");
    } else if (intervals[1].start != 1) {
        printf("-1\n");
    } else {
        int count = 1;
        int p = 2;
        int k = intervals[1].end;

        while (k < t && p <= n) {
            count++;

            if (intervals[p].start > k + 1) {
                printf("-1\n");
                return 0;
            }

            int q = k;

            while (p <= n && intervals[p].start <= k + 1) {
                q = max(q, intervals[p].end);
                p++;
            }

            k = q;
        }

        if (k < t) {
            printf("-1\n");
        } else {
            printf("%d\n", count);
        }
    }
    return 0;
}
