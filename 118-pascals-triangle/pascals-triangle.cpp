class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=1;i<=numRows;i++){
            vector<int> temp;
            temp.push_back(1);
            int col =1;
            for(int j=1;j<i;j++){
              col = col*(i-j);
              col = col/j;
              temp.push_back(col);
            }
            res.push_back(temp);
        }
        return res;
    }
};