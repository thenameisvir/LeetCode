class Solution {
public:
    int solveUsingTabulation(vector<int>& nums) {
        int n = nums.size();
        //step1
        // vector<int> dp(n, -1);
        //step2
        int prev = nums[n-1];
        int next = 0;
        int curr;
        for(int index = n-2; index>=0; index--) {
            int tempAns = 0;
            if(index + 2 < n) {
                tempAns = next;
            }
            int include = nums[index] + tempAns;
            int exclude = 0 + prev;
            curr = max(include, exclude);

            next = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int ans = solveUsingTabulation(nums);
        return ans;
    }
};