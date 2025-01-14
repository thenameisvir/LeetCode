class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int c = 1;
        for(int i=1;i<arr.size();i++){
            if(arr[i-1]!=arr[i]){
                arr[c] = arr[i];
                c++;
            }
        }

        return c;
    }
};