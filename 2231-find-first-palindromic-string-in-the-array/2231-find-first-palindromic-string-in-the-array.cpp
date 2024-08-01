class Solution {
public:
    bool ispalindrome(string str){
        int start = 0;
        int end = str.length()-1;
        while(start<end){
            if(str[start]!=str[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& arr) {
        for(int i=0;i<arr.size();i++){
            string str = arr[i];
            if(ispalindrome(str)){
                return str;
            }
        }
        string s = "";
        return s;
    }
};