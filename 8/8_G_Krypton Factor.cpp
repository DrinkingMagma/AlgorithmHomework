# include <iostream>
# include <string>

using namespace std;
int n, l;

bool check(string ans) {  // 每次只判断增加后的部分是否导致存在容易的串
    int len = ans.length();
    for (int i = 1; 2 * i <= len; i++) {  //
        int start = len - 2 * i, start1 = len - i;  // 计算左部分与右部分的起始位置
        bool ok = false;
        for (int j = 0; j < i; j++) {  // 左部分与右部分逐个判断
            if (ans[start + j] != ans[start1 + j]) {
                ok = true;  break;
            }
        }
        if (ok) continue;  // ok = true，存在不相等的字符，说明该长度不可能存在“简易的串”，那么检查一个长度（2，4，6，8...2*i）
        return false;
    }
    return true;  // 检查完，所有偶数长度都不存在 -> true，是复杂的串
}

bool dfs(string ans = "") {
    if (!check(ans))  // 判断
        return false;  // 不满足条件，返回
    if (ans.length() == n) {  // 符合条件 & 长度为n
        cout << ans << endl;  // 实际题目要求输出更加复杂这里做了简化
        return true;
    }

    for (int i = 0; i < l; i++) {
        ans += char(65 + i);
        // 一个为true，即找到了一个结果，一个返回true，全部返回true，结束
        if (dfs(ans))   return true;  
        ans.pop_back();  // 状态恢复
    }
    // 特别注意，不然遍历完默认返回了true（但其实并没有找到，应该继续返回上层继续搜索），导致结果异常！
    return false;  
}

int main() {
    // 简单输入
    cin >> n >> l;
    dfs();
    return 0;
}
