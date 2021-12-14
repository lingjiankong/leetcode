// ***
//
// Feeding in datastream of *timestamp* (in second), track the mean, stddev, min, max of *timedelta*.
//
// ***

// You can also use monotonic queue O(1) instead of multiset(Ologn) to track min max.
class MonotonicQueue {
public:
    void push(double num) {
        while (not _dec_dq.empty() and _dec_dq.back() < num) {
            _dec_dq.pop_back();
        }
        _dec_dq.push_back(num);

        while (not _inc_dq.empty() and _inc_dq.back() > num) {
            _inc_dq.pop_back();
        }
        _inc_dq.push_back(num);
    }

    double peek_max() {
        if (_dec_dq.empty()) {
            return 0;
        }
        return _dec_dq.front();
    }

    double peek_min() {
        if (_inc_dq.empty()) {
            return 0;
        }
        return _inc_dq.front();
    }

    void pop_max() {
        if (_dec_dq.empty()) {
            return;
        }
        _dec_dq.pop_front();
    }

    void pop_min() {
        if (_inc_dq.empty()) {
            return;
        }
        _inc_dq.pop_front();
    }

private:
    std::deque<double> _dec_dq;
    std::deque<double> _inc_dq;
};

class Statistics {
public:
    Statistics(max_size = 100) { _max_size = max_size; }

    void feed(double ts) {
        if (_dq.size() == _max_size) {
            _sum -= _dq.front();
            _sum_sq -= pow(_dq.front(), 2);

            _set.erase(_set.lower_bound(_dq.front()));

            _dq.pop_front();
        }

        if (_last_ts) {
            double delta = ts - _last_ts;

            _dq.push_back(delta);
            _set.insert(delta);
            _sum += delta;
            _sum_sq += pow(delta, 2);
        }

        _last_ts = ts;
    }

    double get_window_size() { return _dq.size(); }

    double get_average() {
        if (_dq.empty()) {
            return 0;
        }

        return _sum / _dq.size();
    }

    double get_stddev() {
        if (_dq.size() <= 2) {
            return 0;
        }

        return sqrt(_sum_sq / _dq.size() - pow(_sum / _dq.size(), 2));
    }

    double get_min() {
        if (_set.empty()) {
            return 0;
        }

        return *_set.begin();
    }

    double get_max() {
        if (_set.empty()) {
            return 0;
        }

        return *_set.rbegin();
    }

private:
    // running sum of timedelta between message receipt time
    double _sum = 0;

    // running sum of timedelta^2 between message receipt time
    double _sum_sq = 0;

    // max window size
    size_t _max_size;

    // array of timedelta
    std::deque<double> _dq;

    // treeset of time delta (tracks min and max)
    std::set<double> _set;

    double _last_ts = 0;
};
