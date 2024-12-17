#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int K)
    {
        unordered_map<int, int> map;
        vector<int> ret;
        // 遍历所有元素 加入map中
        for (size_t i = 0; i < nums.size(); i++)
        {
            // 加入前首先查询有没有，有就加一，没有插入对应键值对
            if (map.count(nums[i]))
            {
                map[nums[i]]++;
            }
            else
            {
                map.insert({nums[i], 1});
            }
        }

        // 1. 将 unordered_map 的键值对存入 vector 中
        vector<pair<int, int>> vec(map.begin(), map.end());

        // 2. 按照值排序（从大到小）
        sort(vec.begin(), vec.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             {
                 return a.second > b.second; // 按 second 降序排序
             });

        // 3. 取出前 K 个元素
        cout << "前 " << K << " 个元素为：" << endl;
        for (int i = 0; i < K && i < vec.size(); ++i)
        {
            cout << "Key: " << vec[i].first << ", Value: " << vec[i].second << endl;
            ret.push_back(vec[i].first);
        }
        return ret;
    }
};


class Solution2 {
public:
    // 小顶堆
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;  // 小顶堆
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 要统计元素出现频率
        unordered_map<int, int> map; // map<nums[i],对应出现的次数>
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        // 对频率排序
        // 定义一个小顶堆，大小为k
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

        // 用固定大小为k的小顶堆，扫面所有频率的数值
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) { // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
                pri_que.pop();
            }
        }

        // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;

    }
};



int main()
{
    Solution2 s;
    vector<int> nums = {5,1, 1, 1, 2, 2, 3};
    int k = 2;
    s.topKFrequent(nums, k);
    return 0;
}