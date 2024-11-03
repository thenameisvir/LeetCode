class Solution {
public:
    bool isValid(string s) {
        
        stack<char>ch;
        int size = s.length();
        if(size==0) return true;
        for(int i=0;i<size;i++){
            if(s[i]=='{' || s[i]=='[' || s[i]=='('){
                ch.push(s[i]);
            }
            else{
                if(ch.empty()) return false;  
                else if(s[i]==')'&&ch.top()=='('){
                ch.pop();
            }
            else if(s[i]=='}'&&ch.top()=='{'){
                ch.pop();
            }
            else if(s[i]==']'&&ch.top()=='['){
                ch.pop();
            }
            else{
                ch.push(s[i]);
            }
            }
            
        }

        if(ch.empty()){
            return true;
        }

        return false;
    }
};