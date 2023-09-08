class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans ( n ,  vector<int>(n,0));
        int element =1;
        int left =0;
        int right = n-1;
        int top = 0;
        int bottom = n-1;
        while(element <= n*n){
          // first row
          for(int i = left;i<=right && element <= n*n;i++){
            ans[top][i] = element;
            element++;
          }
          top++;
          // last column
          for(int i = top ;i<=bottom  && element <= n*n;i++){
            ans[i][right] = element;
            element++;
          }
          right--;
          // last row
          for(int i = right;i>=left  && element <= n*n;i--){
             ans[bottom][i] = element;
              element++;
          }
          bottom--;
          // first column
          for(int i=bottom;i>=top  && element <= n*n;i--){
             ans[i][left] = element;
              element++;
          }
          left++;
        } 
        return ans;
    }
};