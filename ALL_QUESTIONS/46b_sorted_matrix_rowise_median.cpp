#include<iostream>
#include<vector>
using namespace std;

int total_less(vector<vector<int>> &matrix,int R,int C,int e){
    // go thriugh evry row and get the total element which is smaller or equal
    int total=0;
    for(int i = 0;i<R;i++){
        // now traverse in the row binary way
        int start = 0;
        int end = C-1;
        int mid = start + (end-start)/2;
        while(start<= end){
            if (matrix[i][mid] <= e){
                start = mid+1;
            }
            else{
                end = mid-1;
            }

            mid = start+(end-start)/2;
        }
        // now the start will be the total element whoch is smaller
        total+=start;
    }
    return total;

}
int median(vector<vector<int>> &matrix,int R,int C){
    // find the size
    int n = R*C;
    // make the limits 
    int start = 1;
    int end = 2000;
    // now go through it
    int mid = start + (end-start)/2;
    int median_pos = n/2 +1;
    while(start <= end){
        // how many are below or equal to the mid
        // total_less will give the tptal number element which is smaller than pr equal to the mid
        int total = total_less(matrix,R,C,mid);
        // now check 
        if (total >= median_pos){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
        mid = start+(end-start)/2;
    }
    // the start have the answer
    return start;
}
int main(){
    vector<vector<int>> matrix = {
        {4,7,9,10,12},
        {1,3,5,6,7},
        {3,5,6,11,13},
        {7,8,9,10,11},
        {5,6,6,8,9}
    };
    int row = matrix.size();
    int col = matrix[0].size();
    int ans = median(matrix,row,col);
    cout<<"answer is "<<ans<<endl;

    
}