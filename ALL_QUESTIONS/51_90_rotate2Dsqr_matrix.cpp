#include<vector>
#include<iostream>
using namespace std;




/*
    Description:
    Given a square matrix mat[][], 
    turn it by 90 degrees in an clockwise direction without using any extra space
*/
void rotate(vector<vector<int>> &mat){
    // i got the logic but don't have the idea how to code it let's see
    int side = mat.size();
    int n = side*side;
    // int traverse = side;
    int level = 0;
    while(level < n/2){
        // 00,11,22 etc
        int top_row = level;
        int right_col = side-level-1;
        int bottom_row = side-level-1;
        int left_col = level;
        int end = side-level*2;
        for(int i =0;i<end-1;i++){
            swap(mat[level][left_col],mat[top_row][side - level-1]);
            swap(mat[level][left_col],mat[side-level-1][right_col]);
            swap(mat[level][left_col],mat[bottom_row][level]);
            left_col++;
            top_row++;
            right_col--;
            bottom_row--;
        }
        level++;
        // traverse-=2;
    }

}

void print2D(vector<vector<int>> mat){
    for(auto i : mat){
        for(int j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
int main(){
    vector<vector<int>> mat = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
        // {1}

    };
    rotate(mat);
    print2D(mat);


}