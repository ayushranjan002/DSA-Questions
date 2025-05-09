class Solution {
public:
//easy question only catch is to keep count of the number of edges in particular componet graph and then compare it with v*v-1/2 if equla cnt++
    void bfs(unordered_map<int , vector<int>> &adj, unordered_map<int,bool> &visited, int node, vector<int>& component, int& edgeCount){
        queue<int> q;
        q.push(node);
        visited[node] = true;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            component.push_back(front);
            edgeCount += adj[front].size();  
            for(auto i : adj[front]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,bool> visited;
        unordered_map<int , vector<int>> adj;
        int cnt = 0;

        
        for(auto& e : edges){
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                vector<int> component;
                int edgeCount = 0;
                bfs(adj, visited, i, component, edgeCount);
                
                int size = component.size();
                int expectedEdges = size * (size - 1);  
                if(edgeCount == expectedEdges){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
