class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
       int n = colors.size();
  int cost = 0;
	  for (int i = 1; i < n; i++) {
				if (colors[i] == colors[i - 1]) {   // curr color = prev color
				  cost = cost + min(neededTime[i], neededTime[i - 1]);  // add min time out of the two time
				  
				  /*
				if curtime < prev time then in that case we update current with larger time this is because after removing the smaller time ballon larger time balloon will be left and at each iteration we are comparing the current ballon with the just previous ballon  
				*/
				  if (neededTime[i] < neededTime[i - 1]) 
					neededTime[i] = neededTime[i - 1];
				}
	  }
  return cost;  
    }
};