
// largest One region accept 1 which is horizontly , vertically , diagonally

#include<iostream>
#include<vector>
using namespace std;

bool is_valid(vector<vector<int>> region,vector<vector<int>> visited,int x,int y,int n){
    if ((x <= n-1 && x>=0) && (y <= n-1 && y>= 0) && (region[x][y] == 1) && (visited[x][y] == 0)){
        return true;
    }
    return false;

}


void solve(vector<vector<int>> region,vector<vector<int>> &visited,int n,int x,int y,int &count){


    // you are visited here at x and y position so....
    visited[x][y] =1;
    count+=1;

    // move further
    // Down
    int i = x+1;
    int j = y;
    if (is_valid(region,visited,i,j,n)){
        solve(region,visited,n,i,j,count);
    }

    //Left 
    i = x;
    j = y-1;
    if (is_valid(region,visited,i,j,n)){
        solve(region,visited,n,i,j,count);
    }

    //Right
    i = x;
    j = y+1;
    if (is_valid(region,visited,i,j,n)){
        solve(region,visited,n,i,j,count);
    }

    // Up
    i = x-1;
    j = y;
    if (is_valid(region,visited,i,j,n)){
        solve(region,visited,n,i,j,count);
    }

    // UL
    i = x-1;
    j = y-1;
    if (is_valid(region,visited,i,j,n)){
        solve(region,visited,n,i,j,count);

    }

    // UR
    i = x-1;
    j = y+1;
    if (is_valid(region,visited,i,j,n)){
        solve(region,visited,n,i,j,count);
    }

    // DL
    i = x+1;
    j = y-1;
    if (is_valid(region,visited,i,j,n)){
        solve(region,visited,n,i,j,count);
    }

    // DR
    i = x+1;
    j = y+1;
    if (is_valid(region,visited,i,j,n)){
        solve(region,visited,n,i,j,count);
    }

    return;

}
int maximum_region(vector<vector<int>> region){
    // size 
    int n = region.size();
    // visited region
    vector<vector<int>> visited(n,vector<int>(n,0));
    // check position from where we can start
    int count=0;
    int max_count=0;
    for(int i=0;i<n;i++)    {
        for(int j=0;j<n;j++){
            // starting position
            if (is_valid(region,visited,i,j,n)){
                solve(region,visited,n,i,j,count);
                if (count>max_count){
                    max_count=count;
                }
                count=0;
            }

        }
    }

    return max_count;   

}

int main(){

    vector<vector<int>> region = {
        {1,1,0,0,0,0,0},
        {0,0,1,0,0,1,1},
        {0,1,0,1,0,1,1},
        {1,1,1,0,0,1,0},
        {0,0,0,0,0,0,1},
        {1,1,1,1,1,0,0},
        {1,0,0,0,0,0,1}
    };

    vector<vector<int>> region2={
        {1,1,1},
        {0,0,0},
        {1,1,0}
    };
    int ans = maximum_region(region2);
    cout<<ans<<endl;
    
}