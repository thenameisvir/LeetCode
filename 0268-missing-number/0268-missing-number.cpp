class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi  = INT_MIN;
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0;i<nums.size();i++){
            sum1+=nums[i];

            if(nums[i]>maxi){
                maxi = nums[i];
            }
            if(nums[i]<mini){
                mini = nums[i];
            }
        }

        for(int i=1;i<=nums.size();i++){
            sum2+=i;
        }

        return sum2-sum1;

        
    }
};