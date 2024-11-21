// 输入：19
// 输出：true
// 解释：
// 1^2 + 9^2 = 82
// 8^2 + 2^2 = 68
// 6^2 + 8^2 = 100
// 1^2 + 0^2 + 0^2 = 1

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <cmath>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> myset;
        vector<int> numvec;
        int number;

        while (true)
        {
            numvec.clear();
            while (n > 0)
            {
                number = n % 10;
                numvec.push_back(number);
                n = n / 10;
            }

            n = 0;

            for (auto i : numvec)
            {
                n +=pow (i,2);
            }

            if (n == 1)
            {
                return true;
            }

            if (myset.find(n) == myset.end())
            {
                myset.insert(n);
            }
            else
            {
                return false;
            }
        }
    }
};

int main()
{
    Solution s;
    int n = 2;
    std::cout << s.isHappy(n) << std::endl;
    return 0;
}