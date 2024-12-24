#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    ListNode* right;
    ListNode* left;
    Node(int data){
        this->data = data;
        this ->right = NULL;
        this ->left = NULL;
    }
};

ListNode* buildtree(ListNode* &root){
    int data;
    cout<<"enter the data"<<endl;
    cin>>data;
    if (data == -1){
        return NULL;
    }

    root = new Node(data);
    cout<<"for left "<<endl;
    root->left = buildtree(root->left);
    cout<<"for right "<<endl;
    root->right = buildtree(root->right);

    return root;
}

void level_order(ListNode* root){
    if (root == NULL) return;

    queue<ListNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        ListNode* demo = q.front();
        q.pop();
        if (demo == NULL){
            cout<<endl;
            if (!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<demo->data <<" ";
            if (demo->left){
                q.push(demo->left);
            }
            if (demo->right){
                q.push(demo->right);
            }
        }
    }
}

pair<int,int> solve(ListNode* root){ // this is down to up approach it reach at last and then during returning check maximum
    if (root == NULL){
        return {0,0}; // first count and second sum
    }

    pair<int,int> left = solve(root->left);
    pair<int,int> right = solve(root->right);

    cout<<left.second<<" and "<<right.second<<endl;
    if (left.first == right.first){
        if (left.second >= right.second){
            return {left.first+1,left.second+root->data};

        }
        else{
            return {right.first+1,right.second+root->data};
        }
    }
    if (left.first > right.first){
        return {left.first+1,left.second+root->data};
    }
    else{
        return {right.first+1,right.second+root->data};
    }

}

void top_down_solve(ListNode* root,int len,int &maxlen,int value,int &maxvalue){
    if (root == NULL){
        // here check the maxlen and maxvalue.
        if (maxlen == len){
            if(maxvalue < value){
                maxvalue = value;                
            }
        }

        if (len > maxlen){
            maxlen = len;
            maxvalue = value;
        }
        return;

    }

    // update len and value here
    value = value + root->data;
    // for left
    top_down_solve(root->left,len+1,maxlen,value,maxvalue);
    // for right
    top_down_solve(root->right,len+1,maxlen,value,maxvalue);
    
}


int anotherway(ListNode* root){
    int len = 0;
    int maxlen=0;
    int value=0;
    int maxvalue=0;
    top_down_solve(root,len,maxlen,value,maxvalue);
    return maxvalue;
}
int sumOfLongRootToLeafPath(Node *root){
    pair<int,int> ans = solve(root);
    return ans.second;
    
    
}
int main(){
    Node * root = NULL;
    buildtree(root);
    level_order(root);
    int ans = sumOfLongRootToLeafPath(root);
    cout<<"answer for this question is "<<ans<<endl;
    cout<<"another approach"<<endl;
    ans = anotherway(root);
    cout<<"value here will be "<<ans<<endl;

    // 4 2 7 -1 -1 1 6 -1 -1 -1 5 2 -1 -1 -1
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1 
    // 3 9 -1 -1 9 6 -1 -1 2 -1 -1 
    // 1 2 2 -1 1 -1 -1 8 -1 -1 100 18 -1 -1 -1

}