#include<iostream>
#include<vector>
using namespace std;


vector<int> lps(string str){
    int n = str.size();
    vector<int> ans(n,0);
    int pre=0;
    int suff = 1;
    while(suff < n){
        if (str[pre] == str[suff]){
            ans[suff] = pre+1;
            suff++;
            pre++;
        }
        else{
            if (pre==0){
                ans[suff] = 0;
                suff++;
            }
            else{
                pre = ans[pre-1];
            }
        }

    }
    return ans;
}

vector<int> search(string pat,string txt){
    int pat_n=pat.size();
    int txt_n=txt.size();
    if (pat_n>txt_n){
        return {-1};
    }
    vector<int> LPS = lps(pat);
    int big=0;
    int small=0;
    vector<int> ans;
    while(big < txt_n){
        if (txt[big] == pat[small]){
            big++;
            small++;
            if (small == pat_n){
                ans.push_back(big-small+1);
                small = 0;
                continue;
            }
        }
        else{
            if (small ==0){
                big++;
            }
            else{
                small = LPS[small-1];
            }
        }
    }
    if (ans.size() ==0){
        return {-1};
    }
    return ans;

}
int main(){
    // find lps 
    // then store the indexing of every occurance
    string pat = "geeko";
    string txt = "geeksforgeeks";
    vector<int> ans = search(pat,txt);
    for(int i : ans){
        cout<<i<<" ";
    }
    cout<<endl;

}