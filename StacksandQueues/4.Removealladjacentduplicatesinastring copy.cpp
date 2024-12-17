// 给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。

// 在 S 上反复执行重复项删除操作，直到无法继续删除。

// 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

// 示例：

// 输入："abbaca"
// 输出："ca"
// 解释：例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
#include <iostream>
#include <string>
#include <stack>
#include <algorithm> // 引入头文件

using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stack1;
        for (size_t i = 0; i < s.size(); i++)
        {
            if(stack1.empty())
            {
                stack1.push(s[i]);
                continue;
            }

            if (stack1.top() == s[i])
            {
                stack1.pop();
                continue;
            }

            stack1.push(s[i]);
        }

        string temp ;
        while (!stack1.empty())
        {
            temp += stack1.top();
            stack1.pop();    


        }
        
        return reverse(temp.begin(), temp.end());
        

        
    }
};


int main()
{
    Solution s;
    string str = "abbaca";
    string result = s.removeDuplicates(str);
    cout << result << endl;

    printf("%s",result.c_str());
    return 0;
}