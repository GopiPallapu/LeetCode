class Solution {
public:
        void merge(vector<int>& arr , int low , int mid , int high){
        vector<int> temp;
        int left=low;
        int right=mid+1;
        while(left<=mid && right<=high){
            if(arr[left]<arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                right++; 
            }
        }
        while(left<=mid){
            temp.push_back(arr[left]);
                left++;
        }
        while(right<=high){
            temp.push_back(arr[right]);
                right++;
        }
        for(int i=low;i<=high;i++){
            arr[i] = temp[i-low];
        }

    }
    // best/avg/worst time complexity - O(n*log n)---- space complexity - O(n)
    void mergeSort(vector<int>& arr, int l, int r) {
        // Write Your Code Here
        if(l>=r)return;
        int mid = (l+r)/2;
        mergeSort(arr , l,mid);
        mergeSort(arr , mid+1 ,r);
        merge(arr , l,mid,r);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0,nums.size()-1);
        return nums;
    }
};