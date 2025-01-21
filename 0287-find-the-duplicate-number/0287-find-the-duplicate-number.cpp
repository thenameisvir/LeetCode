class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            int index = abs(arr[i]);

            if(arr[index]<0) return index;

            arr[index]*=-1;
        }

        return -1;
    }
};