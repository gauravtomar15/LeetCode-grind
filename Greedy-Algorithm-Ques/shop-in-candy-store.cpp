  class Solution {
public:
vector<int> minMaxCandy(vector<int>& prices, int k) {
  int n = prices.size();
  sort(prices.begin() , prices.end());
  int min = 0;
  int buy =0;
  int free = n-1;

  while(buy<=free){
      min = min + prices[buy];
      buy++;
      free = free - k;
  }

  buy = n-1;
  free = 0;
  int max =0;

  while(free<=buy){
      max = max + prices[buy];
      buy--;
      free = free + k;
  }

  vector<int> ans;
  ans.push_back(min);
  ans.push_back(max);

  return ans;
}
};
