class Solution {
public:
/*
Time Complexity:O(V2+q)
SC: same as above
q is queries
v is numcourses
*/
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> gr(numCourses);//creation of graph
        vector<int> indegree(numCourses,0);//a vector containing indegree for each node in graph but initially declae as 0 for every node

        for(const auto& edge : prerequisites){
            gr[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        //using topological sort bfs traverssal method
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<unordered_set<int>> nodePrereq(numCourses);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int adj : gr[node]){ //going each node and putting its prerequisite
                nodePrereq[adj].insert(node);
                for(int prereq : nodePrereq[node]){
                    nodePrereq[adj].insert(prereq);
                }
                if(--indegree[adj] == 0) q.push(adj);
            }
        }
        vector<bool> answer;
        for(const auto& query : queries){
            answer.push_back(nodePrereq[query[1]].count(query[0]));
        }
        return answer;
    }
};
