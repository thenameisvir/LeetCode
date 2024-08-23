class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>v;
        for(auto str:bank){
            int total = count(str.begin(),str.end(),'1');
            if(total>0){
                v.push_back(total);
            }
        }

        long long int ans = 0;
        for(int i=1;i<v.size();i++){
            ans += v[i] * v[i-1];
        }

        return ans;
    }
};