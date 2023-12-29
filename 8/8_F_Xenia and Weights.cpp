#include <iostream>
#include <vector>
using namespace std;
vector<int> ans;
string s;
bool dfs(int deep, int l, int r, char now) // 次数，左右重量，当前应该在哪一边添加砝码
{
    if (deep == 0)
        return true;
    for (int i = 1; i <= 10; i++)
    {
        if (s[i] == '1')
        {
            if (now == 'l')
            {
                if (!ans.size() || ans.size() && ans.back() != i && l + i > r)
                {
                    ans.push_back(i);
                    if (dfs(deep - 1, l + i, r, 'r'))
                        return true;
                    ans.pop_back();
                }
            }
            else
            {
                if (!ans.size() || ans.size() && ans.back() != i && r + i > l)
                {
                    ans.push_back(i);
                    if (dfs(deep - 1, l, r + i, 'l'))
                        return true;
                    ans.pop_back();
                }
            }
        }
    }
    return false;
}

void solve()
{

    cin >> s;
    int m;
    cin >> m;
    s = "1" + s;
    if (dfs(m, 1, 1, 'l'))
    {
        cout << "YES" << endl;
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
    }
    else
        cout << "NO" << endl;
}
int main()
{
    int t = 1;
    while (t--)
        solve();
    return 0;
}