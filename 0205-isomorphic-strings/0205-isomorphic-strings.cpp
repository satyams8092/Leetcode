class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        
        unordered_map<char, char> s_to_t;
        unordered_map<char, char> t_to_s;
        
        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i];
            char c2 = t[i];
            
            // Check if c1 is already mapped
            if (s_to_t.find(c1) != s_to_t.end() && s_to_t[c1] != c2 ||
                t_to_s.find(c2) != t_to_s.end() && t_to_s[c2] != c1) {
                return false;
            } 
            s_to_t[c1] = c2;
            t_to_s[c2] = c1;
        }
        
        return true;
    }
};