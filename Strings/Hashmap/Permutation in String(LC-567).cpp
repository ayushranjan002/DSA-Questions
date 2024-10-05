//Make 2 maps, iterate them, compare 
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int size1 = s1.length();
        int size2 = s2.length();
        map <char, int> mpp;

        if (size1 > size2){
            return false;
        }
        
        else{
            for (int i = 0; i < size1; i++){
                mpp[s1[i]]++; 
            }
            for (int j = 0; j < size2-size1+1; j++){
                map <char,int> mmp;
                for (int k = j; k < j+size1; k++){
                    mmp[s2[k]]++;
                }
                if (mpp == mmp){
                    return true;
                }
                continue;
            }
        }
        return false;
    }
};
