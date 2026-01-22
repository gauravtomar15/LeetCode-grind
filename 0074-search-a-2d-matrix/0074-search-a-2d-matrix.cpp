class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();  //no. of rows
        int n = matrix[0].size();  // no. of columns
        int start = 0;     // starting point of matix
        int end = m*n-1;   // ending
       
         while(start<=end){
            int mid = start+(end-start)/2;
            int row = mid/n;
            int col = mid%n;
            if(matrix[row][col]>target){
                end = mid-1;
            } else if(matrix[row][col]<target){
                start =mid+1;
            } else {
                 return true;
            }
         }
        return false;  
    }
};