class Solution {
public:
    string decodeString(string s) {
        stack<string>st;

        for(int i=0;i<s.length();i++){
            char ch = s[i];

            if(ch==']'){
                string stringToRepeat = "";
                while(!st.empty() && !isdigit(st.top()[0])){
                    string top = st.top();
                    stringToRepeat+=top=="["? "" : top;
                    st.pop();
                }

                string numericTimes = "";
                while(!st.empty() && isdigit(st.top()[0])){
                    numericTimes+=st.top();
                    st.pop();

                }

                reverse(numericTimes.begin(),numericTimes.end());

                int n = stoi(numericTimes);
                
                // final decoding 
                string current = "";
                while(n--){
                    current+=stringToRepeat;
                }
                st.push(current);
            }

            else{
                string temp(1,ch);
                st.push(temp);
            }
        }


        string ans;
         while(!st.empty()){
            ans+=st.top();
            st.pop();
         }


         reverse(ans.begin(),ans.end());


         return ans;
    }
};