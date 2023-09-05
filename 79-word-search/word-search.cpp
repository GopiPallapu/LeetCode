class Solution {
public:
    bool helper(int i , int j , vector<vector<char>>& board, string &word,int k,int n, int m)
    {
        // base case
         if(k == word.size())return true;
        if(i < 0 || j < 0 || i == n || j == m || board[i][j] != word[k])return false;
        char ch = board[i][j];
        board[i][j] = '@';
        bool op1 = helper(i+1,j,board,word,k+1,n,m);
        bool op2 = helper(i-1,j,board,word,k+1,n,m);
        bool op3 = helper(i,j+1,board,word,k+1,n,m);
        bool op4 = helper(i,j-1,board,word,k+1,n,m);
        board[i][j] = ch;
        return op1 || op2 || op3 || op4;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        for(int i=0;i<rows;i++){
          for(int j=0;j<cols;j++){
            if(board[i][j] == word[0])
            {
              //if(search(i,j,rows,cols,board,word,0))
              if(helper(i,j,board,word , 0,rows , cols))
               { 
                      return true;
               }
            }
          }
        }
        return false;
    }
};