#include<iostream>
#include<vector>
#include<map>
using namespace std;

string smallest_substring(string str,string sub){
    map<char,int> all;
    // initialize the first substring characters in it.
    int n = str.size();
    int sub_n = sub.size();
    for(auto c : sub){
        all[c]++;
    }
    int min_size= INT_MAX;
    int start= 0;
    int cnt=0;

    // to generate all substring
    for(int i =0;i<n;i++){
        for(int j = i;j<n;j++){
            // it will create all the string
                for(int k =i;k<=j;k++){
                    if (all[str[k]] > 0){
                        cnt++;
                    }
                    all[str[k]]--;

                    // check that cnt is euql to sub size or not
                    if (cnt == sub_n){
                        break;
                    }
                }

                if (cnt == sub_n && (j-i+1) < min_size){
                    min_size = j-i+1;
                    start = i;

                }
                // after this done normalize the map all
                all.clear();
                for(auto c: sub){
                    all[c]++;
                }
                cnt=0;

        }

    }

    // start value and size 
    string ans="";
    return str.substr(start,min_size);

}

string smallest_Window(string s,string p){
    // there is runtime error cannot completed this in time
    map<char,int> hash;
    // add initial element
    for(char c:p){
        hash[c]++;
    }
    // after this 
    int start =-1;
    int min_size = INT_MAX;
    int n = s.size();
    int p_n=p.size();
    //starting from
    int st=0;
    // ending of slide
    int ed=0;
    int cnt=0;
    while(ed < n){
        if (hash[s[ed]] > 0){
            cnt++;
        }
        hash[s[ed]]--; 
        while(cnt == p_n){
            // increase  it
            if (ed-st+1 < min_size){
                min_size = ed-st+1;
                start = st;
            }
            hash[s[st]]++;
            if (hash[s[st]] >0){
                cnt--;
            }
            st++;

            
        }


        ed++;
    }

    // till here we will get start and min_value just need to return that substring
    if (start != -1){
        return s.substr(start,min_size);
    }
    return "-1";
}


string smallestWindow1(string s, string p){
    // use of fiexed array instead of hash map
    int arr[26] ={0};
    // insert the pp element in it
    for(char c : p){
        arr[c-'a']++; // this will input the elements of p.
    }

    // requiermemts
    int n = s.size();
    int n_p=p.size();
    int start = -1;
    int min_size = INT_MAX;
    int cnt=0;
    int st=0;
    int ed=0;
    while(ed<n){
        if (arr[s[ed] - 'a'] > 0){
            cnt++;

        }
        arr[s[ed] - 'a']--;
        while(cnt==n_p){
            if (ed-st+1 < min_size){
                start = st;
                min_size = ed-st+1;
            }
            arr[s[st]-'a']++;
            if(arr[s[st] - 'a'] >0){
                cnt--;
            }
            st++;

        }
        ed++;
    }
    if (start != -1){
        return s.substr(start,min_size);
    }
    return "-1";
}
int main(){
    string str ;
    cout<<"enter the string"<<endl;
    cin>>str;
    string sub;
    cout<<"enter the substring "<<endl;
    cin>> sub;
    string ans = smallestWindow1(str,sub);
    cout<<"and the answer is"<<endl;
    cout<<ans<<endl;
    
}