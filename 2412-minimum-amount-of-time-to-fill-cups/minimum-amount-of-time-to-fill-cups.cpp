class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        int count=0;
        for(int i=0;i<amount.size();i++){
            pq.push(amount[i]);
        }
        while(pq.top()!=0){
            vector<int> temp;
            for(int i=1;i<=2;i++){
                if(!pq.empty()){
                    temp.push_back(pq.top()-1);
                    pq.pop();
                }
            }
            for(int i=0;i<temp.size();i++){
                pq.push(temp[i]);
            }
            if(temp.size()==2){
                count++;
            }
            else{
                count+=temp[0];
            }
        }
        return count;

    }
};