class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        
        sort(a.begin() , a.end());
        
        int i = 0;
        int j= m-1;
        int minimum = INT_MAX;
        
        while(j<a.size()){
            int diff = a[j] - a[i];
            minimum = min(minimum , diff);
            i++;
            j++;
        }
        return minimum;
    }
};