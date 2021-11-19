// ***
//
// You are feeding a stream of datapoint {api_endpoint (string), delay (double)}.
//
// Design a class that supports the following:
//
// Stores a datapoint in a FIFO order with size limit.
//
// void add(pair<string, double> datum)
// - add a datapoint
//
// double average(string filter = "")
// - get the average delay of the datapoint
// - if you pass in filter, get the delay for that specific endpoint (i.e. for endpoint == filter)
//
// int count(string filter)
// - get the total number of elements in the queue
// - if you pass in filter, get the total number of elements for that specific endpoint (i.e. for endpoint == filter)
//
// ***

#include <cassert>
#include <deque>
#include <iostream>
#include <unordered_map>

using namespace std;

class EndpointMetrics {
public:
    EndpointMetrics(int qSize) : _qSize(qSize) {}

    void add(pair<string, double> datum) {
        string endpoint = datum.first;
        double delay = datum.second;

        if (_dq.size() >= _qSize) {
            pair<string, double> toPop = _dq.front();
            _dq.pop_front();

            string endpoint = toPop.first;
            double delay = toPop.second;

            _sum -= delay;
            _endpoint2sum[endpoint] -= delay;

            if (--_endpoint2count[endpoint] == 0) {
                _endpoint2count.erase(endpoint);
            }
        }

        _dq.emplace_back(datum);
        _sum += delay;
        _endpoint2sum[endpoint] += delay;
        ++_endpoint2count[endpoint];
    }

    double average(string filter = "") {
        if (filter.empty()) {
            return _dq.empty() ? 0. : _sum / _dq.size();
        }

        if (_endpoint2count.count(filter)) {
            return _endpoint2sum[filter] / _endpoint2count[filter];
        }

        return 0.;
    }

    int count(string filter = "") {
        if (filter.empty()) {
            return _dq.size();
        }

        if (_endpoint2count.count(filter)) {
            return _endpoint2count[filter];
        }

        return 0.;
    }

private:
    int _qSize;

    int _sum = 0;

    unordered_map<string, double> _endpoint2sum;

    unordered_map<string, int> _endpoint2count;

    deque<pair<string, double>> _dq;
};

int main() {
    EndpointMetrics em(4);
    em.add({"/api/2", 10.});
    em.add({"/api/1", 20.});
    em.add({"/api/1", 30.});
    assert(em.average() == 20);
    assert(em.average("/api/1") == 25);
    assert(em.average("/api/2") == 10);
    assert(em.count() == 3);
    assert(em.count("/api/1") == 2);
    assert(em.count("/api/2") == 1);

    em.add({"/api/3", 40});
    em.add({"/api/2", 50});
    assert(em.average() == 35);
    assert(em.average("/api/1") == 25);
    assert(em.average("/api/2") == 50);
    assert(em.average("/api/3") == 40);
    assert(em.count() == 4);
    assert(em.count("/api/1") == 2);
    assert(em.count("/api/2") == 1);
    assert(em.count("/api/3") == 1);

    return 0;
}
