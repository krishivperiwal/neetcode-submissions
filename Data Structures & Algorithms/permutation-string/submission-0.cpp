class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length()) return false;
        
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        
        // Count frequencies for s1 and the first window in s2
        for (int i = 0; i < s1.size(); i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
        
        // Check if the first window matches
        if (freq1 == freq2) return true;
        
        // Slide the window across s2
        for (int i = s1.size(); i < s2.size(); i++) {
            // Add the new character entering the window on the right
            freq2[s2[i] - 'a']++;
            
            // Remove the old character leaving the window on the left
            freq2[s2[i - s1.size()] - 'a']--;
            
            // Compare frequency maps
            if (freq1 == freq2) return true;
        }
        
        return false;
    }
};