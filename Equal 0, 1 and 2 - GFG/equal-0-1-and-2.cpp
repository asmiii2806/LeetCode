//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    long long getSubstringWithEqual012(string str)
    {
        long long ans = 0;
    map <pair <long long, long long>, long long> mp;
    int countZero=0,countOnes=0,countTwos=0;
    string currkey= to_string(countOnes-countZero)+"#"+to_string(countTwos-countOnes);
    mp[make_pair(0,0)]=1;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='0')
          countZero+=1;
        else if(str[i]=='1')
           countOnes+=1;
        else
          countTwos+=1;
    pair <int, int> currkey= make_pair(countOnes-countZero,countTwos-countOnes);  
    if(mp.find(currkey)!=mp.end())
    {
         ans+=mp[currkey];
         mp[currkey]+=1;
    }
    else
      mp[currkey]=1;
    }
    return ans;


        // code here
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.getSubstringWithEqual012(s)<<endl;
	}
    return 0;
}

// } Driver Code Ends