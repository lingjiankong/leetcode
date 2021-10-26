// ***
//
// Dijkstra's algorithm. Return the mininum distance from start to each node.
//
// ***

template <typename NodeT, typename DistT>
unordered_map<NodeT, DistT> dijkstra(unordered_map<NodeT, unordered_set<NodeT>>& neighbors,
                                     unordered_map<NodeT, unordered_map<NodeT, DistT>>& weights, NodeT start) {
    struct NodeState {
        NodeT id;
        DistT dist;  // distance from start the current node
    };

    unordered_map<NodeT, DistT> minDistTo;  // min distance from start to each node
    minDistTo[start] = 0;

    // smallest distance has the highest priority
    auto comp = [](const NodeState& a, const NodeState& b) { return a.dist > b.dist; };
    priority_queue<NodeState, vector<NodeState>, decltype(comp)> pq(comp);
    pq.push({start, 0});

    while (not pq.empty()) {
        NodeState curState = pq.top();
        pq.pop();

        NodeT curID = curState.id;
        DistT distToCur = curState.dist;

        // already obtained a shorter distance to reach curID, continue.
        // Note: this step is an optimization for Dijkstra; removing it does not affect correctness.
        if (minDistTo.count(curID) and distToCur > minDistTo[curID]) {
            continue;
        }

        for (NodeT neighID : neighbors[curID]) {
            DistT distToNeigh = distToCur + weights[curID][neighID];

            if (not minDistTo.count(neighID) or distToNeigh < minDistTo[neighID]) {
                minDistTo[neighID] = distToNeigh;
                pq.push({neighID, distToNeigh});
            }
        }
    }

    return minDistTo;
}
