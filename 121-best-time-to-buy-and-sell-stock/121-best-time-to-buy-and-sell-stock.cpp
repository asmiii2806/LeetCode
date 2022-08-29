class Solution {
public:
    int dp[100001][2][2];
    int maxProfit(vector<int>& prices)
    {
        // vector<vector<vector<int>>>v(100001,vector<vector<int>>(2,vector<int>(2,-1)));
         memset(dp,-1,sizeof(dp));
         return maximumProfit(prices, 0,1,1);     
    }
    
    int maximumProfit(vector<int>&prices, int currentDay, int canbuy, int transaction)
    {
        if(currentDay>=prices.size() || transaction <= 0)
        {
            return 0;
        }

        if(dp[currentDay][canbuy][transaction]!=-1){
            return dp[currentDay][canbuy][transaction] ;
        }
        
        int idle = maximumProfit(prices, currentDay+1,canbuy,transaction);
        int buy = 0,sell=0;
        if(canbuy)
        {
            buy=-prices[currentDay]+maximumProfit(prices, currentDay+1, 0, transaction);
            return  dp[currentDay][canbuy][transaction]=max(idle, buy);
        }
        else
        {
            sell=prices[currentDay]+maximumProfit(prices, currentDay+1, 1, transaction-1);
            return  dp[currentDay][canbuy][transaction]=max(idle, sell);
            
    }
    }
};