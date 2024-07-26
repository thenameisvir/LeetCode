class Solution {
public:
    vector<int> takeitout(vector<int>& arr, int target){
        vector<int> ans;
        int e = arr.size()-1;
        int i = 0;
        while(i < e){
            int sum = arr[i] + arr[e];
            if(sum == target){
                ans.push_back(i+1);
                ans.push_back(e+1);
                break; // If only one pair is required, break after finding it
            }
            else if(sum > target){
                e--;
            }
            else {
                i++;
            }
        }
        return ans;
    }
    vector<int> twoSum(vector<int>& arr, int target) {
        return takeitout(arr, target);
    }
};
