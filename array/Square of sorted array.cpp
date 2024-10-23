

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for (int i = 0; i < A.size(); i++) {
            A[i] *= A[i];
        }
        sort(A.begin(), A.end()); // 快速排序
        return A;
    }

    // 双指针法
public:
    vector<int> sortedSquares2(vector<int>& A) {
        int k = A.size() - 1;
        printf("输入的数组是：");
        for (int i = 0; i < A.size(); i++) {
            printf("%d ", A[i]);
        }
        printf("\n");
        printf("数组的大小是：%d\n", A.size());
        vector<int> result(A.size(), 0);
        for (int i = 0, j = A.size() - 1; i <= j;) { // 注意这里要i <= j，因为最后要处理两个元素
            if (A[i] * A[i] < A[j] * A[j])  {
                result[k--] = A[j] * A[j];
                j--;
            }
            else {
                result[k--] = A[i] * A[i];
                i++;
            }
        }
        return result;
    }
};




int main(){

    vector<int> nums = {-1,2,2,33};
    int target = 9;
    Solution s;
    vector<int> res = s.sortedSquares2(nums);
    // 全部取出
    for (int i = 0; i < res.size(); i++) {
        printf("%d ", res[i]);
    }
    return 0;
}