// 给定一个字符串 s，它包含小写字母和数字字符，请编写一个函数，将字符串中的字母字符保持不变，而将每个数字字符替换为number。

// 例如，对于输入字符串 "a1b2c3"，函数应该将其转换为 "anumberbnumbercnumber"。

// 对于输入字符串 "a5b"，函数应该将其转换为 "anumberb"

// 输入：一个字符串 s,s 仅包含小写字母和数字字符。

// 输出：打印一个新的字符串，其中每个数字字符都被替换为了number

// 样例输入：a1b2c3

// 样例输出：anumberbnumbercnumber

// 数据范围：1 <= s.length < 10000。

// #思路
#include <iostream>
#include <string>
#include <numbers>
#include <cctype> // 包含 isdigit 函数的头文件

using namespace std;

class replacenumber
{

public:
    replacenumber(/* args */);
    ~replacenumber();
    string replaceNumber(string s)
    {
        for (int i; i < s.length(); i++)
        {
            if (isdigit(s[i]))
            {
                s.replace(i,1,newStr);
                i += newStr.length() - 1;
            }
        }
        return s;
    }
    std::string newStr;


};

replacenumber::replacenumber(/* args */)
{
    newStr = "number";

}

replacenumber::~replacenumber()
{
}

int main()
{
    replacenumber r;
    string s = "a1b2c3";
    cout << r.replaceNumber(s) << endl;
    return 0;
}
