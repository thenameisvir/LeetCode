class Solution {
public:
    
   

    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<k;i++){
            int e = nums[i];
            pq.push(e);
        }
        for(int i=k;i<size;i++){
            int e = nums[i];
            if(e>pq.top()){
                pq.pop();
                pq.push(e);
            }
        }
        int ans = pq.top();
        return ans;
    }
};