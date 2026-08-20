#include <iostream>
#include <vector>

using namespace std;

class MyCircularQueue
{
private:
    vector<int> q;
    int head;
    int size;
    int capacity;

public:
    MyCircularQueue(int k)
    {
        capacity = k;
        q.assign(k, 0);
        head = 0;
        size = 0;
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;
        int tail = (head + size) % capacity;
        q[tail] = value;
        size++;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        head = (head + 1) % capacity;
        size--;
        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return q[head];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        int tail = (head + size - 1) % capacity;
        return q[tail];
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }
};

int main()
{
    MyCircularQueue myCircularQueue(3);

    cout << (myCircularQueue.enQueue(1) ? "true" : "false") << "\n"; // return true
    cout << (myCircularQueue.enQueue(2) ? "true" : "false") << "\n"; // return true
    cout << (myCircularQueue.enQueue(3) ? "true" : "false") << "\n"; // return true
    cout << (myCircularQueue.enQueue(4) ? "true" : "false") << "\n"; // return false

    cout << myCircularQueue.Rear() << "\n"; // return 3

    cout << (myCircularQueue.isFull() ? "true" : "false") << "\n";  // return true
    cout << (myCircularQueue.deQueue() ? "true" : "false") << "\n"; // return true

    cout << (myCircularQueue.enQueue(4) ? "true" : "false") << "\n"; // return true
    cout << myCircularQueue.Rear() << "\n";                          // return 4

    return 0;
}