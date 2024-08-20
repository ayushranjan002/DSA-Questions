/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

//<===================================T.C= (Nlogn) and S.C= O(n)=========================================>
#include <vector>

Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    Node* result;
    if (left->data <= right->data) {
        result = left;
        result->child = merge(left->child, right);
    } else {
        result = right;
        result->child = merge(left, right->child);
    }
    return result;
}

Node* mergeSort(Node* head) {
    if (!head || !head->child) return head;

    Node* slow = head;
    Node* fast = head->child;

    while (fast && fast->child) {
        slow = slow->child;
        fast = fast->child->child;
    }

    Node* mid = slow->child;
    slow->child = nullptr;

    Node* left = mergeSort(head);
    Node* right = mergeSort(mid);

    return merge(left, right);
}

Node* flattenLinkedList(Node* root) {
    std::vector<Node*> nodes;

    while (root != nullptr) {
        nodes.push_back(root);
        Node* temp = root->child;
        while (temp != nullptr) {
            nodes.push_back(temp);
            temp = temp->child;
        }
        root = root->next;
    }

    Node* merged = nullptr;
    for (auto node : nodes) {
        node->child = merged;
        merged = node;
    }

    return mergeSort(merged);
}
