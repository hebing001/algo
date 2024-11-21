// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

// 注意： 答案中不可以包含重复的三元组。

// 示例：

// 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

// 满足要求的三元组集合为： [ [-1, 0, 1], [-1, -1, 2] ]
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
#include <set>

// 自定义哈希函数

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> revec;
        set<vector<int>> mset;
        std::vector<int> temp;
        sort(nums.begin(), nums.end());

        if (nums.size() < 3)
        {
            return revec;
        }

        for (size_t i = 0; i < nums.size() - 2; i++) // 取出了所有组合 耗时太长了吧
        {
            if (nums[i] > 0)
                break;
            for (size_t j = i + 1; j < nums.size(); j++)
            {

                for (size_t k = j + 1; k < nums.size(); k++)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        temp = {nums[i], nums[j], nums[k]};
                        mset.insert(temp);
                    }
                }
            }
        }
        // 去重复的排序结果
        revec.assign(mset.begin(), mset.end());
        return revec;
    }

    vector<vector<int>> threeSum2(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> revec;
        sort(nums.begin(), nums.end());

        if (nums.size() < 3)
        {
            return revec;
        }

        for (size_t i = 0; i < n - 2; i++) // 取出了所有组合 耗时太长了吧
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1]) // 去一下重 感觉很难去重 时间还是很长  关键是后面的循环太多了 后面改成logn的查找
                continue;

            for (size_t j = i + 1; j < n - 1; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                // 二分查找
                int rest = 0 - nums[i] - nums[j];
                auto it = lower_bound(nums.begin() + j + 1, nums.end(), rest);
                if (it != nums.end() && *it == rest)
                {
                    revec.push_back({nums[i], nums[j], rest});
                }
            }
        }
        return revec;
    }
    vector<vector<int>> threeSum2(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> revec;
        sort(nums.begin(), nums.end());

        if (nums.size() < 3)
        {
            return revec;
        }

        for (size_t i = 0; i < n - 2; i++) // 取出了所有组合 耗时太长了吧
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1]) // 去一下重 感觉很难去重 时间还是很长  关键是后面的循环太多了 后面改成logn的查找
                continue;
            int left = i + 1, right = n - 1;
            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] == 0)
                {
                    revec.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) // 这里加上left < right 是为了防止移动过头
                        left++;
                    while (left < right && nums[right] == nums[right - 1]) // 这里加上left < right 是为了防止left和right相等的情况
                        right--;
                    left++;
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        return revec;
    }

    vector<vector<int>> threeSum3(vector<int> &nums) // 进一步优化
    {
        int n = nums.size();
        vector<vector<int>> revec;
        sort(nums.begin(), nums.end());

        if (nums.size() < 3)
        {
            return revec;
        }

        for (size_t i = 0; i < n - 2; i++) // 取出了所有组合 耗时太长了吧
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1]) // 去一下重 感觉很难去重 时间还是很长  关键是后面的循环太多了 后面改成logn的查找
                continue;

            if (nums[i] + nums[i + 1] + nums[i + 2] > 0)
                break; // 优化1
            if (nums[i] + nums[n - 2] + nums[n - 1] < 0)
                continue; // 优化2

            int left = i + 1, right = n - 1;
            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] == 0)
                {
                    revec.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) // 这里加上left < right 是为了防止移动过头
                        left++;
                    while (left < right && nums[right] == nums[right - 1]) // 这里加上left < right 是为了防止left和right相等的情况
                        right--;
                    left++;
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        return revec;
    }
    vector<vector<int>> threeSum4(vector<int> &nums) // 进一步优化
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> revec;
        int size = nums.size();

        for (size_t i = 0; i < size - 2; i++)
        {
            int left = i + 1, right = size - 1;
            while (right > left)
            {
                if (nums[i] + nums[left] + nums[right] == 0)
                {
                    revec.push_back({nums[i], nums[left], nums[right]});

                    // 去重啦
                    while (right > left && nums[left] == nums[left + 1])
                    {
                        left++;
                    }

                    // 去重啦
                    while (right > left && nums[right] == nums[right - 1])
                    {
                        right--;
                    }

                    left++;
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] > 0)
                {
                    right --;
                }
                else
                {
                    left++;
                }
            }
        }
        return revec;
    }
};

int main()
{
    // 一般测试 3个循环就比较耗时间了
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution s;
    // 打印耗时
    time_t start, end;
    start = time(NULL);

    vector<vector<int>> res = s.threeSum2(nums);
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

    return 0;
}