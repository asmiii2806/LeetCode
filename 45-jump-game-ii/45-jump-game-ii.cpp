class Solution {
public:
    int minStep(vector<int>&nums, int currentIndex,vector<int>&dp)
    {
        if(currentIndex>=nums.size()-1){
            return 0;
        }
        if(dp[currentIndex] != -1){
            return dp[currentIndex];
        }
        int maxJumpFromCurrentEle = nums[currentIndex];
        int ans = 10001;
        for(int i=1; i<= maxJumpFromCurrentEle; i++)
            {
                int jump= 1 + minStep(nums, currentIndex+i,dp);
            ans = min(ans,jump);
            }
        dp[currentIndex] = ans;
        return ans;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(10001, -1);
        return minStep(nums,0,dp);
        
        
    }
};