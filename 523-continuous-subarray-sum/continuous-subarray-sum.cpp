class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>f;
        int sum = 0;
        f[0]=-1;
        for(int i =0; i <nums.size(); i++){
            sum+=nums[i];
            int rem = sum % k;

            if(rem<0)
            rem+=k;

            if(f.find(rem) == f.end()){
                f[rem] = i;
            }
            else{
                if (i - f[rem] >=2 )
                return true;
            }
        }
        return false;
        
    }
};