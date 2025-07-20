class Solution {
public:
    int binary(vector<int>&ans,int target){
        int s = 0;
        int e = ans.size()-1;
        int m = s+(e-s)/2;
        int vir = -1;
        while(s<=e){
            if(ans[m]>=target){
                vir = m;
                e = m-1;
            }
            else{
                s = m+1;
            }
            m = s+(e-s)/2;
        }
        return vir;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int index = binary(ans,nums[i]);
                ans[index] = nums[i];
            }
        }

        return ans.size();



    }
};