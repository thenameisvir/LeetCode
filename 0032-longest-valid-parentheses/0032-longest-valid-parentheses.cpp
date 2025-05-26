class Solution {
public:
    int longestValidParentheses(string str) {
     int leftCount = 0,rightCount = 0;
     int maxValid = 0;
     for(int i=0;i<str.size();i++){
        if(str[i]=='('){
            leftCount++;
        }
        else{
            rightCount++;
        }

        if(leftCount==rightCount){
            maxValid = max(maxValid,2*leftCount);
        }
        else if(rightCount>leftCount){
            leftCount = 0;
            rightCount = 0;
        }
     }

     leftCount = 0;
     rightCount = 0;

     for(int i=str.size()-1;i>=0;i--){
        if(str[i]=='('){
            leftCount++;
        }
        else{
            rightCount++;
        }

        if(leftCount==rightCount){
            maxValid = max(maxValid,2*leftCount);
        }
        else if(rightCount<leftCount){
            leftCount = 0;
            rightCount = 0;
        }
     }

     return maxValid;




    }
};