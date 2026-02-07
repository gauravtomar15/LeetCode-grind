class Solution {
    set<vector<int>> s;
    void getAllCombination(vector<int>& candidates, int i ,int target ,vector<vector<int>>& ans, vector<int>& combin){
        if(i == candidates.size() || target<0 ) return;
        if(target==0){
            if(s.find(combin)== s.end()){
                ans.push_back(combin);
                s.insert(combin);
            }
            return;
        }

        //single
        combin.push_back(candidates[i]);
        getAllCombination(candidates , i+1 , target-candidates[i], ans, combin);

        // multiple
        getAllCombination(candidates , i, target-candidates[i] ,ans , combin);

        combin.pop_back();
        //exclusion
        getAllCombination(candidates, i+1, target, ans , combin);
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    
        vector<vector<int>> ans;
        vector<int> combin;

        getAllCombination(candidates , 0 , target , ans , combin );
        return ans;
 }
};