class Solution {
public:
    vector<int> currentElementsInDownwardDirection(int r, int c, int n, int m, vector<vector<int>>& mat)
    {
        vector<int> currentElements = {};
        while(c>=0 && r<n)
        {
            currentElements.push_back(mat[r][c]);
            
            r++;
            c--;
        }
        
        return currentElements;
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> answer ;

        // iterate through all columns and get all diagonal elements
        // first set of elements
        int flag = 1;
        for(int i =0 ; i < m ; i++)
        {
            vector<int> elements = currentElementsInDownwardDirection(0, i, n, m, mat);
            if( flag % 2 !=0 )
            {
                reverse(elements.begin() , elements.end());
            }
            for( int k =0 ; k < elements.size() ; k++)
            {
                answer.push_back(elements[k]);
            }
            flag +=1;
        }

        // iretate through second set of elements from row and get all diagonal elements

        for(int i = 1 ; i < n ; i++)
        {
            vector<int> elements = currentElementsInDownwardDirection(i , m-1, n, m , mat);
            if( flag % 2 != 0 )
            {
                reverse(elements.begin() , elements.end());
            }
            for( int k =0 ; k < elements.size() ; k++)
            {
                answer.push_back(elements[k]);
            }
            flag +=1;
        }

        // return the list
        return answer;

    }
};