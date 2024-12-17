// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

// 有效字符串需满足：

// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
// 每个右括号都有一个对应的相同类型的左括号。

#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        char mapping[128] = {0};
        mapping['('] = ')';
        mapping['['] = ']';
        mapping['{'] = '}';

        for (size_t i = 0; i < s.size(); i++)
        {
            if (stacksy.empty())
            {
                stacksy.push(mapping[s[i]]);
                continue;
            }
            if (stacksy.top() == s[i])
            {
                stacksy.pop();
            }
            else
            {
                stacksy.push(mapping[s[i]]);
            }
        }

        if (stacksy.empty())
        {
            return true;
        }
        return false;
    }

private:
    stack<char> stacksy;
};

int main()
{
    Solution s;
    string str = "()[]{}";
    bool result = s.isValid(str);
    printf("%d\n", result);
    return 0;
}