// ***
//
// Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
//
// Example:
//
// MovingAverage m = new MovingAverage(3);
// m.next(1) = 1
// m.next(10) = (1 + 10) / 2
// m.next(3) = (1 + 10 + 3) / 3
// m.next(5) = (10 + 3 + 5) / 3
//
// ***

class MovingAverage {
public:
    MovingAverage(int size) : _qSize(size), _sum(0) {}

    double next(int val) {
        if (_q.size() >= _qSize) {
            _sum -= _q.front();
            _q.pop();
        }

        _q.push(val);
        _sum += val;

        return _sum / _q.size();
    }

private:
    queue<int> _q;
    int _qSize;
    double _sum;  // running sum
};
