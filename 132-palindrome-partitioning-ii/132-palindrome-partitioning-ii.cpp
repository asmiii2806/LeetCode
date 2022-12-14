class Solution {
public:
    
    bool ispalindrome(string &s,int start,int end)
    {
      while(start<=end)
      {
        if(s[start]!=s[end])
            return false;
          
          start++;
          end--;
          
      }
        return true;
        
    }
    
    int minimumCuts(string &s,int start, int end, vector<int>&v)
    {
        if(ispalindrome(s,start,end)){
            return 0;
        }
        
        //string currentkey=to_string(start)+"_"+to_string(end);
        
        if(v[start]!=-1)
        {
            return v[start];
        }
        int totalcuts=INT_MAX;
        
        for(int i=start; i<end; i++)
        {
            if(ispalindrome(s,start,i))
            {
                int ans=1+minimumCuts(s,i+1, end,v);
                totalcuts=min(totalcuts,ans);
                 v[start]=min(totalcuts,ans);
   
            }
            
        }

       return totalcuts;
    }
    
    int minCut(string s) {
        vector<int>v(2001,-1);
        return minimumCuts(s,0,s.length()-1,v);
        
    }
};