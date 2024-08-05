class Solution {
public:
    string reverseOnlyLetters(string str) {
        int s = 0;
        int e = str.length()-1;
        while(s<=e){
            if(isalpha(str[s])&& isalpha(str[e])){
                swap(str[s],str[e]);
                s++;
                e--;
            }
            else if(!isalpha(str[s])){
                s++;
            }
            else{
                e--;
            }
        }
        return str;
    }
};