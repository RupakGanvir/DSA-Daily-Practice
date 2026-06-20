#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class MedianFinder
{
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder() {}

    void addNum(int num)
    {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if (maxHeap.size() < minHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian()
    {
        if (maxHeap.size() > minHeap.size())
        {
            return maxHeap.top();
        }
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

int main()
{
    MedianFinder finder;

    cout << "--- Find Median from Data Stream Tests ---" << endl;

    finder.addNum(1);
    finder.addNum(2);
    cout << "Test 1: " << finder.findMedian() << endl;

    finder.addNum(3);
    cout << "Test 2: " << finder.findMedian() << endl;

    return 0;
}