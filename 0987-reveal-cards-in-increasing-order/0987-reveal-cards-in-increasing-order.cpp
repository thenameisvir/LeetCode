class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

        // Step 1 : Sorting the deck so that it will be useful to reverse verify
        sort(deck.begin(),deck.end());
        // initialising the queue for the reverse nature of the question
        queue<int>q;
        // initialising the ans vector which we need to return
        vector<int>arr(deck.size());
        // Step 2 : Push all the indices into the queue

        for(int i=0;i<deck.size();i++){
            q.push(i);
        }

        // take the charge of for loop for the simulation and remember that the simulation question might get solved by the help of queue.

        for(int i=0;i<deck.size();i++){

            // Step 1 in for loop : push the front card into the deck
            arr[q.front()] = deck[i];

            q.pop();

            // Step 2 in for loop : check whether the queue is empty or not and if it's not empty then pop the second element revising the circular nature

            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }


        }


        return arr;



    }
};