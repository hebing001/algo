#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> buildNext(const string& pattern) {
    int m = pattern.size();
    vector<int> next(m, 0); // 初始化 next 数组
    int j = 0; // 前缀长度

    for (int i = 1; i < m; ++i) { // 从第二个字符开始
        // 如果当前字符不匹配，回退 j
        while (j > 0 && pattern[i] != pattern[j]) {
            j = next[j - 1]; // 回到上一个前缀
        }

        // 如果当前字符匹配，前缀长度加 1
        if (pattern[i] == pattern[j]) {
            j++;
        }

        // 记录 next[i]
        next[i] = j;
    }

    return next;
}

int main() {
    string pattern = "ababaca";
    vector<int> next = buildNext(pattern);

    cout << "Next array: ";
    for (int val : next) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
