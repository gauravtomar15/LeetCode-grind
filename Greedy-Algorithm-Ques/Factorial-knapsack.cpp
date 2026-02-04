class Solution {
public:
    
    static bool cmp(pair<double, int> a, pair<double, int> b) {
        return a.first > b.first;
    }
    
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        
        int n = val.size();
        vector<pair<double, int>> v;
        
        // per unit value store karo
        for(int i = 0; i < n; i++) {
            double perUnitValue = (1.0*val[i]) / wt[i];
            v.push_back({perUnitValue, i});
        }
        
        sort(v.begin(), v.end(), cmp);
        
        double totalValue = 0.0;
        
        for(int i = 0; i < n && capacity > 0; i++) {
            int idx = v[i].second;
            
            if(wt[idx] <= capacity) {
                totalValue += val[idx];
                capacity -= wt[idx];
            } else {
                totalValue += capacity * v[i].first;
                capacity = 0;
            }
        }
        
        return totalValue;
    }
};
