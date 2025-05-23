class Solution {
public:
    string decodeString(string str) {
        
        stack<string>st1;
        stack<int>st2;

        for(int i=0;i<str.size();i++){
            string temp = "";
            // integer hua toh 
            int num = 0;
            if(str[i]>='0' && str[i]<='9'){
                while(i<str.size() && str[i]>='0' && str[i]<='9'){
                    int a = str[i]-'0';
                    num = (num*10) + a;
                    i++;
                }
                i--;
                st2.push(num);
            }
            else if(str[i]=='[' || str[i]>='a' && str[i]<='z'){
                st1.push(string(1,str[i]));
            }
            else if(str[i]==']'){
                
               while(!st1.empty() && st1.top() >= "a" && st1.top() <= "z"){
        temp = st1.top() + temp;
        st1.pop();
    }
    st1.pop(); // remove '['

    int t = st2.top(); st2.pop();
    string temp2 = "";
    while(t--) temp2 += temp;

    st1.push(temp2);

            }

            
            
        }

        string ans = "";
        while(!st1.empty()){
            ans = st1.top() + ans;
            st1.pop();
        }

        return ans;

    }
};