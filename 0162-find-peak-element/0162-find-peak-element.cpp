class Solution {
public:
    int peak(vector<int>& nums){
        if(nums.size()<=1) return 0;
        int s = 0;
        int e = nums.size()-1;
        int m = s+(e-s)/2;
        while(s<e){
            if(nums[m]<nums[m+1]){
                s = m+1;
            }
            else{
                e = m;
            }
            m = s+(e-s)/2;
        }
        return s;
    }
    int findPeakElement(vector<int>& nums) {
        int ans =  peak(nums);
        return ans;
    }
};