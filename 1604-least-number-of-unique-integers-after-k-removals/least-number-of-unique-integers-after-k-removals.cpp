class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> mp;
        for(auto it:arr){
            mp[it]++;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto it:mp){
            pq.push(it.second);
        }
        while(k>0 && !pq.empty()){
            k-=pq.top();
            if(k>=0){
                pq.pop();
            }
        }
        return pq.size();
    }
};