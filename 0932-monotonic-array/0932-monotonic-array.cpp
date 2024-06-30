#include <vector>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) {
            return true; // A single element or empty vector is monotonic
        }

        bool isIncreasing = true, isDecreasing = true;

        for (int i = 1; i < size; i++) {
            if (nums[i] > nums[i-1]) {
                isDecreasing = false;
            }
            if (nums[i] < nums[i-1]) {
                isIncreasing = false;
            }
        }

        return isIncreasing || isDecreasing;
    }
};
