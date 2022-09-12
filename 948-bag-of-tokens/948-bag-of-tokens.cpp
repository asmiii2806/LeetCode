class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        	ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		sort(tokens.begin(), tokens.end());
		int score = 0;
		int maxScore = 0;
		int s = 0, e = tokens.size()-1;
		while(s<=e){
			if(tokens[s]<=power){
				power-=tokens[s];
				score++;
				s++;
			}else if(score>=1){
				power+=tokens[e];
				e--;
				score--;
			}else{
				break;
			}
			maxScore=max(maxScore, score);
		}
		return maxScore;
    }
};