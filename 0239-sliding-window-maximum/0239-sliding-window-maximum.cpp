class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
         deque<int>q;
         vector<int>v;

         // first iterate first window
         for(int i=0;i<k;i++){
            while(!q.empty() && arr[q.back()]<=arr[i]){
                q.pop_back();
            }

            q.push_back(i);
         }

         v.push_back(arr[q.front()]);

         for(int i=k;i<arr.size();i++){
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