class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        unordered_map<char,int> need;
        unordered_map<char,int> have;
        string s = "balloon";
        int res = INT_MAX;
        for(int i =0 ; i<s.size() ; i++){
            need[s[i]]++;
        }
        for(int i =0 ; i<n ; i++){
            have[text[i]]++;
        }
        for(auto val : need){
            char c = val.first;
            int fneed =val.second;
            int fhave = have[c];
            int times = fhave/fneed;
            res = min(res , times);
        }
        return res;

    }
};