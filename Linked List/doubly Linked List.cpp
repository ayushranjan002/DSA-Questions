#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    
    Node(int d) {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insertAtStart(Node* &head, int data) {
    Node* temp = new Node(data);
    temp->next = head;
    if (head != NULL) {
        head->prev = temp;
    }
    head = temp;
}

void insertAtEnd(Node* &tail, int data) {
    Node* temp = new Node(data);
    if (tail != NULL) {
        tail->next = temp;
    }
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node* &tail, Node* &head, int position, int d) {
    if(position == 1) {
        insertAtStart(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtEnd(tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(int position, Node* & head) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp ->next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr;

    }
}

void traverse(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node* &head) {
    int cnt = 0;
    Node* temp = head;
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int main() {
    Node* n1 = new Node(12);
    Node* head = n1;
    Node* tail = n1;

    cout << "Length: " << getLength(head) << endl;
    traverse(head);

    insertAtStart(head, 34);
    traverse(head);

    insertAtStart(head, 14);
    traverse(head);

    insertAtEnd(tail, 69);
    traverse(head);

    insertAtEnd(tail, 13);
    traverse(head);

    insertAtPosition(tail, head, 3, 92);
    traverse(head);

    insertAtPosition(tail, head, 5, 38);
    traverse(head);
	
	deleteNode(5,head);
	traverse(head);
    cout << "Length: " << getLength(head) << endl;

    return 0;
}
