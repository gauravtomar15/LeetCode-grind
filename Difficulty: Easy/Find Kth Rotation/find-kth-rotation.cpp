class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int res;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(arr[mid]>arr[n-1]){
                low = mid+1;
            }else {
                res = mid;
                high = mid-1;
            }
        }
       return res;
    }
};
