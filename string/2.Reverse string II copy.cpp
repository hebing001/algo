// 541. 反转字符串II
// 力扣题目链接(opens new window)

// 给定一个字符串 s 和一个整数 k，从字符串开头算起, 每计数至 2k 个字符，就反转这 2k 个字符中的前 k 个字符。

// 如果剩余字符少于 k 个，则将剩余字符全部反转。

// 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

// 示例:

// 输入: s = "abcdefg", k = 2
// 输出: "bacdfeg"

// #算法公开课

#include <string>
#include <iostream>
using namespace std;
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int size = s.length();
        int res = size % (2 * k);

        for (int i = 0; i < size / 2 / k; i++)
        {

            int left = 2 * k * i;
            int right = 2 * k * i + k - 1;

            while (left < right)
            {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        if (res >= k)
        {
            int left = size - res;
            int right = left + k - 1;
            while (left < right)
            {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        else
        {
            int left = size - res;
            int right = size-1;
            while (left < right)
            {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};

int main()
{
    Solution s;
    string str = "abcdefg";
    cout << s.reverseStr(str, 8) << endl;
    return 0;
}