class Solution {
public:
    /*
        Approach :
        TC => O(n^2)
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
        for(int i =0; i< n ; i++)
        {
            reverse(image[i].begin(), image[i].end());
            flip(image[i], n);
        }
        return image;
    }
};