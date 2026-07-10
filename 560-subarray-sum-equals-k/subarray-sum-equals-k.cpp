class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //Step 1: Brute Force
//Generate every subarray.
//for(i)
  //  for(j)
    //    calculate sum

    unordered_map<int,int> mp;

        mp[0] = 1;

        int pre = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {

            pre += nums[i];

            if (mp.find(pre - k) != mp.end())
                ans += mp[pre - k];

            mp[pre]++;
        }

        return ans;
        
    }
};