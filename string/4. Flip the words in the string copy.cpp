// 151.翻转字符串里的单词
// 力扣题目链接(opens new window)

// 给定一个字符串，逐个翻转字符串中的每个单词。

// 示例 1：
// 输入: "the sky is blue"
// 输出: "blue is sky the"

// 示例 2：
// 输入: "  hello world!  "
// 输出: "world! hello"
// 解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。

// 示例 3：
// 输入: "a good   example"
// 输出: "example good a"
// 解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

// #算法公开课

#include <string>
#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;
 void myreverse(string& s, int start, int end) //翻转，区间写法：左闭右闭 []    
 {
             // 快慢指针
    int fast = end, low = start;

    while (fast > low)
    {
        swap(s[fast--],s[low++]);
    }


}
class Solution
{
public:
    string reverseWords(string s)
    {
        // 双指针加栈法

        int left = 0, right = 0, i = 0;
        // 弄一个栈装起来
        stack<string> mystack;

        while (right < s.length())
        {
            while (right < s.length() && ' ' == s[right])
            {
                right++;
            }

            left = right;

            while (right < s.length() && ' ' != s[right])
            {
                right++;
            }

            if (left == right)
                break;

            // 找到一个单词
            mystack.push(s.substr(left, right - left));
        }

        // 弹出来
        s = "";
        while (mystack.size())
        {
            if (mystack.size() == 1)
            {
                s = s + mystack.top();
                mystack.pop();
            }
            else
            {
                s = s + mystack.top() + " ";
                mystack.pop();
            }
        }

        return s;
    }

    string reverseWords2(string s)
    {
        // 1. 去掉首尾多余的空格
        int left = 0, right = s.size() - 1;
        while (left <= right && s[left] == ' ')
            left++;
        while (left <= right && s[right] == ' ')
            right--;

        // 2. 将字符串中的多余空格压缩成一个空格
        string trimmed;
        while (left <= right)
        {
            if (s[left] != ' ' || (trimmed.size() > 0 && trimmed.back() != ' '))
            {
                trimmed += s[left];
            }
            left++;
        }

        // 3. 翻转整个字符串
        reverse(trimmed.begin(), trimmed.end());

        // 4. 翻转每个单词
        int start = 0, end = 0, n = trimmed.size();
        while (start < n)
        {
            // 找到单词的结束位置
            while (end < n && trimmed[end] != ' ')
                end++;
            // 翻转单词
            reverse(trimmed.begin() + start, trimmed.begin() + end);
            // 移动到下一个单词的开始
            start = end + 1;
            end++;
        }

        return trimmed;
    }

    string reverseWords3(string s)
    {
        // 使用 stringstream 分割单词
        stringstream ss(s);
        string word;
        vector<string> words;

        // 分割单词并存入数组
        while (ss >> word)
        {
            words.push_back(word);
        }

        // 倒序相加单词，构造结果
        string result;
        for (int i = words.size() - 1; i >= 0; --i)
        {
            result += words[i];
            if (i > 0)
                result += " "; // 在单词间添加空格
        }

        return result;
    }
};

string reverseWords4(string s) // 除去多余空格
{
    // 快慢指针
    int fast = 0, low = 0;
    while (s[fast] == ' ' && fast < s.length()) // s[fast]肯定不是' '  去掉头部空格
        fast++;

    if (fast == s.length())
    {
        return "";
    }

    while (fast < s.length())
    {
        while ((fast < s.length()) && s[fast] != ' ')
        {
            s[low] = s[fast];
            low++;
            fast++;
        }

        if (fast == s.length())
        {
            return s;
        }

        else
        {
            s[low] = s[fast];
            low++;
            fast++;

            // 收集多余空格 s[fast] == ' '
            while (fast < s.length() && s[fast] == s[fast - 1])
            {
                fast++;
            }
        }
    }

    if (s[low] == ' ')
    {
        low--;
    }

    s.resize(low);

    return s;
}

string reverseWords5(string s) // 除去多余空格
{
    // 快慢指针
    int fast = 0, low = 0;
    for (int fast = 0; fast < s.length(); fast++)
    {
        if (s[fast] != ' ')
        {
            if (low != 0)
            {
                s[low++] = ' ';
            }
            while (fast < s.length() && s[fast] != ' ')
            {
                s[low++] =s[fast++];

            }
        }
    }
    s.resize(low);
    myreverse(s,0,s.length()-1);
    fast = 0, low = 0;

    for (size_t fast = 0; fast < s.length(); fast++)
    {
        if(s[fast] != ' ')
        {
            low = fast;
            while (fast < s.length() && s[fast] != ' ')
            {
                fast++;
            }

            myreverse(s,low,fast-1);
            
        }
    }

    return s ;
}



int main()
{
    Solution s;
    string str = "   the    sky my  hello    ";
    cout << "---";
    cout << reverseWords5(str);
    cout << "+++" << endl;
    return 0;
}