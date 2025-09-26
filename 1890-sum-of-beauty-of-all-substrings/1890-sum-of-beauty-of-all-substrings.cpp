class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int totalBeauty = 0;
        
        for (int i = 0; i < n; i++) {
            vector<int> cnt(26, 0);
            
            for (int j = i; j < n; j++) {
                cnt[s[j] - 'a']++;
                
                // Early termination: if substring length < 3, beauty is always 0
                if (j - i < 2) {
                    continue;
                }
                
                totalBeauty += calculateBeauty(cnt);
            }
        }
        
        return totalBeauty;
    }
    
private:
    int calculateBeauty(const vector<int>& cnt) {
        int most = 0;
        int least = INT_MAX;
        
        for (int freq : cnt) {
            if (freq > 0) {
                most = max(most, freq);
                least = min(least, freq);
            }
        }
        
        return most - least;
    }
};