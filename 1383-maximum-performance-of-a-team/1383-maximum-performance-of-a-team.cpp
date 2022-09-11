class Solution {
public:
      static bool compare(pair<int,int> p1,pair<int,int> p2)
    {
        return p1.first>p2.first;
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
       priority_queue<int,vector<int>,greater<int>> pq;
        vector<pair<int,int>> arr(n);
        for(int i=0;i<speed.size();i++)
        {
            arr[i]={efficiency[i],speed[i]};
        }
        sort(arr.begin(),arr.end(),compare);
        
        long long int sum=0,ans=0;
        
        for(int i=0;i<n;i++)
        {
            int sp = arr[i].second;
            int eff = arr[i].first;
            pq.push(sp);
            sum+=sp;
            if(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
            
            ans=max(ans,sum*eff);
            
        }
        return ans%1000000007;
    }  
    
};