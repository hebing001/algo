#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums = {1, 3, 5, 7, 9};

    int target = 4;
    auto it = std::lower_bound(nums.begin(), nums.end(), target);

    if (it != nums.end()) {
        std::cout << "Found element >= " << target << ": " << *it << std::endl;
    } else {
        std::cout << "No element >= " << target << " found!" << std::endl;
    }

    return 0;
}
