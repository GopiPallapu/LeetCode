class Solution {
public:
    /*
        Approach :
        TC => O(n)
        Sc => O(n)
    */
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<pair<int,int>> v ;
        int n = score.size();
        // make a vector pair to store k th element and it's index
        for(int i =0 ; i < n ; i++)
        {
            v.push_back({score[i][k] , i});
        }
        // sort the vector pair in decreasing order
        sort(v.begin()  , v.end() , greater<pair<int,int>>());
        // create answer vector and store the score vector from v .second position
        vector<vector<int>> answer ;
        for(int i =0 ;i< n ;i++)
        {
            answer.push_back(score[v[i].second]);
        }
        return answer;
    }
};