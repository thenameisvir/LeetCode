class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int profit = 0;
        int mini = arr[0];
        for(int i=1;i<arr.size();i++){
            int diff = arr[i]-mini;
            profit = max(diff,profit);
            mini = min(mini,arr[i]);
        }

        return profit;
    }
};