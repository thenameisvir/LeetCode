class Solution {
public:
    void backtrack(int index, int n, vector<int>& perm, int& count) {
        if (index == n + 1) { // Valid permutation found
            count++;
            return;
        }

        for (int i = index; i <= n; i++) {
            swap(perm[i], perm[index]);
            if (perm[index] % index == 0 || index % perm[index] == 0) { // Check condition
                backtrack(index + 1, n, perm, count);
            }
            swap(perm[i], perm[index]); // Backtrack
        }
    }

    int countArrangement(int n) {
        vector<int> perm(n + 1); // 1-based indexing ke liye
        for (int i = 1; i <= n; i++) perm[i] = i; // Initialize array
        int count = 0;
        backtrack(1, n, perm, count); // Start from index 1
        return count;
    }
};
