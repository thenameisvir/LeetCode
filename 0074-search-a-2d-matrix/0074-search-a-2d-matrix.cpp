class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[i].size();j++){
                if(arr[i][j]==target) return true;
            }
        }

        return false;
    }
};