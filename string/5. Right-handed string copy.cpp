// 字符串的右旋转操作是把字符串尾部的若干个字符转移到字符串的前面。给定一个字符串 s 和一个正整数 k，请编写一个函数，将字符串中的后面 k 个字符移到字符串的前面，实现字符串的右旋转操作。

// 例如，对于输入字符串 "abcdefg" 和整数 2，函数应该将其转换为 "fgabcde"。

// 输入：输入共包含两行，第一行为一个正整数 k，代表右旋转的位数。第二行为字符串 s，代表需要旋转的字符串。

// 输出：输出共一行，为进行了右旋转操作后的字符串。

// 样例输入：

// 2
// abcdefg 
// 样例输出：

// fgabcde
// 数据范围：1 <= k < 10000, 1 <= s.length < 10000;
# include <iostream>
# include <string>
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
int main ()
{
    int k;
    string s;
    cin >> k;
    cin >> s;

    myreverse(s,0,s.length()-1);

    myreverse(s,0,k-1);
    myreverse(s,k,s.length()-1);

    cout << s << endl;
    return 0;
}