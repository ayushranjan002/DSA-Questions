#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory freed with data " << value << endl;
    }
};

void insertNode(Node*& tail, int element, int data) {
    if (tail == NULL) {
        Node* newnode = new Node(data);
        tail = newnode;
        newnode->next = newnode;
    } else {
        Node* curr = tail;
        do {
            if (curr->data == element) {
                Node* newnode = new Node(data);
                newnode->next = curr->next;
                curr->next = newnode;
                if (curr == tail) {
                    tail = newnode;
                }
                break;
            }
            curr = curr->next;
        } while (curr != tail);
    }
}

void deleteNode(Node*& tail, int value) {
    if (tail == NULL) {
        cout << "List is empty, please check again" << endl;
        return;
    } else {
        Node* prev = tail;
        Node* curr = prev->next;

        while (curr->data != value) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        if (curr == prev) {
            tail = NULL;
        } else if (tail == curr) {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}

void traverse(Node* tail) {
    if (tail == NULL) {
        cout << "List is Empty " << endl;
        return;
    }

    Node* temp = tail;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);

    cout << endl;
}

int main() {
    Node* tail = NULL;

    insertNode(tail, 5, 3);
    traverse(tail);

    insertNode(tail, 3, 5);
    traverse(tail);

    insertNode(tail, 5, 7);
    traverse(tail);

    insertNode(tail, 7, 9);
    traverse(tail);

    insertNode(tail, 5, 6);
    traverse(tail);

    insertNode(tail, 9, 10);
    traverse(tail);

    insertNode(tail, 3, 4);
    traverse(tail);

    deleteNode(tail, 4);
    traverse(tail);

    deleteNode(tail, 10);
    traverse(tail);

    deleteNode(tail, 3);
    traverse(tail);

    deleteNode(tail, 5);
    traverse(tail);

    deleteNode(tail, 7);
    traverse(tail);

    deleteNode(tail, 6);
    traverse(tail);

    deleteNode(tail, 9);
    traverse(tail);

    return 0;
}
