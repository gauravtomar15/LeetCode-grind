class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<vector<int>>& ans, int idx, vector<int>& curr){
     if(target<0){
        return;
     }   

     if(target == 0){
        ans.push_back(curr);
        return;
     }

     for(int i = idx ; i<candidates.size(); i++){
        if(i>idx && candidates[i]==candidates[i-1]){
            continue;
        }

        curr.push_back(candidates[i]);  //Do
        solve(candidates, target-candidates[i], ans, i+1,curr); // Explore
        curr.pop_back();// Undo
     }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(begin(candidates), end(candidates));

        solve(candidates, target, ans, 0, curr);

        return ans;
    }
};