class Solution {
public:
    int minStoneSum(vector<int>& arr, int k) {
        priority_queue<int> pq;
        
        // Push all elements into the max heap
        for (int i = 0; i < arr.size(); i++) {
            pq.push(arr[i]);
        }

        while (k > 0 && !pq.empty()) {
            int element = pq.top(); // Get the largest element
            pq.pop();
            
            // Remove half of the stones from the largest pile
            element -= element / 2; 
            
            // Push the updated pile back into the heap
            pq.push(element);
            k--;
        }

        int ans = 0;

        // Sum up all remaining stones in the heap
        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};
