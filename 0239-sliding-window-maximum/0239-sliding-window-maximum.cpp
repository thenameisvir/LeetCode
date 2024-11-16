class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        deque<int> q; // Deque to store indices
        vector<int> v; // Result vector

        // Process the first window
        for (int i = 0; i < k; i++) {
            // Remove all smaller elements from the back of the deque in the same loop
            while (!q.empty() && arr[q.back()] <= arr[i]) {
                q.pop_back();
            }
            q.push_back(i); // Add the current index
        }

        // Push the maximum of the first window
        v.push_back(arr[q.front()]);

        // Process the rest of the array
        for (int i = k; i < arr.size(); i++) {
            // Remove elements out of the current window
            if (!q.empty() && q.front() <= i - k) {
                q.pop_front(); // Remove the front element
            }

            // Remove all smaller elements from the back of the deque
            while (!q.empty() && arr[q.back()] <= arr[i]) {
                q.pop_back();
            }

            q.push_back(i); // Add the current index

            // Push the maximum of the current window
            v.push_back(arr[q.front()]);
        }

        return v;
    }
};
