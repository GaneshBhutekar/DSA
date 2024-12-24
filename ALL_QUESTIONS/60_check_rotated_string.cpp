#include<iostream>
#include<vector>



void LSP_array(std::string s1,std::vector<int> &Lsp,int n){
    int prefix = 0;
    int suffix = 1;
    while(suffix<n){
        if (prefix==0 && s1[prefix] != s1[suffix]){
            Lsp[suffix] = 0;
            suffix++;
        }
        else if (s1[prefix]==s1[suffix]){
            Lsp[suffix] = prefix+1;
            suffix++;
            prefix++;
        }
        else{
            prefix = Lsp[prefix-1];
        }
    }
}

bool areRotations(std::string &s1,std::string &s2){
    // first of all find the LSP of the s1
    int n = s1.size();
    int m = s2.size();

    std::vector<int> Lsp(n,0);
    LSP_array(s1,Lsp,n);

    // now i have LSP of s1 now we will start to traverse
    int for_s1 = 0;
    int for_s2=0;
    while(for_s2<m){
        if (s1[for_s1] == s2[for_s2]){
            // if this is the case then increament man
            ++for_s1;
            ++for_s2;
        }
        else{
            // move the for_s1 again to the 0
            if (for_s1==0){
                for_s2++;
            }
            else{
                for_s1 = Lsp[for_s1-1];
            }
        }
    }
    // after this if it is completed it means that for_s1 is n also then it is true
    if (for_s1 == n){
        return true;
    }
    if (for_s1 ==0){
        return false;
    }
    for_s2=0;
    while(for_s1<n){
        if (s1[for_s1] != s2[for_s2]){
            return false;
        }
        ++for_s1;
        ++for_s2;
    }
    return true;

}
int main(){
    std::string s1 = "aaaab";
    std::string s2 = "aabaa";
    if (areRotations(s1,s2)){
        std::cout<<"yes it is rotated"<<std::endl;
    }
    else{
        std::cout<<"no it is not rotated \"NOT MATCHED\""<<std::endl;
    }
}