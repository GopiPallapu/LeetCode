class Solution {
public:
    void merge(vector<int>& arr , long long low , long long mid , long long high)
    {
        vector<long long > temp;
        long long int left =low;
        long long int right = mid+1;
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left <= mid){
            temp.push_back(arr[left]);
                left++;
        }
        while(right <= high){
             temp.push_back(arr[right]);
             right++;
        }
         // transfering all elements from temporary to arr //
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
        
    }
   long long int countPairs(vector<int>& arr,long long low,long long mid,long long  high)
   {
     long long int count=0;
     long long right = mid+1;
     for(int i=low;i<=mid;i++){
       while(right<=high && (long)arr[i] > 2* (long)arr[right]){
         right++;
       }
       count +=right-(mid+1);
     }
     return count;
   }
   int mergeSort(vector<int>& arr ,long long low,long long  high)
    {
        long long int count =0;
        if(low >= high)return count;
        int mid = low +(high-low)/2;
        count +=mergeSort(arr,low,mid);
        count +=mergeSort(arr,mid+1,high);
        count +=countPairs(arr,low,mid,high);
        merge(arr,low,mid,high);
        return (int)count;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};