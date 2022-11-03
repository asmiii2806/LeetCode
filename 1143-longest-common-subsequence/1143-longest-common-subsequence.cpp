class Solution {
public:
    
    
    int lengthofLCS(string &text1, string &text2,int i,int j, int m, int n,vector<vector<int>>&v)
    {
        if(i>=m || j>=n)
        {
            return 0;
        }
        int ans=0;
        
        
        if(v[i][j]!=-1)
        {

            return v[i][j];
        }
        
        if(text1[i]==text2[j])
        {
          return 1+lengthofLCS(text1, text2, i+1, j+1, m,n,v);
        }
        
        else
        {
            int a=lengthofLCS(text1, text2, i, j+1, m,n,v);
            int b=lengthofLCS(text1, text2, i+1, j, m,n,v);
            
            v[i][j]=max(a,b);

     
        }
        return v[i][j];
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int m=text1.length();
        int n=text2.length();
        
        vector<vector<int>>v(m+1, vector<int>(n+1,-1));
        
       return lengthofLCS(text1, text2, 0,0,m,n,v);
        
    }
};