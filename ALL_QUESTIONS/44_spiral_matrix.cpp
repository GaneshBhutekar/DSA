#include<iostream>
#include<vector>
using namespace std;


void print2D(vector<vector<int>> matrix){
    for(auto i: matrix){
        for(int j :i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
}
vector<int> spirallyTraverse(vector<vector<int>> & mat){
    // get the row size and col.
    int row = mat.size();
    int col = mat[0].size();

    // now with this size make a vector with all false value
    vector<vector<int>> visited(row,vector<int>(col,0));
    vector<int> ans;
    // totak element
    int top_row = 0;
    int bottom_row = row-1;
    int left_col = 0;
    int right_col = col-1;
    while(top_row <= bottom_row && left_col<=right_col){
        // left to right
        for(int m=left_col;m<=right_col;m++){
            // here column is changing but row is same
            ans.push_back(mat[top_row][m]);
                // one element also done
        }
        top_row++;        

        // top to down
        for(int m = top_row;m<=bottom_row;m++){
            ans.push_back(mat[m][right_col]);
        }
        right_col--;

        // right to left
        if (top_row<=bottom_row){

        for(int m = right_col;m>=left_col;m--){
            ans.push_back(mat[bottom_row][m]);
        }
        bottom_row--;
        }

        // down to top
        if (left_col<= right_col){
        for(int m = bottom_row;m>=top_row;m--){
            ans.push_back(mat[m][left_col]);
        }
        left_col++;
        }
    }
    return ans;

}

void print(vector<int> ans){
    for(int i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main(){
    vector<vector<int>> mat = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    vector<int> ans = spirallyTraverse(mat);
    print(ans);


}