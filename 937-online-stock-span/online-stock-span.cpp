class StockSpanner {   
public:
    StockSpanner() {
        
    }

    vector<int> prices;
    vector<int> spans;
    
    int next(int price) {
        int span = 1;

        int len = prices.size() - 1;

        while (len >= 0 && prices[len] <= price) {
            span = span + spans[len];
            len = len - spans[len]; 
        } 

        prices.push_back(price);
        spans.push_back(span);
        
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */