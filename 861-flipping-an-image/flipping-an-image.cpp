class Solution {
public:
    /*
        Approach :
        TC => O(n^2) == Optimized solution is doing XOR to get bits to be flipped.
        and swapped from first and last position TC => O(n)
        SC => O(1)
    */
    void flip(vector<int>& row , int n)
    {
        for(int i =0 ;i < n;i++)
        {
           row[i] =  row[i] == 1? 0:1;
        }
    }
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n =image.size();
       /* for(int i =0; i< n ; i++)
        {
            reverse(image[i].begin(), image[i].end());
            flip(image[i], n);
        }*/
        for(int i =0;i< n;i++)
        {
            for(int j = 0 ;j< (n+1)/2;j++)
            {
                int temp  =image[i][j]^1;
                image[i][j] = image[i][n-1-j]^1;
                image[i][n-1-j] = temp;
            }
        }
        return image;
    }
};