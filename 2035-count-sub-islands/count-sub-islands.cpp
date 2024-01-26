class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int row, int col, bool& issubisland, int m, int n){
        int drow[]={-1,0,1,0};
	    int dcol[]={0,1,0,-1};
        if(grid1[row][col]==0){
            issubisland=false;
        }
        grid2[row][col]=-1;
        for(int i=0;i<4;i++){
            int nr=row+drow[i];
            int nc=col+dcol[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n && grid2[nr][nc]==1){
                dfs(grid1,grid2,nr,nc,issubisland,m,n);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size();
        int n=grid1[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1){
                    bool issubisland=true;
                    dfs(grid1, grid2, i, j, issubisland, m, n);
                    if(issubisland){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};