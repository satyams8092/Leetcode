class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    // for upper block
                    if (i == 0 || grid[i-1][j] == 0) cnt++;
                    
                    // for down block
                    if (i == n-1 || grid[i+1][j] == 0) cnt++;
                    
                    // for left block
                    if (j == 0 || grid[i][j-1] == 0) cnt++;
                    
                    // for right block
                    if (j == m-1 || grid[i][j+1] == 0) cnt++;
                }
            }
        }
        return cnt;
    }
};