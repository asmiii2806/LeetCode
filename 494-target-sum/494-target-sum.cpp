class Solution {
public:
    unordered_map<string, int>mp;
    
    
    int targetsum(vector<int>&nums, int target, int currentvalue)
    {
        if(currentvalue>=nums.size()&& target!=0)
            return 0;
        if(currentvalue==nums.size() && target==0)
            return 1;
        string currentkey=to_string(currentvalue)+" "+to_string(target);
        
        if(mp.find(currentkey)!=mp.end())
            return mp[currentkey];
        
        
            int pos=targetsum(nums, target-nums[currentvalue], currentvalue+1);        
          int neg=targetsum(nums, target+nums[currentvalue], currentvalue+1);
      mp[currentkey]=pos+neg;
       return   pos+neg;
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
       return  targetsum(nums, target, 0);
        
    }
};