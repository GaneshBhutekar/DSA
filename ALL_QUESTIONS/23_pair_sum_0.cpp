#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> getPairs(vector<int>& arr){
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;
    int n = arr.size();
    int neg=0;
    int pos = n-1;

    while(neg<pos){
        if (arr[neg]+arr[pos] < 0){
            neg++;
        }
        else if (arr[neg]+arr[pos] > 0){
            pos--;
        }

        else{
            ans.push_back({arr[neg],arr[pos]});
            int tempneg = arr[neg];
            int temppos = arr[pos];
            while(neg < pos && arr[neg] == tempneg){
                neg++;
            }
            while(neg <pos && arr[pos] == temppos){
                pos++;  
            }
        }

    }
    return ans;

}
int main(){
    vector<int>  arr = {4,8,4,2,0,-10,7,3,-7};
    vector<vector<int>> ans = getPairs(arr);

    for(auto i : ans){
        for(int j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<ans.size()<<endl;

}