class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char start = 'a';
        char arr[300] = {0};
        for(auto ch:s){
            if(arr[ch]==0){
                arr[ch] = start;
                start++;
            }
        }
        char start2 = 'a';
        char arr2[300] = {0};
        for(auto ch:t){
            if(arr2[ch]==0){
                arr2[ch] = start2;
                start2++;
            }
        }
        string str = "";
        string str2 = "";
        for(auto ch:s){
            char p = arr[ch];
            str.push_back(p);
        }
        for(auto ch:t){
            char p = arr2[ch];
            str2.push_back(p);
        }

        if(str==str2){
            return true;
        }
        return false;
    }
};