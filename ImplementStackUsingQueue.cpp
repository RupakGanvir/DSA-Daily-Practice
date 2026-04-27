#include <iostream>
#include <queue>

using namespace std;

class MyStack
{
private:
    queue<int> q;

public:
    MyStack() {}

    void push(int x)
    {
        q.push(x);

        int size = q.size();
        for (int i = 0; i < size - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int val = q.front();
        q.pop();
        return val;
    }

    int top()
    {
        return q.front();
    }

    int empty()
    {
        return q.empty();
    }
};

int main()
{
    MyStack *obj = new MyStack();
    obj->push(10);
    obj->push(20);
    obj->push(30);

    cout << "Top element: " << obj->top() << endl; // Output: 30
    cout << "Popped: " << obj->pop() << endl;      // Output: 30
    cout << "New Top: " << obj->top() << endl;     // Output: 20

    return 0;
}