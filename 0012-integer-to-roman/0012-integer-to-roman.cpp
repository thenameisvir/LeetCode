class Solution {
public:
    vector<pair<string, int>> mp = {
        {"M",1000}, {"CM",900}, {"D",500}, {"CD",400},
        {"C",100}, {"XC",90}, {"L",50}, {"XL",40},
        {"X",10}, {"IX",9}, {"V",5}, {"IV",4}, {"I",1}
    };

    string intToRoman(int num) {
        string ans = "";
        
        for (auto str : mp) {
            while (num >= str.second) {
                ans += str.first;  // Add Roman numeral
                num -= str.second; // Reduce number
            }
        }
        
        return ans;
    }
};
