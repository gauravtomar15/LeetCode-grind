class Solution {
    void getAllSubSet(vector<int>& nums ,int i , vector<int> ans ,vector<vector<int>>& allSubSets){
        // base case
        if(i==nums.size()){
            allSubSets.push_back(ans);
            return;
        }
        //include
        ans.push_back(nums[i]);
        getAllSubSet(nums , i+1 , ans, allSubSets);

        ans.pop_back();

        int index = i+1;
        while(index<nums.size() && nums[index]==nums[index-1]) index++;

        // exclude

        getAllSubSet(nums , index , ans, allSubSets);

    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin() , nums.end());

        vector<vector<int>> allSubSets;

        vector<int> ans;

        getAllSubSet(nums, 0, ans, allSubSets);

        return allSubSets;   
    }
};