class Solution {
public:
    // Ye sirf nth natural number sum deta hai: 1 + 2 + ... + n
    long long solve(int n){
        if(n==0 || n==1) return n;
        return solve(n-1) + n;
    }

    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;

        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                int j = i;
                while(j<n && nums[j]==0){
                    j++;
                }

                // ab block [i...j-1] me sirf 0 hai
                int len = j - i;

                // us block ke subarrays of zero ka count
                ans += solve(len);

                // i ko aage le jao directly
                i = j-1;
            }
        }

        return ans;
    }
};
