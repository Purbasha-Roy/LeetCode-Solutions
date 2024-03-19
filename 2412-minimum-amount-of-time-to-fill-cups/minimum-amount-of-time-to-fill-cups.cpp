class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        int count=0;
        for(int i=0;i<amount.size();i++){
            pq.push(amount[i]);
        }
        while(pq.top()!=0){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            a--;
            b--;
            pq.push(a);
            pq.push(b);
            count++;
        }
        return count;

    }
};