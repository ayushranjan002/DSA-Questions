class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long chem = 0;
        int n = skill.size();
        
        // Step 1: Sort the skill array
        sort(skill.begin(), skill.end());
        
        // Step 2: Calculate the total skill and check divisibility
        int totalskill = 0;
        for (int i = 0; i < n; i++) {
            totalskill += skill[i];
        }
        
        if (totalskill % (n / 2) != 0) {
            return -1;
        }
        
        // Step 3: Calculate target skill for each team
        int targetskill = totalskill / (n / 2);
        int i = 0, j = n - 1;
        
        // Step 4: Pair players and calculate chemistry
        while (i < j) {
            if (skill[i] + skill[j] != targetskill) {
                return -1;
            }
            chem += (long long)skill[i] * skill[j];
            i++;
            j--;
        }
        
        // Special case for two players
        if (n == 2) {
            chem = skill[0] * skill[1];
        }
        
        return chem;
    }
};
