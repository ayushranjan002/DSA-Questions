//using stacks
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        stack<int> st;
        
        // Step 1: Push all people onto the stack
        for (int i = 0; i < n; i++) {
            st.push(i);
        }
        
        // Step 2: Find the potential celebrity
        while (st.size() > 1) {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            // If a knows b, then a can't be the celebrity, so push b
            if (mat[a][b] == 1) {
                st.push(b);
            } 
            // If a doesn't know b, then b can't be the celebrity, so push a
            else {
                st.push(a);
            }
        }
        
        // Step 3: Verify the potential celebrity
        int candidate = st.top();
        
        for (int i = 0; i < n; i++) {
            if (i != candidate) {
                // The candidate should not know anyone and everyone should know the candidate
                if (mat[candidate][i] == 1 || mat[i][candidate] == 0) {
                    return -1;  // Not a celebrity
                }
            }
        }
        
        return candidate;  // Celebrity found
    }
};

//brute force
class Solution {
  public:
   
    int celebrity(vector<vector<int> >& mat) {
        n=mat.size();
        for(int i = 0; i < n ;i++){
            bool isCeleb = true;
            for(int j=0;j<n;j++){
                if(i != j && (mat[i][j] == 1mat[j][i] == 0)){
                    isCeleb = false;
                    break;
                }
            }
           if(isCeleb == true){
               return i;
           } 
        }
        return -1;
    }
};
