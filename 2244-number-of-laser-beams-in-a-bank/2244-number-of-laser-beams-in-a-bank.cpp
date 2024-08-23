class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> v;
        for (auto& str : bank) {  // auto deduces the type of str as string&
            int total = count(str.begin(), str.end(), '1');
            if (total > 0) {
                v.push_back(total);
            }
        }

        long long int total_sum = 0;
        for (size_t i = 1; i < v.size(); ++i) {
            total_sum += v[i] * v[i - 1];
        }

        return total_sum;
    }
};
