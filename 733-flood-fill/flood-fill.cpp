class Solution {
public:
    void helper(int i, int j , vector<vector<int>>& image , int newColor , int oldColor, int n, int m )
    {
        if( i < 0 || j < 0 || i>= n || j >=m || image[i][j] != oldColor)return;
        image[i][j] = newColor;
        helper(i , j+1,image  ,newColor  ,oldColor ,n,m);
        helper(i , j-1,image  ,newColor  ,oldColor,n,m );
        helper(i+1, j,image  ,newColor  ,oldColor,n,m );
        helper(i-1, j,image  ,newColor  ,oldColor,n,m );
        return ;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int oldColor = image[sr][sc];
        if(oldColor == color)return image;
        helper(sr,sc,image,color,oldColor,n,m);
        return image;
    }
};