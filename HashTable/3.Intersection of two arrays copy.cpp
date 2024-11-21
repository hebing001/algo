#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> myset;
        vector<int> revec = {};

        for (size_t i = 0; i < nums1.size(); i++)
        {
            myset.insert(nums1[i]);
        }

        for (size_t i = 0; i < nums2.size(); i++)
        {

            if (myset.find(nums2[i]) != myset.end())
            {
                myset.erase(nums2[i]);
                revec.push_back(nums2[i]);
            }
        }

        return revec;
    }
};

int main()
{
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    Solution s;
    vector<int> res = s.intersection(nums1, nums2);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}