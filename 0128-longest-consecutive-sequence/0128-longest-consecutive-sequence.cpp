class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());

        if(n==0) return 0;
        
        int currLen =1;
        int globalLen = 1;

        for(int i =1; i<n; i++){
            if(nums[i]==nums[i-1]){
                continue ;
            }
            if(nums[i]-1==nums[i-1]){
            currLen++;
            } else{
                globalLen = max(globalLen , currLen);
                currLen =1;
            }
        }
        globalLen = max(globalLen , currLen);
        return globalLen;      
        
    }
};