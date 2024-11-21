// 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

// 示例:

// 给定 nums = [2, 7, 11, 15], target = 9

// 因为 nums[0] + nums[1] = 2 + 7 = 9

// 所以返回 [0, 1]
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < nums.size(); ++j)
            {

                if ((nums[i] + nums[j]) == target)
                {
                    vector<int> revec = {i, j};

                    return revec;
                }
            }
        }
    }

    vector<int> twoSum2(vector<int> &nums, int target)
    {
        unordered_map<int, int> mymap;
        for (size_t i = 0; i < nums.size(); i++)
        {
            unordered_map<int, int>::iterator re = mymap.find(target - nums[i]);
            if (re == mymap.end())
            {
                // 加入进去
                // mymap.insert({nums[i], i});
                mymap[nums[i]] = i; // 使用 operator[] 会覆盖原来的值
            }
            else
            {
                return {re->second, i};
            }
        }
        return {}; // 确保函数在所有控制路径中都有返回值
    }
};

int main()
{
    vector<int> nums = {2, 2, 2, 7, 11, 15};
    int target = 9;
    Solution s;
    vector<int> res = s.twoSum2(nums, target);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}