#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
8 4
1 2 3 4 5 6 7 8
1 2 3 1
*/

string isSubset(int a1[],int a2[],int n , int m){
    unordered_map<int,int> mp;
    // a2 is subset of a1 so we have to store every a1 frq in map
    for(int i =0;i<n;i++){
        mp[a1[i]]++;

    }

    // now check every element in the mp 
    for(int i =0;i<m;i++){
        if (!mp[a2[i]]){
            return "No";
        }
        mp[a2[i]]--;
    }

    return "Yes";
}


int main(){
    int n = 8;
    int m = 5;
    int a1[n] = {11, 7, 1, 13, 21, 3, 7, 3};
    int a2[m] = {11,7,1,13,21,3,7,3};

    string ans = isSubset(a1,a2,n,m);

    cout<<ans<<endl;

}