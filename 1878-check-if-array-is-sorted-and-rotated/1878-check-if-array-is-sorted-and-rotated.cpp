class Solution {
public:
    bool check(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        for(int i=1;i<n;i++){
            if(arr[i-1]>arr[i]){
                count++;
            }
        }

        // one more case is pending over here where we have to check the first and last element aswell

        if(arr[n-1]>arr[0]) count++;


        return count<=1;
    }
};