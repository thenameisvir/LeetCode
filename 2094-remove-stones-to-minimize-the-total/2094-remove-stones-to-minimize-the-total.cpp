class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(int i=0;i<piles.size();i++){
            int element = piles[i];
            pq.push(element);
        }
        while(k--){
            int tope = pq.top();
            pq.pop();
            tope = tope-(tope/2);
            pq.push(tope);
        }

        int sum = 0;
        while(!pq.empty()){
            int e = pq.top();
            pq.pop();
            sum+=e;
        }
        return sum;
    }
};