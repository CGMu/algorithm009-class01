class Solution {
public: 
    // 1. DFS
    int direct[4][2]={{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0) return 0;
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<bool> > visited(row, vector<bool>(col, false));
        int result=0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]=='1'&&!visited[i][j]){
                    result++;
                    dfs(grid, visited, i, j);
                }
            }
        }
        return result;
    }

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j){
        visited[i][j]=true;
        int rw=grid.size();
        int cl=grid[0].size();
        for(int k=0; k<4; k++){
            int x=i+direct[k][0];
            int y=j+direct[k][1];
            if(inArea(x,y,rw,cl)&&grid[x][y]=='1'&&!visited[x][y]){
                dfs(grid, visited, x, y);
            }
        }
    }

    bool inArea(int i, int j, int row, int col){
        return (i>=0 && i<row && j>=0 && j<col);
    }
};