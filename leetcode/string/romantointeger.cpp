#include<iostream>
#include<vector>
#include<map>
using namespace std;
int romanToInt(string s){

    map<char,int> roman= {
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}
    };
    int n = s.size();
    if (n==1){
        return roman[s[0]];
    }
    // sliding window concept 
    int start =0;
    int end = 1;
    int sum=0;
    while(end <n){
        if (roman[s[start]] >= roman[s[end]]){
            sum+=roman[s[start]];
        }
        else{
            sum-=roman[s[start]];
        }
        start++;
        end++;
    }
    // just add last element
    sum+=roman[s[start]];
    return sum;
}
int main(){
    string s = "III";
    int ans = romanToInt(s);
    cout<<ans<<endl;

}