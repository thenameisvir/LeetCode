class Solution {
public:
    int rob(vector<int>& arr) {
        if(arr.empty()) return 0;
        if(arr.size()==1) return arr[0];
        int prev1 = 0;
        int prev2 = 0;

        for(int i=0;i<arr.size();i++){
            int current = max(prev2+arr[i],prev1);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};