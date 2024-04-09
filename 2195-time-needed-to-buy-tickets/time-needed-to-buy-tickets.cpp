class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans=0;
        while(true){
        for(int i=0;i<tickets.size();i++){
            if(tickets[i]>0){
                tickets[i]=tickets[i]-1;
                ans++;
            }
            if(i==k && tickets[i]==0){
                return ans;
            }
        }
        }
        return 0;
    }
};