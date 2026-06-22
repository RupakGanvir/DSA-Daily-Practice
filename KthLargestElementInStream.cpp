#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class KthLargest
{
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int kSize;

public:
    KthLargest(int k, vector<int> &nums)
    {
        kSize = k;
        for (int num : nums)
        {
            add(num);
        }
    }

    int add(int val)
    {
        minHeap.push(val);
        if (minHeap.size() > kSize)
        {
            minHeap.pop();
        }
        return minHeap.top();
    }
};

int main()
{
    vector<int> nums = {4, 5, 8, 2};
    KthLargest *kthLargest = new KthLargest(3, nums);

    cout << "--- Kth Largest Element in Stream Tests ---" << endl;
    cout << "Add 3: " << kthLargest->add(3) << endl;
    cout << "Add 5: " << kthLargest->add(5) << endl;
    cout << "Add 10: " << kthLargest->add(10) << endl;
    cout << "Add 9: " << kthLargest->add(9) << endl;
    cout << "Add 4: " << kthLargest->add(4) << endl;

    delete kthLargest;
    return 0;
}