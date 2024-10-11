#include<iostream>
#include<queue>
#include<map>
using namespace std;

string non_repeat(string str){ 
    // this is wrong for test case like aaab and anbbb etc where any value is more than 2.
    deque<char> dq;
    string ans ="";

    int str_size= str.size();
    for(int i=0;i<str_size;i++){
        if (dq.empty()){
            dq.push_back(str[i]);
            ans+=str[i];
        }
        else{
            dq.push_back(str[i]);
            if (dq.front() == dq.back()){
                dq.pop_front();
                dq.pop_back();
            }
            if (!dq.empty()){
                ans+=dq.front();
                
            }
            else{
                ans+="#";
            }
        }

    }
    return ans;
}


string string_Non_repeating(string str){
    // mapp needed
    map<char,int> mp;
    // queue also needed,
    queue<char> q;
    string ans = "";
    int mysize = str.size();
    for(int i =0;i<mysize;i++){
        // stire it somewhere
        char demo=str[i];
        //push it to the queue.
        q.push(demo);
        //update the map
        mp[demo] += 1;
        while(!q.empty()){
            if (mp[q.front()] > 1){
                q.pop();
            }

            else{
                ans.push_back(q.front());
                break;
            }
        }

        if(q.empty()){
            ans.push_back('#');
        }
        
    }
    return ans;

}
int main(){
    string str1 = "acdacd";
    string str2="aabc";
    string str3="abad";
    string str4 = "aaab";
    string str = string_Non_repeating(str4);
    cout<<"answer is "<<endl;
    cout<<str<<endl;

    


}
