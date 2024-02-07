class Solution {
public:
    void dfs(vector<vector<int>>& image, vector<vector<int>>& vis, int sr, int sc, int col, int color, int delrow[], int delcol[], int n, int m){
        image[sr][sc]=color;
        vis[sr][sc]=1;
        for(int i=0;i<4;i++){
            int nrow=sr+delrow[i];
            int ncol=sc+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==col && !vis[nrow][ncol]){
                dfs(image,vis,nrow,ncol,col,color,delrow,delcol,n,m);
            }
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int col=image[sr][sc];
        int delrow[] = {-1, 0, +1, 0}; 
        int delcol[] = {0, -1, 0, +1};
        dfs(image,vis,sr,sc,col,color,delrow,delcol,n,m);
        return image;
    }
};