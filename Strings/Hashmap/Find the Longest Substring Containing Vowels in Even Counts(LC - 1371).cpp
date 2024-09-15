class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.length();
        int mask = 0;
        int maxLen = 0;
        unordered_map<int, int> m;
        m[0] = -1;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'a')
                mask = mask ^ (1 << 0);
            else if(s[i] == 'e')
                mask = mask ^ (1 << 1);
            else if (s[i] == 'i') 
                mask = mask ^ (1 << 2);
            else if (s[i] == 'o')
                mask = mask ^ (1 << 3);
            else if(s[i] == 'u')
                mask = mask ^ (1 << 4);
            
           if (m.find(mask) != m.end()) {
                // If the current mask (vowel state) has been seen before,
                // calculate the length of the substring between the first occurrence
                // of this mask and the current index 'i', and update maxLen if necessary.
                maxLen = max(maxLen, i - m[mask]);
          } else {
                // If this mask (vowel state) has not been seen before,
                // store the current index 'i' as the first occurrence of this mask.
                m[mask] = i;
            }
        }
        return maxLen;
    }
};
