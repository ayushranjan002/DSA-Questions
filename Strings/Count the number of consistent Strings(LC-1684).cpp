class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int result = 0;
        int ans = 0;
        for ( int i = 0; i < words.size() ; i++){
            string w = words[i];
            for( int j = 0 ; j < w.size(); j++){
                bool found = false;
                for(int k = 0; k< allowed.size();k++){
                    if(w[j] == allowed[k]){
                        found = true;
                        break;
                    }
                }
                if(!found){
                    ans++;
                    break;
                }
            }
        }
        return result = words.size() - ans ;
    }
};
