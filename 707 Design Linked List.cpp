// ***
//
// Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
// A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and
// next is a pointer/reference to the next node. If you want to use the doubly linked list, you will need one more
// attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.
//
// Implement the MyLinkedList class:
//
// MyLinkedList() Initializes the MyLinkedList object.
// int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
// void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the
// new node will be the first node of the linked list. void addAtTail(int val) Append a node of value val as the last
// element of the linked list. void addAtIndex(int index, int val) Add a node of value val before the indexth node in
// the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked
// list. If index is greater than the length, the node will not be inserted. void deleteAtIndex(int index) Delete the
// indexth node in the linked list, if the index is valid.
//
//
// Example 1:
//
// Input
// ["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
// [[], [1], [3], [1, 2], [1], [1], [1]]
// Output
// [null, null, null, null, 2, null, 3]
//
// Explanation
// MyLinkedList myLinkedList = new MyLinkedList();
// myLinkedList.addAtHead(1);
// myLinkedList.addAtTail(3);
// myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
// myLinkedList.get(1);              // return 2
// myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
// myLinkedList.get(1);              // return 3
//
// ***

class MyLinkedList {
public:
    MyLinkedList() : head_(nullptr), tail_(nullptr), dummy_(0), size_(0) {}

    ~MyLinkedList() {
        Node* node = head_;
        while (node) {
            Node* cur = node;
            node = node->next;
            delete cur;
        }
        head_ = nullptr;
        tail_ = nullptr;
    }

    int get(int index) {
        if (index < 0 || index >= size_) return -1;
        return getNode(index)->val;
    }

    void addAtHead(int val) {
        head_ = new Node(val, head_);  // new head points to the oridinal head
        if (size_++ == 0) tail_ = head_;
    }

    void addAtTail(int val) {
        auto node = new Node(val);
        if (size_++ == 0) {
            head_ = tail_ = node;
        } else {
            tail_->next = node; // original tail points to the new tail
            tail_ = tail_->next;
        }
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size_) return;
        if (index == 0) return addAtHead(val);
        if (index == size_) return addAtTail(val);
        Node* prev = getNode(index - 1);
        prev->next = new Node(val, prev->next);
        ++size_;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size_) return;
        Node* prev = getNode(index - 1);
        Node* node_to_delete = prev->next;
        prev->next = node_to_delete->next;
        if (index == 0) head_ = prev->next;
        if (index == size_ - 1) tail_ = prev;
        delete node_to_delete;
        --size_;
    }

private:
    struct Node {
        int val;
        Node* next;
        Node(int _val) : Node(_val, nullptr) {}
        Node(int _val, Node* _next) : val(_val), next(_next) {}
    };

    Node* head_;
    Node* tail_;
    Node dummy_;
    int size_;

    Node* getNode(int index) {
        dummy_.next = head_;
        Node* node = &dummy_;
        for (int i = 0; i <= index; ++i) node = node->next;
        return node;
    }
};
