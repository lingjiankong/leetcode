// ***
//
// Implement the following operations of a queue using stacks.
//
// push(x) -- Push element x to the back of queue.
// pop() -- Removes the element from in front of queue.
// peek() -- Get the front element.
// empty() -- Return whether the queue is empty.
//
// ***

class MyQueue {
public:
    MyQueue() {}

    void push(int x) { _s1.push(x); }

    int pop() {
        shiftStack();
        int toReturn = _s2.top();
        _s2.pop();
        return toReturn;
    }

    int peek() {
        shiftStack();
        return _s2.top();
    }

    bool empty() { return _s1.empty() && _s2.empty(); }

private:
    stack<int> _s1;  // stores elements in the order which they were pushed.
    stack<int> _s2;  // stores elements in the reverse order which they were pushed.

    void shiftStack() {
        if (_s2.empty()) {
            while (!_s1.empty()) {
                _s2.push(_s1.top());
                _s1.pop();
            }
        }
    }
};
