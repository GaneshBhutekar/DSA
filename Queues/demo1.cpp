#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,int> M;
    M[1]+=3;
    M[4] += 100;
    for(auto i: M){
        cout<<i.first<< " AND "<<i.second<<endl;
    }
}