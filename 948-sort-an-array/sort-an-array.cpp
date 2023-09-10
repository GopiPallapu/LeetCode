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
    int partitionArray(vector<int>& input, int start, int end) {
	// Write your code here
	int pivot = input[start];
	int i=start;
	int j=end;
	while(i<j){
		while(input[i]<=pivot && i<end){
			i++;
		}
		while(input[j]>=pivot && j>start){
			j--;
		}
		 if (i < j)
		 {
			 int temp = input[i];
			 input[i] = input[j];
			 input[j] = temp;
		 } 
	}
	 int temp = input[start];
	input[start] = input[j];
	input[j] = temp;
	return j;
}
// best/avg/worst time complexity - O(n*log n)---- space complexity - O(1)
void quickSort(vector<int>& input, int start, int end) {
	
	if(start<end){
		int partitionIndex = partitionArray(input, start, end);
		quickSort(input, start, partitionIndex-1);
		quickSort(input, partitionIndex+1, end);
	}
}
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0,nums.size()-1);
        return nums;
    }
};