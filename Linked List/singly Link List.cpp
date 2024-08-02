#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
	
	Node(int data){
		this->data= data;
		this->next= NULL;
	}
};
void insertAtHead(Node* &head, int d){
	Node* temp = new Node(d);
	temp->next = head;
	head = temp;
}
void insertAtTail(Node* &tail, int d){
	Node* temp = new Node(d);
	tail->next = temp;
	tail = tail->next;
}

void insertAtPosition(Node* &tail, Node* & head, int position, int d) {


    //insert at Start
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(tail,d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;
}

void traverseLinkList(Node* &head){
	Node* temp = head;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}
int main(){
	Node* node1 = new Node(20);
	//cout<<node1 -> data<<endl;
	//cout<<node1 -> next<<endl;
	Node* head = node1;
	
	Node* tail = node1;
	traverseLinkList(head);
    insertAtTail(tail,13);  
	traverseLinkList(head);
	insertAtHead(head,17);
	traverseLinkList(head);
	insertAtPosition(tail,head,3,45);
	traverseLinkList(head);
}
