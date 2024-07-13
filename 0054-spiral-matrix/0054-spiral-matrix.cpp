class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int m = matrix.size();
        int n = matrix[0].size();
        int total = m * n;
        int count = 0;
        int startingRow = 0;
        int endingCol = n - 1;
        int endingRow = m - 1;
        int startingCol = 0;

        while (count < total) {
            // Print starting row
            for (int i = startingCol; i <= endingCol && count < total; i++) {
                v.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;

            // Print ending col
            for (int i = startingRow; i <= endingRow && count < total; i++) {
                v.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;            

            // Print ending row
            for (int i = endingCol; i >= startingCol && count < total; i--) {
                v.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;

            // Print starting col
            for (int i = endingRow; i >= startingRow && count < total; i--) {
                v.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
        }
        return v;
    }
};
