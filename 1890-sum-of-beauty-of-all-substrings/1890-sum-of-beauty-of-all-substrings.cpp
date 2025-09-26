class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int totalBeauty = 0;
        
        // Check all possible substrings
        for (int i = 0; i < n; i++) {
            vector<int> cnt(26, 0);
            
            for (int j = i; j < n; j++) {
                // Add current character to frequency count
                cnt[s[j] - 'a']++;
                
                // Calculate beauty for current substring s[i...j]
                int most = 0;
                int least = INT_MAX;
                
                for (int freq : cnt) {
                    if (freq > 0) {  // Only consider characters that appear
                        most = max(most, freq);
                        least = min(least, freq);
                    }
                }
                
                // Add beauty to total (difference between max and min frequency)
                totalBeauty += (most - least);
            }
        }
        
        return totalBeauty;
    }
};