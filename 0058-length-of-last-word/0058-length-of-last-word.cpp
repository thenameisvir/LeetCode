class Solution {
public:
    int find(string s){
        int sum = 0;
        int num = 0;
        int i = 0;
        int n = s.length();
        while(i<n){
            if(s[i]!=' '){
                num++;
            }
            else if(s[i]==' '){
                if(num>0){
                    sum = num;
                }
                num = 0;

            }
            i++;
        }

        if(num>0){
            sum = num;
        }
        return sum;
    }
    int lengthOfLastWord(string s) {
        return find(s);
    }
};