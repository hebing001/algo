#include <iostream>
#include <vector>
using namespace std;

void computeNext(const string& pattern) {
    int n = pattern.size();
    vector<int> next(n, 0); // 初始化 next 数组
    int j = 0; // 前缀指针

    cout << "Step-by-step explanation:" << endl;

    for (int i = 1; i < n; ++i) {
        // 处理回退
        while (j > 0 && pattern[i] != pattern[j]) {
            cout << "Mismatch: i=" << i << ", j=" << j
                 << " -> backtrack j=next[" << (j - 1) << "]=" << next[j - 1] << endl;
            j = next[j - 1];
        }

        // 匹配成功
        if (pattern[i] == pattern[j]) {
            j++;
        }
        next[i] = j;

        // 输出当前步骤
        cout << "i=" << i << ", j=" << j << ", next[" << i << "]=" << next[i] << endl;
    }

    // 输出完整的 next 数组
    cout << "Final next array: ";
    for (int x : next) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    string pattern = "ababaca";
    computeNext(pattern);
    return 0;
}