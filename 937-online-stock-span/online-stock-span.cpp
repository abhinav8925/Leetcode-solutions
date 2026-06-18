class StockSpanner {
public:
    stack<pair<int,int>> st;
    int span=0;
    StockSpanner() {
        
   

        

    }
    
    int next(int price) { 
        span = 1;
        while(!st.empty () && price >= st.top().first){
            span+=st.top().second;
            st.pop();
        }

        st.push({price,span});
        return span;
    }
};


