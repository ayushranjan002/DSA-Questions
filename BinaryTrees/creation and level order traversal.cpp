#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    // Constructor
    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelorderTraversal(node* root) {
    if (root == NULL) {
        cout << "Tree is empty." << endl;
        return;
    }

    queue<node*> q;
    q.push(root);
    q.push(NULL); // Marker for end of current level

    cout << "Level-order traversal (with levels):" << endl;

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) { // End of current level
            cout << endl;
            if (!q.empty()) {
                q.push(NULL); // Add marker for next level
            }
        } else {
            cout << temp->data << " ";

            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

// Function to build the tree
node* buildtree() {
    cout << "Enter the data (-1 to indicate no node): ";
    int data;
    cin >> data;

    // Base case: if data is -1, return NULL
    if (data == -1) {
        return NULL;
    }

    // Create a new node with the given data
    node* root = new node(data);

    // Recursively build the left and right subtrees
    cout << "Enter data for left node of " << data << ": ";
    root->left = buildtree();
    cout << "Enter data for right node of " << data << ": ";
    root->right = buildtree();

    return root;
}
void inorder(node* root){
	if(root == NULL){
		return;
	}
	inorder(root -> left);
	cout<< root -> data <<" ";
	inorder(root -> right);
}

void preorder(node* root){
	if(root == NULL){
		return;
	}
	cout<< root -> data <<" ";
	preorder(root -> left);
	preorder(root -> right);
}

void postorder(node* root){
	if(root == NULL){
		return;
	}
	postorder(root -> left);
	postorder(root -> right);
	cout<< root -> data <<" ";
}

int main() {
    cout << "Build your binary tree. Use -1 to indicate no child node." << endl;
    node* root = buildtree(); // Build the tree
    cout << "Tree construction complete." << endl;
	cout<<"level order traversal"<<endl;
    levelorderTraversal(root);
    cout<<"inorder traversal"<<endl;
	inorder(root);
	cout<<"preorder traversal"<<endl;
	preorder(root);
	cout<<"postorder traversal"<<endl;
	postorder(root);
    return 0;
}
