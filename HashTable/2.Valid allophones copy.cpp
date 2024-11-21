#include <iostream>
#include <string>
using namespace std;



class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size()!=t.size())
        {
            return false;
        }

        for (size_t i = 0; i < s.size(); i++)
        {
            record[s[i]%26] ++;
        }

        for (size_t i = 0; i < t.size(); i++)
        {
            record[t[i]%26]--;
        }

        for (size_t i = 0; i < 26; i++)
        {
            if(record[i] !=0 )
            {
                return false;
            }
        }
        
        return true;
    }
    private:
     int record[26]={0};
};

int main() {
    string s = "anagram";
    string t = "nagaram";
    Solution solution;
    std::cout << solution.isAnagram(s, t) << std::endl;
    // 结束了
    std::cout << "结束了" << std::endl;
    return 0;
}