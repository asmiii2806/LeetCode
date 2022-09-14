class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp;
        if(n == 0){
            dp.push_back(0);
            return dp;
        }
        dp = countBits(n-1);
        dp.push_back(dp[n/2] + n%2);
        return dp;
    }
};