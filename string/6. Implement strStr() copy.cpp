// 28. 实现 strStr()
// 力扣题目链接(opens new window)

// 实现 strStr() 函数。

// 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

// 示例 1: 输入: haystack = "hello", needle = "ll" 输出: 2

// 示例 2: 输入: haystack = "aaaaa", needle = "bba" 输出: -1

// 说明: 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
#include <string>
#include <iostream>
#include <vector>
using namespace std;
// 计算一个这个的哈希
// 计算另一个的哈希
// 相等就说明找到了
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        /*暴力匹配*/
        if (needle == "")
            return 0;

        for (int i = 0; i < haystack.length(); i++) // 暴力匹配法 一个字母一个字母匹配 不太好吧
        {

            int temp = i;
            int difflag = 0;
            for (int k = 0; k < needle.length(); k++, temp++)
            {
                if (haystack[temp] != needle[k])
                {
                    difflag = 1;
                    break;
                }
            }

            if (!difflag)
            {
                printf("%d", i);
                printf("\n");
                for (; i < temp; i++)
                {
                    printf("%c", haystack[i]);
                }

                printf("\n");

                return i;
            }
        }

        return 0;
    }
    int strStr2(string haystack, string needle)
    {
        int j = 0;
        vector<int> next = computeNext(needle);
        for (int i = 0; i < haystack.size(); i++)
        {
            
            while(haystack[i] != needle[j]&& j >0)
            {
                j = next[j-1];

            }

            if(haystack[i] == needle[j])
            {
                j++;
            }

            if(j == needle.size())
            {
                return i-j+1;
            }


   
        }
        return -1;
    }

    vector<int> computeNext(const string &pattern)
    {
        vector<int> next;
        int i = 1, j = 0;

        next.push_back(0);
        for ( ; i < pattern.size() ; i++)
        {
            while (j > 0 && pattern[i] != pattern[j])
            {
                j = next[j - 1];
            }

            if (pattern[i] == pattern[j])
            {
                j++;
            }

            next.push_back(j);
        }

        return next;
    }
};

int main()
{
    Solution s;
    string haystack = "mississippi";
    string needle = "issipi";
    cout << s.strStr2(haystack, needle) << endl;
    return 0;
}