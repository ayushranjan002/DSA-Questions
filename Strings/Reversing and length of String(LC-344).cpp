class Solution {
public:

    void reverseString(vector<char>& s) {
	int i=0;
    int j=(s.size())-1;
	while(i<j){
		swap(s[i++],s[j--]);
	  }
    }
};

int stringLength (char name[]){
		int count=0;
		for(int i=0;name[i]!='\0';i++){
			count++;
		}
	return count;
}
