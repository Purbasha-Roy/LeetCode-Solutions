class Solution {
public:
    bool dfs(int row, int col,string &s, string word, int p, vector<vector<char>>& board, vector<vector<int>> &vis, int dr[], int dc[]){
        if(s==word){
            return true;
        }
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]==word[p] && vis[nr][nc]==0){
                s=s+board[nr][nc];
                vis[nr][nc]=1;
                if(dfs(nr,nc,s,word,p+1,board,vis,dr,dc)){
                    return true;
                }
                s.pop_back();
                vis[nr][nc]=0;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    string s=word.substr(0,1);
                    vis[i][j]=1;
                    if(dfs(i,j,s,word,1,board,vis,dr,dc)==true){
                        return true;
                    }
                    vis[i][j]=0;
                }
            }
        }
        return false;
    }
};