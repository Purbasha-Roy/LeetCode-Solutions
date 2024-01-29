class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> s(forbidden.begin(),forbidden.end());
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
        s.insert(0);
        while(!q.empty()){
            int cod=q.front().first;
            int jump=q.front().second.first;
            int prev=q.front().second.second;
            q.pop();
            if(cod==x) return jump;
            int forward=cod+a;
            int backward=cod-b;
            if(prev==0 && backward>=0 && s.find(backward)==s.end()){
                q.push({backward,{jump+1,1}});
                s.insert(backward);
            }
            if(forward<=10000 && s.find(forward)==s.end()){
                q.push({forward,{jump+1,0}});
                s.insert(forward);
            }
        }
        return -1;
    }
};