#include<iostream>

#include<vector>

#include<algorithm>
using namespace std;
string longestCommonPrefix(vector<string> strs){
    string ans = "";
    int n = strs.size();
    vector<int> sizes;
    //store every one size at a time
    for(int i = 0;i<n;i++){
        sizes.push_back(strs[i].size());
    }
    bool status = true;
    int charac=0;
    while(status== true && charac < sizes[0]){
        char c = strs[0][charac];
        for(int i=1;i<n;i++){
            if (charac >= sizes[i] || strs[i][charac] != c ){
                status = false;
                break;
            }
        }
        if (status==true){
            ans.push_back(c);
        }
        charac++;
    }
    return ans;
}

string longestCommonPrefix1(vector<string> strs){
    // sort the vector
    sort(strs.begin(), strs.end());
    string ans="";
    // traverse through firstr string
    for(int i =0;i<strs[0].size();i++)
    {
        if (strs[0][i] == strs.back()[i]){
            ans.push_back(strs[0][i]);
        }
        else{
            break;
        }
    }
    return ans;

}

int main(){
    vector<string> strs = {"fought","flaght","flaw","fladge","flask"};
    string ans  = longestCommonPrefix1(strs);
    cout<<ans<<endl;

}