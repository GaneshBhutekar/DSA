#include<iostream>
#include<vector>
#include<queue>
using namespace std;

string solve(string str){
    string ans = "";
    int n = str.size();
    char x= str[0];
    int cnt=0;
    for(int i =0;i<n;i++){
        if(str[i] != x){
            char num = cnt+'0';
            ans.push_back(num);
            ans.push_back(x);
            x=str[i];
            cnt=0;
        }
        cnt++;
    }
    char num = cnt+'0';
    ans.push_back(num);
    ans.push_back(x);

    return ans;
}

void solve1(queue<char> &d){
    int n = d.size();
    int cnt =0;
    char x= d.front();
    for(int i =0;i<n;i++){
        if (d.front() != x ){
            char num = cnt + '0';
            d.push(num);
            d.push(x);
            cnt=0;
            x= d.front();
        }
        cnt++;
        d.pop();
    }
    char num = cnt + '0';
    d.push(num);
    d.push(x);

}
string countAndSay(int n ){
    // string str = "1";
    queue<char> d;
    d.push('1');
    for(int i  = 1;i<n;i++){
        // str = solve(str);
        solve1(d);
    }

    string str = "";
    while(!d.empty()){
        str.push_back(d.front());
        d.pop();
    }
    return str;
}
int main(){
    int n;
    cout<<"enter number "<<endl;
    cin>>n;

    string str = countAndSay(n);
    cout<<str<<endl;
}