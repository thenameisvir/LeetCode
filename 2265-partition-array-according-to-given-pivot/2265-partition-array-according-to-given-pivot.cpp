class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>ans;
        for(auto i:nums){
            if(pivot>i){
                ans.push_back(i);
            }
        }
        for(auto i:nums){
            if(pivot==i){
                ans.push_back(i);
            }
        }
        // all the smaller elements have been added into it 
        // ans.push_back(pivot);

        for(auto i:nums){
            if(pivot<i){
                ans.push_back(i);
            }
        }

        // all the elements have been added
        nums = ans;
        return ans;
    }
};