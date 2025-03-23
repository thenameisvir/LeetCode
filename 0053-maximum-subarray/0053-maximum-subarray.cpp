class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = nums[0];
        int curr = 0;
        for(int i=0;i<nums.size();i++){
            // starting me ek condition check lagaunga
            if(curr<0){
                // agar mera curr 0 se chota hai toh usko reset karde
                curr = nums[i];
            }
            else{
                curr +=nums[i];
            }

            // ab jab ye kar hi dia hai toh max ko bhi update kardo

            maxi = max(maxi,curr);
        }

        return maxi;
    }
};