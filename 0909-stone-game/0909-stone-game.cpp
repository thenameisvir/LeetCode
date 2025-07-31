class Solution {
public:
    bool stoneGame(vector<int>& arr) {
        // priority_queue<int>pq;
        if(arr.size()==1) return true;

        int n = arr.size()-1;
        // pq.push(arr[0]);
        // pq.push(arr[n]);

        int alice = 0, bob = 0;
        int i = 0;
        bool flag = true;
        while(i<n){
            int a = arr[i];
            int b = arr[n];
            if(flag){
                if(a>b){
                    alice+=a;
                    i++;
                }
                else{
                    alice+=b;
                    n--;
                }
                flag = false;
            }
            else{
                if(a>b){
                    alice+=a;
                    i++;
                }
                else{
                    alice+=b;
                    n--;
                }
                flag = true;
            }
        }

        return alice>bob;
    }
};