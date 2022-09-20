class Solution {
public:
    int dp[10001];
    bool maxJump(vector<int>&nums, int currentIndex)
    {
        bool ans=false;
        if(currentIndex>=nums.size()-1)
            return true;
        if(dp[currentIndex]!=-1)
            return dp[currentIndex];
        

        int maxJumpLength=nums[currentIndex];
        
        for(int i=1; i<=maxJumpLength; i++)
        {
            bool t=maxJump(nums, currentIndex+i);
            ans=ans|| t;
        if(ans)
        {
        
       return  dp[currentIndex]=ans;

        }
    }
    return dp[currentIndex]= false;
    }
     
    

    bool canJump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return maxJump(nums, 0);
        
        
    }
};