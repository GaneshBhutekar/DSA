#include<iostream>
#include<vector>
using namespace std;
vector<int> LPS(string needle){
    int n = needle.size();
    vector<int> ans(n,0);
    int pre=0;
    int suff = 1;
    while(suff < n){
        if (needle[pre] == needle[suff]){
            ans[suff] = pre+1;
            pre++;
            suff++;
        }
        else{
            if (pre == 0){
                ans[suff] = 0;
                suff++;
            }
            else{
                pre = ans[pre-1 ];
            }
        }
    }
    return ans;
}
int strStr(string haystack,string needle){
    int N = haystack.size();
    int n = needle.size();
    if (N < n){
        return -1;
    }

    vector<int> lps = LPS(needle);

    int index  = 0;
    int big=0;
    while(big < N){
        if (haystack[big] == needle[index]){
            big++;
            index++;

            if (index == n){
                return big - n;
            }
        }
        else{
            if (index != 0){
            index = lps[index-1];
            }
            else{
                big++;
            }
        }
    }
    return -1;


}
int main(){
    string haystack = "MISSISSIPI";
    string needle = "ISSIP";
    string haystack1 = "sadbutsad";
    string needle1 = "sad";
    int ans = strStr(haystack1,needle1);
    cout<<"starting index is "<<ans<<endl;

}