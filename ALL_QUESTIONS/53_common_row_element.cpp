#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


vector<int> common_Element(vector<vector<int>> mat){
    int row = mat.size();
    int col = mat[0].size();

    // now get unordered list and insert evry value in it and starting will be 1;
    unordered_map<int,int> mp;
    for(int i = 0;i<col;i++){
        if (!mp[mat[0][i]]){
            mp[mat[0][i]] = 1;

        }

    }

    // start travel from row 1 and go one by cheking
    for(int i = 1;i<row;i++){
        for(int j =0;j<col;j++){
            if (mp[mat[i][j]]== i){
                mp[mat[i][j]]++;
            }
        }        
    }

    // now check the map which value is wqual to the row size
    vector<int> ans;
    for(auto i:mp){
        if (i.second == row){
            ans.push_back(i.first);
        }
    }
    return ans;
}


void print(vector<int> arr){
    for(auto i : arr){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main(){
    vector<vector<int>> mat = {
        {1,2,1,4,8},
        {3,4,8,5,1},
        {8,7,4,3,1},
        {8,1,2,7,4}
    };

    vector<int> ans = common_Element(mat);
    print(ans);
    cout<<ans.size()<<endl;

}