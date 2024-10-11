#include<iostream>
#include<vector>
using namespace std;



void dfs(vector<vector<char>> &grid,int i,int j,int row,int col){
    // doiing DFS in all directtion just don't encounter with 0
    if (i<0 || j<0 || i>=row || j>=col || grid[i][j] != '1'){
        return;
    }


    // mark it as visited
    grid[i][j] = 'z';

    // process all directtion
    dfs(grid,i-1,j,row,col); // up
    dfs(grid,i-1,j+1,row,col); // up right
    dfs(grid,i,j+1,row,col); // right
    dfs(grid,i+1,j+1,row,col); // bottom right
    dfs(grid,i+1,j,row,col); // down
    dfs(grid,i+1,j-1,row,col); // downleft
    dfs(grid,i,j-1,row,col); // left
    dfs(grid,i-1,j-1,row,col); // left above
}
int numsIsland(vector<vector<char>> &grid){
    // make a copy 
    int row = grid.size(); // for row
    int col = grid[0].size(); // for col
    vector<vector<char>> visited = grid;
    int island=0;
    // check for every element 
    for(int i = 0;i<row;i++){
        for(int j = 0;j<col;j++){
            if(grid[i][j] == '1' ){
                // we got new region
                island++;
                dfs(grid,i,j,row,col);
            }
        }
    }

    return island;
}
int main(){
    vector<vector<char>> grid = {
        {'1','0','0','1','0','1'},
        {'0','1','0','0','0','1'},
        {'1','0','1','0','1','1'}
    };

    int ans = numsIsland(grid);
    cout<<"total islands are "<<ans<<endl;
}