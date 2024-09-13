//brute force
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans; 
        
        for(int i = 0; i < queries.size(); i++){ 
            vector<int> w = queries[i]; 
            int result = 0;
            
            
            for(int j = w[0]; j <= w[1]; j++){ //w[0] means left and w[1] means right element
                result = result ^ arr[j];
            }
            
            ans.push_back(result); 
        }
        
        return ans;
    }
};
