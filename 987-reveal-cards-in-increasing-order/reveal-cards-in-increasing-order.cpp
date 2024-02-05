class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        deque<int> dq;
        for(int i=0;i<deck.size();i++){
            dq.push_back(i);
        }
        vector<int> ans(deck.size(),0);
        int i=0;
        while(!dq.empty()){
            ans[dq.front()]=deck[i];
            dq.pop_front();
            int index=dq.front();
            dq.pop_front();
            dq.push_back(index);
            i++;
        }
        return ans;
    }
};