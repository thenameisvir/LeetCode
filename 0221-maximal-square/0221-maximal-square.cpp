class Solution {  
public:  
    int solve(vector<vector<char>>& matrix, int i, int j, int row, int col, int& maxi, vector<vector<int>>& dp) {  
        // Base case  
        if (i >= row || j >= col) {  
            return 0;  
        }  

        // Memoization check  
        if (dp[i][j] != -1) {  
            return dp[i][j];  
        }  

        // Explore all 3 directions  
        int right = solve(matrix, i, j + 1, row, col, maxi, dp);  
        int down = solve(matrix, i + 1, j, row, col, maxi, dp);  
        int diagonal = solve(matrix, i + 1, j + 1, row, col, maxi, dp);  

        // Check if we can form a square  
        if (matrix[i][j] == '1') {  
            dp[i][j] = 1 + min({right, down, diagonal});  
            maxi = max(maxi, dp[i][j]);  
            return dp[i][j];  
        }  

        return dp[i][j] = 0;  
    }  

    int maximalSquare(vector<vector<char>>& matrix) {  
        int row = matrix.size();  
        int col = matrix[0].size();  
        vector<vector<int>> dp(row, vector<int>(col, -1)); // DP array initialized to -1  
        int maxi = 0;  

        solve(matrix, 0, 0, row, col, maxi, dp);  
        return maxi * maxi;  
    }  
};
