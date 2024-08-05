class Solution {
public:
    bool isAnagram(string str, string str2) {
        std::sort(str.begin(), str.end());
        std::sort(str2.begin(), str2.end());

        if(str==str2){
            return true;
        }
        return false;
    }
};