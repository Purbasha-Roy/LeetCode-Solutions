class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size()*grid.size();
        int numrepeated=0;
        int miss=0;
        vector<int> ans(n+1,0);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                ans[grid[i][j]]+=1;
            }
        }
        for(int i=1;i<=n;i++){
            if(ans[i]==0) miss=i;
            if(ans[i]==2) numrepeated=i;
        }
        return {numrepeated,miss};
    }
};