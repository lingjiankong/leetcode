// ***
//
// Implement a thread-safe bounded blocking queue that has the following methods:
//
// BoundedBlockingQueue(int capacity) The constructor initializes the queue with a maximum capacity.
// void enqueue(int element) Adds an element to the front of the queue. If the queue is full, the calling thread is
// blocked until the queue is no longer full. int dequeue() Returns the element at the rear of the queue and removes it.
// If the queue is empty, the calling thread is blocked until the queue is no longer empty. int size() Returns the
// number of elements currently in the queue. Your implementation will be tested using multiple threads at the same
// time. Each thread will either be a producer thread that only makes calls to the enqueue method or a consumer thread
// that only makes calls to the dequeue method. The size method will be called after every test case.
//
// Please do not use built-in implementations of bounded blocking queue as this will not be accepted in an interview.
//
// ***

class BoundedBlockingQueue {
public:
    BoundedBlockingQueue(int capacity) { _capacity = capacity; }

    void enqueue(int element) {
        unique_lock<mutex> lk(_m);

        // Can be waken up by spurious wakeup. You can also explicity check if (_q.size() >= _capacity)
        _cvNotFull.wait(lk, [this] { return _q.size() < _capacity; });

        _q.push(element);

        _cvNotEmpty.notify_one();
    }

    int dequeue() {
        unique_lock<mutex> lk(_m);

        _cvNotEmpty.wait(lk, [this] { return _q.size() > 0; });

        int num = _q.front();
        _q.pop();

        _cvNotFull.notify_one();

        return num;
    }

    int size() {
        unique_lock<mutex> lk(_m);
        return _q.size();
    }

private:
    mutex _m;
    condition_variable _cvNotEmpty;  // wait until the queue is not empty (so we can pop)
    condition_variable _cvNotFull;   // wait until the queue is not full (so we can push)
    queue<int> _q;
    int _capacity;
};
