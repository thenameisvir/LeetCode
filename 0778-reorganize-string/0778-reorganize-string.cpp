class Solution {
public:
    class Info{
        public:
        int count;
        char ch;

        Info(char ch,int count){
            this->count = count;
            this->ch = ch;
        }
    };
    class compare{
        public:
        bool operator()(Info a,Info b){
            return a.count<b.count;
        }
    };
    string reorganizeString(string s) {
        vector<int>freq(26,0);
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            freq[ch-'a']++;
        }    

        // yaha tak frequency store ho chuki hai 
        priority_queue<Info,vector<Info>,compare>pq;
        for(int i=0;i<26;i++){
            if (freq[i] > 0) {
    Info newNode = Info('a' + i, freq[i]);
    pq.push(newNode);
}
        }

        string str = "";
        while(pq.size()>1){

            Info first = pq.top();pq.pop();
            Info second = pq.top();pq.pop();

            str.push_back(first.ch);
            str.push_back(second.ch);

            first.count--;
            second.count--;

            if(first.count>0){
                pq.push(first);
            }
            if(second.count>0){
                pq.push(second);
            }


        }

        if(pq.size()==1){
            Info temp = pq.top();pq.pop();
            if(temp.count>1){
                return "";
            }
            else{
                str.push_back(temp.ch);
            }
        }

        return str;


    }
};