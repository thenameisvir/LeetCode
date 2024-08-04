#include <vector>
#include <unordered_map>

using namespace std;

class neighborSum {
public:
    neighborSum(vector<vector<int>>& grid) : grid(grid) {
        int n = grid.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                valueToCoords[grid[i][j]] = {i, j};
            }
        }
    }
    
    int adjacentSum(int value) {
        int n = grid.size();
        int sum = 0;
        int x = valueToCoords[value].first;
        int y = valueToCoords[value].second;
        
        if (x > 0) sum += grid[x-1][y]; // top
        if (x < n-1) sum += grid[x+1][y]; // bottom
        if (y > 0) sum += grid[x][y-1]; // left
        if (y < n-1) sum += grid[x][y+1]; // right
        
        return sum;
    }
    
    int diagonalSum(int value) {
        int n = grid.size();
        int sum = 0;
        int x = valueToCoords[value].first;
        int y = valueToCoords[value].second;
        
        if (x > 0 && y > 0) sum += grid[x-1][y-1]; // top-left
        if (x > 0 && y < n-1) sum += grid[x-1][y+1]; // top-right
        if (x < n-1 && y > 0) sum += grid[x+1][y-1]; // bottom-left
        if (x < n-1 && y < n-1) sum += grid[x+1][y+1]; // bottom-right
        
        return sum;
    }

private:
    vector<vector<int>> grid;
    unordered_map<int, pair<int, int>> valueToCoords;
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
