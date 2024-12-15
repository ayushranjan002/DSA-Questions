class Solution {
public:
    vector<int> bottomView(Node* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }

        // Map to store the bottom view nodes with horizontal distance as the key
        map<int, int> mpp;
        
        // Queue to perform level order traversal, stores pair of node and horizontal distance
        queue<pair<Node*, int>> q;
        q.push(make_pair(root, 0));

        while (!q.empty()) {
            pair<Node*, int> frontPair = q.front();
            q.pop();

            Node* temp = frontPair.first;
            int hd = frontPair.second;

            // Update the map with the current node at its horizontal distance
            mpp[hd] = temp->da

            // If the node has a left child, push it into the queue with hd-1
            if (temp->left != NULL) {
                q.push(make_pair(temp->left, hd - 1));
            }

            // If the node has a right child, push it into the queue with hd+1
            if (temp->right != NULL) {
                q.push(make_pair(temp->right, hd + 1));
            }
        }

        // Collect the bottom view from the map
        for (map<int, int>::iterator it = mpp.begin(); it != mpp.end(); ++it) {
            ans.push_back(it->second);
        }

        return ans;
    }
};
