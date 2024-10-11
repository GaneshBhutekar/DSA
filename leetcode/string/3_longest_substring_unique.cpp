#include<iostream>
#include<vector>
#include<map>
using namespace std;
int lengthOfLongestSubstring(string s){
    int n = s.size();
    int cnt =0;
    int max=0;
    int front=0;
    int back = 0;
    map<char,int> store;
    while(front < n){
        if (store[s[front]] > 0){
            store[s[back]]--;
            cnt--;
            back++;
       }
       else{
            cnt++;
            store[s[front]]++;
            // check which is maximum
            if (max < cnt){
                max = cnt;
            }
            front++;
       }
    }
    return max;
}
int main(){
    string s = "abcabcbb";
    int ans = lengthOfLongestSubstring(s);
    cout<<ans<<endl;

}