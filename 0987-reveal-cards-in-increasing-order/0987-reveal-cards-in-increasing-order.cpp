class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // initially sort the deck to perform the reversion
        sort(deck.begin(),deck.end());

        queue<int>q;

        vector<int>arr(deck.size());

        // push the indices into the queue so that we will perform the reverse

        for(int i=0;i<deck.size();i++){
            q.push(i);
        }

        // now the main loop comes into the play with the logic

        for(int i=0;i<deck.size();i++){
            // pushing the first element into the queue
            arr[q.front()] = deck[i];
            q.pop();
            // check if q is not empty and then pop the first and push again
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }


        return arr;
    }
};