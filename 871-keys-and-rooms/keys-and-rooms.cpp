class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> ans(n,0);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int room=q.front();
            q.pop();
            ans[room]=1;
            for(int i=0;i<rooms[room].size();i++){
                if(ans[rooms[room][i]]==0){
                    q.push(rooms[room][i]);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(ans[i]==0){
                return false;
            }
        }
        return true;
    }
};