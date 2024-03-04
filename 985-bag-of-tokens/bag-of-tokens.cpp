class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        int left=0;
        int right=n-1;
        int score=0;
        int ans=0;
        sort(tokens.begin(),tokens.end());
        while(left<=right){
            if(power>=tokens[left]){
                power-=tokens[left];
                score+=1;
                ans=max(ans,score);
                left++;
            }
            else{
                power+=tokens[right];
                score-=1;
                right--;
            }
            if(score<0){
                return ans;
            }
        }
        return ans;
    }
};