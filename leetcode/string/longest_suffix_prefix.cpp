#include<iostream>
#include<vector>
using namespace std;
string lps(string str){
    int n = str.length();
    vector<int> LPS(n,0);
    int pre=0;
    int suff =1;
    while(suff < n){
        if (str[pre] == str[suff]){
            LPS[suff] = pre+1;
            pre++;
            suff++;
        }
        else{
            if (pre == 0){
                LPS[suff] = 0;
                suff++;
            }
            else{
                pre = LPS[pre -1];
            }
        }
    }
    // longest string will be 
    return str.substr(0,LPS[n-1]);
}
int main(){

    string str = "ABCABDABCABDABDAB";
    string str1 = "ABCDEABCD";
    string str2 = "ABA";
    string ans = lps(str2);
    cout<<ans<<endl;

}