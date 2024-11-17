


// BRUTE FORCE APPROACH.........

#include<iostream>
#include<vector>
using namespace std;



int median(vector<vector<int>> arr){
    int row = arr.size();
    int col = arr[0].size();
    // total siuze
    int n = row*col;
    // make an array to traverse
    vector<int> head(row,0);
    //now traverse every time and get the smallest one 
    // median position 
    int small = INT_MAX;
    int med_pos = n/2 +1;
    int i =1;
    while(i<=med_pos){
        // check evry element of recent position
        small = INT_MAX;
        int small_i;
        for(int j = 0;j<row;j++){ // here j is row
            if(head[j] <= col-1){
                if(arr[j][head[j]] < small){
                    small = arr[j][head[j]];
                    small_i = j;
                }
            }
        }
        head[small_i]++;
        i++;
    }

    return small;

}
int main(){
    vector<vector<int>> arr = {
        {1,5,7,9,11},
        {2,3,4,5,10},
        {9,10,12,14,16}
    };

    int ans = median(arr);

    cout<<ans<<endl;


}