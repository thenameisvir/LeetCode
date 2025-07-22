class Solution {
public:
    int tab(int n) {
        vector<int> prev(n+1, INT_MAX);
        prev[0] = 0;  // Base case: 0 requires 0 squares

        for(int half = 1; half*half <= n; half++) {
            vector<int> curr(n+1, INT_MAX);
            for(int index = 0; index <= n; index++) {
                // Not pick this square
                curr[index] = prev[index];

                // Pick this square
                if(index >= half*half && curr[index - half*half] != INT_MAX) {
                    curr[index] = min(curr[index], 1 + curr[index - half*half]);
                }
            }
            prev = curr;
        }

        return prev[n];
    }

    int numSquares(int n) {
        return tab(n);  // DP array not needed anymore
    }
};
