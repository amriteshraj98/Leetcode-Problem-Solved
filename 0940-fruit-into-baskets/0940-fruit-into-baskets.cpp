class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int ans = 0;
      int r =0 ,l =0,n = fruits.size();
      while(r<n)
      {
        mp[fruits[r]]++;
      while(mp.size()>2)
      {
       if(mp[fruits[l]] == 1)
       {
        mp.erase(fruits[l]);
       }
        else
        {
        mp[fruits[l]]--;
        }
        l++;
      }
       ans = max(r-l+1,ans);
       r++;
    }
    return ans;
    }
};
