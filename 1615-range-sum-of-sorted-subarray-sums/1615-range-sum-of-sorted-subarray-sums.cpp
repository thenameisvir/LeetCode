#include <vector>
#include <algorithm>

class Solution {
public:
    int rangeSum(std::vector<int>& nums, int n, int left, int right) {
        std::vector<long long> ans;
        for (int i = 0; i < n; ++i) {
            long long sum = 0;
            for (int j = i; j < n; ++j) {
                sum += nums[j];
                ans.push_back(sum);
            }
        }

        std::sort(ans.begin(), ans.end());

        const int MOD = 1e9 + 7;
        long long sum2 = 0;
        for (int i = left - 1; i < right; ++i) {
            sum2 = (sum2 + ans[i]) % MOD;
        }
        return static_cast<int>(sum2);
    }
};
