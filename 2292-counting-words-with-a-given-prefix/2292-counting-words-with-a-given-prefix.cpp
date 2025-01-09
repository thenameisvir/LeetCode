class Solution {
public:
    int prefixCount(vector<string>& arr, string pref) {
        int count = 0;
        for(int i = 0; i < arr.size(); i++) {
            // Check if the prefix matches the start of the current string
            if(arr[i].substr(0, pref.size()) == pref) {
                count++;
            }
        }
        return count;
    }
};
