class Solution {
  public:
    
    
    vector<int> topView(Node *root) {
          vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        
        map<int, int> mpp;
        queue<pair<Node*, int>> q;
        q.push(make_pair(root, 0));
        while(!q.empty()){
            pair<Node*,int> frontpair = q.front();
            q.pop();
            Node* temp = frontpair.first;
            int hd = frontpair.second;
            /*
                For the top view, you should add a node to the map mpp only 
                if the horizontal distance (hd) is not already present in the map.
                This ensures only the topmost node for each horizontal distance 
                is recorded.
            */
            //if (mpp.find(hd) == mpp.end()) {
              //  mpp[hd] = temp->data;
            //}
            mpp.insert({hd, temp->data});


            if(temp->left != NULL){
                q.push(make_pair(temp->left,hd-1));
            }
            if(temp->right != NULL){
                q.push(make_pair(temp->right,hd+1));
            }
        }
        
        for(const auto& pair : mpp){
            ans.push_back(pair.second);
        }
        return ans;
    }
};
