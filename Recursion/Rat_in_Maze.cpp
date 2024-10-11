#include<iostream>
#include<vector>
using namespace std;

// Rat in the MAZE.


bool checkit(int x,int y,vector<vector<int>>& visited,vector<vector<int>>& maze,int n){
    if((x < n && x >=0) && (y < n && y >=0) && visited[x][y]==0 && maze[x][y]==1){
        return true;
    }
    return false;
}

void process(vector<vector<int>>& maze,int n,vector<vector<int>> visited,vector<string>& total_paths,int srcx,int srcy,string paths){
    if (srcx==n-1 && srcy==n-1){
        total_paths.push_back(paths);
        return;
    }

    visited[srcx][srcy]=1;
    // for down

    int x=srcx+1;
    int y = srcy;
    if (checkit(x,y,visited,maze,n)){
        paths.push_back('D');
        process(maze,n,visited,total_paths,x,y,paths);
        paths.pop_back();
    }

    //for left
    x=srcx;
    y=srcy-1;
    if(checkit(x,y,visited,maze,n)){
        paths.push_back('L');
        process(maze,n,visited,total_paths,x,y,paths);
        paths.pop_back();
    }

    // for right
    x=srcx;
    y=srcy+1;
    if (checkit(x,y,visited,maze,n)){
        paths.push_back('R');
        process(maze,n,visited,total_paths,x,y,paths);
        paths.pop_back();

    }

    // for up
    x=srcx-1;
    y=srcy;
    if (checkit(x,y,visited,maze,n)){
        paths.push_back('U');
        process(maze,n,visited,total_paths,x,y,paths);
        paths.pop_back();
    }

    visited[srcx][srcy]=0;
}


vector<string> rat_in_maze(vector<vector<int>> maze,int n){
    vector<string> total_paths;
    if (maze[0][0]==0){
        return total_paths;
    }
    // string vector to save the output
    // checkbox
    vector<vector<int>> visited = maze;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[i][j]=0;
        }
    }
    int srcx=0;
    int srcy=0;
    string paths="";
    process(maze,n,visited,total_paths,srcx,srcy,paths);
    return total_paths;


}

int main(){
// rat in the maze
    vector<vector<int>> maze={
        {1,1,1,1},
        {1,1,0,1},
        {1,1,0,1},
        {0,1,1,1}
    };
    int n=maze[0].size();
    vector<string> total_paths=rat_in_maze(maze,n);
    for(auto i:total_paths){
        cout<<"path "<<i<<endl;
    }

}
    


    
    
