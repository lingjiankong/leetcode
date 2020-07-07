// ***
//
// Given a binary tree
//
// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// };
//
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should
// be set to NULL.
//
// Initially, all next pointers are set to NULL.
//
// Note:
// You may only use constant extra space.
// Recursive approach is fine, implicit stack space does not count as extra space for this problem.
//
// Example:
// Given the following binary tree,
//
//      1
//    /  \
//   2    3
//  / \    \
// 4   5    7
//
// After calling your function, the tree should look like:
//
//      1 -> NULL
//    /  \
//   2 -> 3 -> NULL
//  / \    \
// 4-> 5 -> 7 -> NULL
//
// ***

// BFS.
// Exactly same solution can be applied to 116. Populating Next Right Pointers in Each Node
// Almost the same as 102. Binary Tree Level Order Traversal with one added line.
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return nullptr;
        }

        queue<Node*> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            int currentLevelSize = nodeQueue.size();
            for (int i = 0; i < currentLevelSize; ++i) {
                Node* node = nodeQueue.front();
                nodeQueue.pop();

                // As long as we have not reached the rightmost node in current level,
                // set current node's next to be the next element in the queue
                // (which is the next node on current level)
                if (i < currentLevelSize - 1) {
                    node->next = nodeQueue.front();
                }

                if (node->left) {
                    nodeQueue.push(node->left);
                }

                if (node->right) {
                    nodeQueue.push(node->right);
                }
            }
        }

        return root;
    }
};

// BFS, constant space.
// This solution uses the idea in 102. Binary Tree Level Order Traversal
// The difference between this one and 116. Populating Next Right Pointers in Each Node is that
// in this question, we are not guaranteed be be given a perfect binary tree.
//
// We traverse current level (the level of currentNode), and we connect the current level's all children nodes (instead
// connecting current nodes themselves) accordingly, until there's no more node (currentNode) in current level. Now we
// go to next level and do the same.
//
// Well, how do we know where to start in next level? This is where dummyNode->next comes into play:
// dummyNode->next is the first child node we see when we are traversing current level,
// so dummyNode->next is the node we should start we traversing the next level.
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return nullptr;
        }

        Node* currentLevelStart = root;

        while (currentLevelStart) {
            Node dummyNode = Node(0);

            // currentNode is the node on current level we are traversing.
            Node* currentNode = currentLevelStart;

            // currentChild is a node on next level.
            // Initially we have no idea when we will see the first child of current level.
            Node* currentChild = &dummyNode;

            while (currentNode) {
                if (currentNode->left) {
                    currentChild->next = currentNode->left;
                    currentChild = currentChild->next;
                }

                if (currentNode->right) {
                    currentChild->next = currentNode->right;
                    currentChild = currentChild->next;
                }

                currentNode = currentNode->next;
            }

            currentLevelStart = dummyNode.next;
            dummyNode.next = nullptr;  // optional
        }

        return root;
    }
};

