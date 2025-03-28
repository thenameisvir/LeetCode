class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end()); // Sort coins
        long long reach = 0; // Maximum sum we can make
        int count = 0, i = 0;

        while (reach < target) {
            if (i < coins.size() && coins[i] <= reach + 1) {
                reach += coins[i];  // Use the coin
                i++;
            } else {
                reach += (reach + 1);  // Add a new coin
                count++;
            }
        }
        return count;
    }
};
