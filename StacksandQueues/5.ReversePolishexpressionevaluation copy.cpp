#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> tempstack;

        for (size_t i = 0; i < tokens.size(); i++)
        {
            if (isdigit(tokens[i][tokens[i].size()-1]))
            {
                tempstack.push(stoi(tokens[i]));
                continue;
            }
            // 下面就是符号的处理流程
            int result;
            int temp1 = tempstack.top();
            tempstack.pop();
            int temp2 = tempstack.top();
            tempstack.pop();

            switch (tokens[i][0])
            {
            case '+':
                result = temp1 + temp2;
                break;

            case '-':
                result = temp2 - temp1;

                break;

            case '*':
                result = temp1 * temp2;

                break;
            case '/':
                result = temp2 / temp1;
                break;
            default:
                break;
            }
            tempstack.push(result);
        }

        return tempstack.top();
    }
};

int main()
{
    Solution s;
    vector<string> str = {"41", "1", "-", "3", "/"};
    int result = s.evalRPN(str);
    printf("%d\n", result);
    return 0;
}