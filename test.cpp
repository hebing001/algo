#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> myVector = {1, 2, 3, 4, 5};

    // 使用迭代器修改容器中的元素
    for (vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it) {
        *it = *it * 2;  // 将每个元素乘以2
    }

    // 打印修改后的元素
    for (vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it) {
        cout << *it << " ";  // 输出 2 4 6 8 10
    }
    cout << endl;

    return 0;
}
