// 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

// 示例 1:

// 输入: nums = [-1,0,3,5,9,12], target = 9     
// 输出: 4       
// 解释: 9 出现在 nums 中并且下标为 4     
// 示例 2:

// 输入: nums = [-1,0,3,5,9,12], target = 2     
// 输出: -1        
// 解释: 2 不存在 nums 中因此返回 -1

#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return -1; 
    }

// [ ]
    int search2(vector<int>& nums, int target) 
    {
    int left = 0;
    int right = nums.size() - 1;
    while(left <= right){
            
            int mid = (left + right) / 2;

            if(nums[mid] > target){
                 right = mid - 1;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else{
               return mid;
            }
        }
        return -1;
    }

    // [ )
    int search3(vector<int>& nums, int target) 
    {
    int left = 0;
    int right = nums.size();
    while(left < right){
            
            int mid = (left + right) / 2;

            if(nums[mid] > target){
                 right = mid;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else{
               return mid;
            }
        }
        return -1;
    }   




};


int main(){

    vector<int> nums = {-1};
    int target = 9;
    Solution s;
    int res = s.search2(nums, target);
    printf("%d\n", res);
    return 0;
}