class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long totalChalk = 0; // To avoid overflow with large numbers
        
        // Calculate the total amount of chalk required
        for (int c : chalk) {
            totalChalk += c;
        }
        
        // Find the effective number of chalk uses left after complete cycles
        k %= totalChalk;
        
        // Traverse the chalk array to find the student who will use the chalk
        for (int i = 0; i < chalk.size(); ++i) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }
        
        return -1; // Should never reach here if input is valid
    }
};
