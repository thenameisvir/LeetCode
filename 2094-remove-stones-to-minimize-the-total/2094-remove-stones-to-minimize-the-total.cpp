class Solution {
public:
    int minStoneSum(vector<int>& arr, int k) {
        priority_queue<int>pq;
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
        }

        while(k--){
            int temp = pq.top(); pq.pop();
            if(temp%2==0){
                temp = temp/2;
            }
            else{
                temp = (temp/2)+1;
            }
            pq.push(temp);
        }

        int ans = 0;
        while(!pq.empty()){
            ans+=pq.top(); pq.pop();
        }

        return ans;
    }
};