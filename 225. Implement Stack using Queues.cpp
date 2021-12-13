// ***
//
// Implement the following operations of a stack using queues.
//
// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// empty() -- Return whether the stack is empty.
//
// ***

class MyStack {
public:
    MyStack() {}

    // O(n) operation. This is inevitable.
    void push(int x) {
        _q.push(x);
        moveLastElementToQueueFront();
    }

    int pop() {
        int toReturn = _q.front();
        _q.pop();
        return toReturn;
    }

    int top() { return _q.front(); }

    bool empty() { return _q.empty(); }

private:
    queue<int> _q;

    void moveLastElementToQueueFront() {
        // If you only have one element in the queue, no need to move it to the front.
        // That is why i < _q.size() - 1 : In order to move the newest element you just pushed to the front of the
        // queue, we need to move all nums.size() - 1 element originally in front of that new element to the back of the
        // new element.
        for (int i = 0; i < _q.size() - 1; ++i) {
            _q.push(_q.front());
            _q.pop();
        }
    }
};
