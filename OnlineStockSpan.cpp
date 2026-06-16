#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class StockSpanner
{
private:
    stack<pair<int, int>> st;

public:
    StockSpanner() {}

    int next(int price)
    {
        int span = 1;

        while (!st.empty() && st.top().first <= price)
        {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});
        return span;
    }
};

int main()
{
    StockSpanner *stockSpanner = new StockSpanner();

    cout << "--- Online Stock Span Tests ---" << endl;
    cout << "Price 100: " << stockSpanner->next(100) << endl;
    cout << "Price 80: " << stockSpanner->next(80) << endl;
    cout << "Price 60: " << stockSpanner->next(60) << endl;
    cout << "Price 70: " << stockSpanner->next(70) << endl;
    cout << "Price 60: " << stockSpanner->next(60) << endl;
    cout << "Price 75: " << stockSpanner->next(75) << endl;
    cout << "Price 85: " << stockSpanner->next(85) << endl;

    delete stockSpanner;
    return 0;
}