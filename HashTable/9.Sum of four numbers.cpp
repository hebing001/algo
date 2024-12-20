
// 题意：给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

// 注意：

// 答案中不可以包含重复的四元组。

// 示例： 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。 满足要求的四元组集合为： [ [-1, 0, 0, 1], [-2, -1, 1, 2], [-2, 0, 0, 2] ]

// #算法公开课

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
#include <set>

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size()-2; k++)
        {
            // 剪枝处理
            if (nums[k] > target && nums[k] >= 0)
            {
                break; // 这里使用break，统一通过最后的return返回
            }
            // 对nums[k]去重
            if (k > 0 && nums[k] == nums[k - 1])
            {
                continue;
            }
            for (int i = k + 1; i < nums.size(); i++)
            {
                // 2级剪枝处理
                if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0)
                {
                    break;
                }

                // 对nums[i]去重
                if (i > k + 1 && nums[i] == nums[i - 1])
                {
                    continue;
                }
                int left = i + 1;
                int right = nums.size() - 1;
                while (right > left)
                {
                    // nums[k] + nums[i] + nums[left] + nums[right] > target 会溢出
                    if ((long)nums[k] + nums[i] + nums[left] + nums[right] > target)
                    {
                        right--;
                        // nums[k] + nums[i] + nums[left] + nums[right] < target 会溢出
                    }
                    else if ((long)nums[k] + nums[i] + nums[left] + nums[right] < target)
                    {
                        left++;
                    }
                    else
                    {
                        result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        // 对nums[left]和nums[right]去重
                        while (right > left && nums[right] == nums[right - 1])
                            right--;
                        while (right > left && nums[left] == nums[left + 1])
                            left++;

                        // 找到答案时，双指针同时收缩
                        right--;
                        left++;
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    // 一般测试 3个循环就比较耗时间了
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    Solution s;
    // 打印耗时
    time_t start, end;
    start = time(NULL);

    vector<vector<int>> res = s.fourSum(nums, 0);
    end = time(NULL);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << "耗时：" << end - start << "s" << endl;
}