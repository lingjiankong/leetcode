// ***
//
// Given a generic tree, calculate the length of its diameter.
// The diameter of a tree is the number of edges on the longest path between any two nodes.
//
// Example input:
//
//    1
//   / \
//  2   3
//     /|\
//    4 5 6
//      |
//      7
//
// Example output: 4
//
// ***

// Note: haven't been validated but should be correct.

#include <climits>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct Node {
    Node(int val_) : val(val_) {}
    int val;
    vector<Node*> children;
};

class FindDiameter {
public:
    int findDiameter(Node* root) {
        if (not root) {
            return 0;
        }

        _maxDepth(root);

        return _diameter;
    }

private:
    int _maxDepth(Node* root) {
        if (not root) {
            return 0;
        }

        if (root->children.empty()) {
            return 1;
        }

        int firstMaxDepth = INT_MIN;
        int secondMaxDepth = INT_MIN;
        for (Node* child : root->children) {
            int curDepth = _maxDepth(child);
            if (curDepth >= firstMaxDepth) {
                secondMaxDepth = firstMaxDepth;
                firstMaxDepth = curDepth;
            } else if (curDepth >= secondMaxDepth) {
                secondMaxDepth = curDepth;
            }
        }

        if (root.children.size() >= 2) {
            _diameter = max(_diameter, firstMaxDepth + secondMaxDepth);
        } else if (root.children.size() == 1) {
            _diameter = max(_diameter, firstMaxDepth);
        }

        return 1 + firstMaxDepth;
    }

    int _diameter = 0;
};

int main() {
    Node* root1 = new Node(1);
    Node* root2 = new Node(2);
    Node* root3 = new Node(3);
    Node* root4 = new Node(4);
    Node* root5 = new Node(5);
    Node* root6 = new Node(6);
    Node* root7 = new Node(7);

    root1->children.push_back(root2);
    root1->children.push_back(root3);

    root3->children.push_back(root4);
    root3->children.push_back(root5);
    root3->children.push_back(root6);

    root5->children.push_back(root7);

    FindDiameter fd;

    int res = fd.findDiameter(root1);
    cout << res << endl;
}
