//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
        vector <int> v; // creating vector to store result 
    stack<pair<int,int>> s; // creating the pair stack
    for (int i=0;i<n;i++)
    {
      if(s.size()==0) // when stack is empty return -1;
      {
        v.push_back(-1);
      }
      else if (s.size()>0 && s.top().first>price[i]) // when there is element in stack and stack top is greater then array element 
      {
        v.push_back(s.top().second); // take stack top in the result vector 
      }
      else if (s.size()>0 && s.top().first<=price[i] ){ // when there is element in stack and that element is less then array element 
        while (s.size()>0 && s.top().first<=price[i] )// upto when there is element and stack top is less then array's element delete the element from stack
        {
          s.pop(); // delete the element from stack
        }
        if(s.size()==0) // when stack became empty return -1
        {
          v.push_back(-1);
        }
        else
        {
          v.push_back(s.top().second); // else push stack top in the vector 
        }
      }
      s.push({price[i],i}); // take price array and index i inside pair stack
    }
    for (int i=0;i<v.size();i++)
    {
       v[i]=i-v[i]; // subtract normal index from the vector index v[i]
    }
    return v;
        
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends