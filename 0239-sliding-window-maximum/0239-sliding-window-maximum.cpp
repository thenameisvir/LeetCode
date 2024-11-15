class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        deque<int> q; // Deque to store indices for maximum elements
        vector<int> v; // Result vector

        // Process the first window
        for (int i = 0; i < k; i++) {
            // Remove all smaller elements from the back of the deque
            while (!q.empty() && arr[q.back()] <= arr[i]) {
                q.pop_back();
            }
            q.push_back(i); // Add current index
        }

        // Add the maximum of the first window
        v.push_back(arr[q.front()]);

        // Process the remaining windows
        for (int i = k; i < arr.size(); i++) {
            // Remove indices that are out of the current window
            if (!q.empty() && q.front() <= i - k) {
                q.pop_front();
            }

            // Remove all smaller elements from the back of the deque
            while (!q.empty() && arr[q.back()] <= arr[i]) {
                q.pop_back();
            }

            // Add the current index
            q.push_back(i);

            // Add the maximum of the current window
            v.push_back(arr[q.front()]);
        }

        return v;
    }
};
