class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int row = arr.size();
        int col = arr[0].size();
        int n = row*col;

        int s = 0;
        int e = n-1;
        while(s<=e){
            int m = s+(e-s)/2;

            int rowindex = m/col;
            int colindex = m%col;
            int currnumber = arr[rowindex][colindex];

            if(currnumber==target){
                return true;
            }
            else if(currnumber<target){
                s = m+1;
            }
            else{
                e = m-1;
            }

        }
        return false;
    }
};