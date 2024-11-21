
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

        sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<vector<int>> revec;

        for (int a = 0; a < size - 3; a++)
        {
            // 优化

            // 去重 同时收集第一个的参数
            if (a > 0 && nums[a] == nums[a - 1])
            {
                continue;
            }

            for (size_t b = a + 1; b < size - 2; b++)
            {

                if (b > a + 1 && nums[b] == nums[b - 1])
                {
                    continue;
                }
                int left = b + 1, right = size - 1;
                while (left < right)
                {
                    long long sum = static_cast<long long>(nums[a]) + nums[b] + nums[left] + nums[right];

                    if (sum == target)
                    {
                        revec.push_back({nums[a], nums[b], nums[left], nums[right]});
                        printf("%d %d %d %d\n", nums[a], nums[b], nums[left], nums[right]);
                        while (left < right && nums[left] == nums[left + 1])
                        {
                            left++;
                        }

                        while (left < right && nums[right] == nums[right - 1])
                        {
                            right--;
                        }

                        left++;
                        right--;
                    }
                    else if (sum > target)
                    {
                        right--;
                    }
                    else
                    {
                        left++;
                    }
                }
            }
        }

        return revec;
    }
};

int main()
{
    // 一般测试 3个循环就比较耗时间了
    vector<int> nums = {-3, -2, -1, 0, 0, 1, 2, 3};
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