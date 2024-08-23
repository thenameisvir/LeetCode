class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>v;
        for(const string& str : bank){
            int total = count(str.begin(), str.end(), '1');
            if (total > 0) {
                v.push_back(total);
            }
        }

        long long int total_sum = 0;
        for(int i = 1; i < v.size(); i++) {
            total_sum += v[i] * v[i-1];
        }

        return total_sum;
    }
};
