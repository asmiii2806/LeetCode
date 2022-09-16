class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
         int m = multipliers.size(), n = nums.size(), res= INT_MIN;
        vector<vector<int>> dp(m+1, vector<int>(m+1));
        for(int leni=0; leni<=m; leni++) {
            for(int lenj=0; lenj<=m-leni; lenj++) {
                if(leni and lenj)
                dp[leni][lenj] = max(dp[leni-1][lenj] + multipliers[leni + lenj - 1]*nums[leni-1], dp[leni][lenj - 1] + multipliers[leni + lenj - 1]*nums[n - lenj]);
                else if(leni) 
                    dp[leni][lenj] = dp[leni - 1][lenj] + multipliers[leni + lenj - 1]*nums[leni-1];
                else if(lenj)
                        dp[leni][lenj] = dp[leni][lenj -1] + multipliers[leni + lenj - 1]*nums[n-lenj];
            }
			res = max(res, dp[leni][m - leni]);
        }
        return res;
    }
};