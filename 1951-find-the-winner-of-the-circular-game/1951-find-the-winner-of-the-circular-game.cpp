class Solution {
public:
    int findTheWinner(int n, int k) {
        // all players should go into queue
        queue<int>q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }

        // simulate the game until it's size becomes one and we gets winner

        while(q.size()>1){
             for(int i=1;i<k;i++){
                // It is not eliminated yet
                q.push(q.front());
                q.pop();
             }

             // kth player must be eliminated
             q.pop();
        }


        return q.front();
    }

};