// ***
//
// A data structure that supports the following operation:
// - connect p and q
// - if p and q are connected
// - number of clusters in the graph
//
// ***

// See labuladong book pp. 396.
template <typename T>
struct UnionFind {
    UnionFind() {}

    void connect(T p, T q) {
        T rootP = findRoot(p);
        T rootQ = findRoot(q);

        if (rootP == rootQ) {
            return;
        }

        // Attach smaller tree to larger tree to keep the tree balanced.
        if (_size[rootP] > _size[rootQ]) {
            _parent[rootQ] = rootP;
            _size[rootP] += _size[rootQ];
        } else {
            _parent[rootP] = rootQ;
            _size[rootQ] += _size[rootP];
        }

        --_numClusters;
    }

    bool isConnected(T p, T q) {
        T rootP = findRoot(p);
        T rootQ = findRoot(q);

        return rootP == rootQ;
    }

    int numClusters() { return _numClusters; }

    void add(T x) {
        if (has(x)) {
            return;
        }

        _parent[x] = x;
        _size[x] = 1;

        ++_numClusters;
    }

    bool has(T x) { return _parent.count(x); }

    T findRoot(T x) {
        while (x != _parent[x]) {
            // Make the tree as flat as possible flat by compressing the tree during find.
            // Speed advantage. Not required for correctness.
            x = _parent[_parent[x]];
            x = _parent[x];
        }

        return x;
    }

    int _numClusters = 0;
    unordered_map<T, T> _parent;
    unordered_map<T, int> _size;
};

