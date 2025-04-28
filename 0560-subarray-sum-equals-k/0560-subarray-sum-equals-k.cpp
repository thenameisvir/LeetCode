class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        // int n = arr.size();
        // int count = 0;
        // vector<int>prefixSum(n,0);

        // prefixSum[0] = arr[0];
        
        // // step 1

        // for(int i=1;i<n;i++){
        //     prefixSum[i] = prefixSum[i-1] + arr[i];
        // }

        // // step 2
        // unordered_map<int,int>m;
        // for(int j=0;j<n;j++){
        //     if(prefixSum[j]==k) count++;

        //     int val = prefixSum[j]-k;
        //     if(m.find(val)!=m.end()){
        //         count+= m[val];
        //     }

        //     if(m.find(prefixSum[j])==m.end()){
        //         m[prefixSum[j]] = 0;
        //     }

        //     m[prefixSum[j]]++;
        // }

        // return count;

        int count = 0;
        int n = arr.size();

        vector<int>v(n,0);
        v[0] = arr[0]; // kch values to jayenge hi andar

        for(int i=1;i<n;i++){
            v[i] = v[i-1] + arr[i];
        }
        // apni prefix array tyar hai ekdum
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            // prefiox sum me condition 1
            if(v[i]==k) count++;

            // step 2nd 
            int val = v[i]-k; // ye value k ko minus karke nikali gayi hai 
            if(mp.find(val)!=mp.end()){
                count+=mp[val]; // jitna usme count pada hua hai + kardo sab
            }
            // step 3
            if(mp.find(v[i])==mp.end()){
                mp[v[i]] = 0;
            }

            mp[v[i]]++;
        }

        return count;




    }
};