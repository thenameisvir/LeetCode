class StockSpanner {
public:
    stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        // ye isliye kyuki baar baar function calls ayengi
        while(!st.empty() && st.top().first<=price){
            span+=st.top().second;
            st.pop();
        }
        // ab idhar toh seedha push kardo looping operation k baad
        st.push({price,span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */