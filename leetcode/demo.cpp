#include<iostream>
#include<vector>
using namespace std;
float median(vector<int> &num1, vector<int> &num2){
    vector<int> mergeit;
    int i=0;
    int j =0;
    int size1=num1.size();
    int size2=num2.size();
    while(i<size1 && j<size2){
        if (num1[i]<=num2[j]){
            mergeit.push_back(num1[i]);
            i++;
        }
        else{
            mergeit.push_back(num2[j]);
            j++;
        }
    }
    while(i<size1){
        mergeit.push_back(num1[i]);
        i++;
    }
    while(j<size2){
        mergeit.push_back(num2[j]);
        j++;
    }

    // after merging find median.
    float median_value;
    if ((size1+size2)&1){
        median_value=mergeit[(size1+size2)/2];
    }
    else{
        int value=(size1+size2)/2;

        median_value=(mergeit[value-1]+mergeit[value])/2.0;
    }
    return median_value;
}

//median without extra space....
float median_approach_2(vector<int> num1,vector<int> num2){
    int i=0;
    int j=0;
    int value1;
    int value2;
    int count=0;
    int index2=(num1.size()+num2.size())/2;
    int index1=((num1.size()+num2.size())/2)-1;

    while(i<num1.size() && j<num2.size()){
        if (num1[i]<=num2[j]){
            if (count==index1){
                value1=num1[i];
            }
            if(count==index2){
                value2=num1[i];
            }
            count++;
            i++;
        }
        else if (num1[i]>num2[j]){
           if (count==index1){
                value1=num2[j];
            }
            if (count==index2){
                value2=num2[j];
            }

            count++;
            j++;
        }
    }

    while(i<num1.size()){
        if (count==index1){
            value1=num1[i];
        }
        if(count==index2){
           value2=num1[i];
        }
        count++;
        i++;

    }
    while(j<num2.size()){
       if (count==index1){
            value1=num2[j];
        }
        if (count==index2){
            value2=num2[j];
        }

        j++;
        count++;

    }

    float median;
    if ((num1.size()+num2.size())&1){
        median=value2;
    }
    else{
        median=(value1+value2)/2.0;
    }
    return median;



}

void median_approach_3()

int main(){
    vector<int> num1= {1,3};
    vector<int> num2= {2,4,19};
    float ans =median(num1,num2);
    cout<<"value is "<<ans<<endl;

    float ans1 = median_approach_2(num1,num2);
    cout<<"median by another approach "<<ans<<endl;

}