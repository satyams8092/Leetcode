class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0;
        int currentDepth = 0;
        
        for(char ch : s) {
            if(ch == '(') {
                currentDepth++;
            } else if(ch == ')') {
                currentDepth--;
            }
            // Update max after processing each character
            maxDepth = max(maxDepth, currentDepth);
        }
        
        return maxDepth;
    }
};