class Solution {
public:
    int minStoneSum(vector<int>& arr, int k) {
        //Make a max heap
        priority_queue<int>pq;
        // pushing every element into the max heap
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
        }
        // now make it removed from the min heap;
        while(k){
            int front = pq.top();pq.pop();
            front = (front) - (front/2);
            pq.push(front);
            k--;
        }

        int count = 0;
        while(!pq.empty()){
            int e = pq.top();
            count+=e;
            pq.pop();
        }

        return count;

        
    }
};