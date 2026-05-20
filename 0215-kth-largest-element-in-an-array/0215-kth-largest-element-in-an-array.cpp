class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
      
        priority_queue<int,vector<int>, greater<int>> pq;
        int n = arr.size();
        for(int i =0 ; i<n;i++){
            if(pq.size()<k){
                pq.push(arr[i]);
            } else if(pq.top()<arr[i]){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();

        
    }
};