class Solution {
public:
    /*
        Approach :
        sort each row and find max number for each column and add it to answer
        TC => O(n * log m ) + O(n*m) => O(n Log m)
        SC => O(1)
    */
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++)
             sort(grid[i].begin(), grid[i].end());
        int maxi = 0;
        int ans = 0;
        for(int i=0;i<grid[0].size();i++){
            maxi = 0;
            for(int j=0;j<grid.size();j++) {
                maxi = max(maxi, grid[j][i]);
            }
            ans += maxi;
        }
        return ans;
    }
};