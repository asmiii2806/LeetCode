//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int k) 
    {
                int prefixSum=0;
        int maxL=0;
        unordered_map<int,int>mpp;
        mpp[0]=-1; // to handle edge cases
        for(int i=0;i<N;i++)
        {
            prefixSum+=A[i];
            
            if(mpp.find(prefixSum-k)!=mpp.end())
            {
                int len2=i-mpp[prefixSum-k];
                maxL=max(maxL,len2);
            }
            
             
            if(mpp.find(prefixSum)==mpp.end())
            mpp[prefixSum]=i;
        }
        
        return maxL;
    

        // Complete the function
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends