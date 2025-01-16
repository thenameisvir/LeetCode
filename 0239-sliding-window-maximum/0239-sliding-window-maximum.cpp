class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        deque<int>q;
        vector<int>v;

        // Vir first window ko access kar
        for(int i=0;i<k;i++){
            while(!q.empty() && arr[q.back()]<=arr[i]){
                q.pop_back();
            }

            q.push_back(i);
        }

        // yaha tak apan ne window bana li hai almost ab iske front p ans pada hai pehli window ka
        // usko bhi lage hat push karde

        v.push_back(arr[q.front()]);

        // now we will be accessing the rest of the window 
        for(int i=k;i<arr.size();i++){
            // check kar jo max element hum push kr rhe the kahi vo out of bound to nahi ho gya
            if(!q.empty() && q.front()<=i-k){
                q.pop_front();
            }

            while(!q.empty() && arr[q.back()]<=arr[i]){
                q.pop_back();
            }

            q.push_back(i);

            v.push_back(arr[q.front()]);

        }

        return v;
    }
};