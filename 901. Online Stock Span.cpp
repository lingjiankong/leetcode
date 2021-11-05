// ***
//
// Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for
// the current day.
//
// The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and
// going backward) for which the stock price was less than or equal to today's price.
//
// For example, if the price of a stock over the next 7 days were [100,80,60,70,60,75,85], then the stock spans would be
// [1,1,1,2,1,4,6]. Implement the StockSpanner class:
//
// StockSpanner() Initializes the object of the class.
// int next(int price) Returns the span of the stock's price given that today's price is price.
//
// ***

class StockSpanner {
public:
    StockSpanner() {}

    int next(int price) {
        int days = 1;
        while (not s.empty() and s.top().first <= price) {
            days += s.top().second;
            s.pop();
        }

        s.push({price, days});

        return days;
    }

private:
    // Monotonic decreasing stack
    // 当前的股价 : 之前比其小的连续天数
    stack<pair<int, int>> s;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
