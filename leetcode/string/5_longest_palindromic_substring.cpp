#include<iostream>
#include<vector>
using namespace std;



// check the stack here
bool check(int start ,int end,string part){
    while(start < end){
        if (part[start] != part[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

// BRUTE FORCE--------------------------------------------------------------------------------------------------------------
string longestPalindrome1(string s){
    int n = s.size();
    int start =0;
    int palindrome_size = -1;
    for(int i =0;i<n;i++){
        for(int j =i;j<n;j++){
            int length = j-i+1;
            if (check(i,j,s)){
                if (palindrome_size < length){
                    start = i;
                    palindrome_size = length;
                }
            }
        }
    }

    // now we have startong point and size so we can written it 
    return s.substr(start,palindrome_size);
}



void printit(vector<vector<int>> check){
    for( auto i: check){
        for(int j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}



// uaing two pointer and memoisation Dynamic Programming --------------------------------------------------------------
string longestPalindrome2(string s){


    int n  = s.size();
    if (n==1){
        return s;
    }
    vector<vector<int>> check(n,vector<int>(n));
    // initialize evry index to 1 because it is a;ready a palindrome
    int max_size = 1;
    int start = 0;
    int i =0;
    int j = i+1;
    while(i < n){
        check[i][i] = 1;
        if (j<n){

            if (s[i] == s[j]){
                check[i][j] = 1;
                int x = j-i+1;
                if (x > max_size){
                    start = i;
                    max_size = x;
                }
            }
        }
        i++;
        j++;
    }

    // now diagonally and pair one is done let's see

    // now we will continue this for other windows 
    i = 2;
    while(i<n){
        int ind2 = i;
        int ind1 = 0;
        while(ind2 < n){
            if (s[ind1] == s[ind2]){
                // check that inner substring is palindrome or not.
                if(check[ind1+1][ind2-1] == 1){
                    check[ind1][ind2] = 1;
                    int x = ind2-ind1+1;
                    if (x > max_size){
                        start = ind1;
                        max_size = x;
                    }
                }
            }
            ind1++;
            ind2++;
        }
        i++;
    }
    return s.substr(start,max_size);
}


string longestPalindrome(string s){
    int n = s.size();
    if (n==1){
        return s;
    }
    // for odd one put in middle only one element
    int max_size = 1;
    int start = 0;
    int i =0;
    while(i<n){
        int back=i;
        int front=i;
        while(back >= 0 && front < n){
            if (s[back]==s[front]){
                int x = front-back+1;
                if (max_size < x){
                    max_size = x;
                    start = back;
                }
            }
            else{
                break;
            }
            front++;
            back--;
        }
        i++;
    }

    // for even one
    i=0;

    while(i<n-1){
        int front = i+1;
        int back = i;
        while(back >=0 && front <n){
            if (s[back] == s[front]){
                int x = front-back+1;

                if (max_size < x){
                    max_size = x;
                    start = back;
                }
            }
            else{
                break;
            }
            back--;
            front++;
        }
        i++;
    }

    return s.substr(start , max_size);
}
int main(){
    string s = "jrjnbctoqgzimtoklkxcknwmhiztomaofwwzjnhrijwkgmwwuazcowskjhitejnvtblqyepxispasrgvgzqlvrmvhxusiqqzzibcyhpnruhrgbzsmlsuacwptmzxuewnjzmwxbdzqyvsjzxiecsnkdibudtvthzlizralpaowsbakzconeuwwpsqynaxqmgngzpovauxsqgypinywwtmekzhhlzaeatbzryreuttgwfqmmpeywtvpssznkwhzuqewuqtfuflttjcxrhwexvtxjihunpywerkktbvlsyomkxuwrqqmbmzjbfytdddnkasmdyukawrzrnhdmaefzltddipcrhuchvdcoegamlfifzistnplqabtazunlelslicrkuuhosoyduhootlwsbtxautewkvnvlbtixkmxhngidxecehslqjpcdrtlqswmyghmwlttjecvbueswsixoxmymcepbmuwtzanmvujmalyghzkvtoxynyusbpzpolaplsgrunpfgdbbtvtkahqmmlbxzcfznvhxsiytlsxmmtqiudyjlnbkzvtbqdsknsrknsykqzucevgmmcoanilsyyklpbxqosoquolvytefhvozwtwcrmbnyijbammlzrgalrymyfpysbqpjwzirsfknnyseiujadovngogvptphuyzkrwgjqwdhtvgxnmxuheofplizpxijfytfabx";
    string ans = longestPalindrome(s);
    cout<<ans<<endl;


}