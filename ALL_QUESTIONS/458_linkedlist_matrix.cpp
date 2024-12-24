#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    ListNode* right;
    ListNode* down;
    Node(int data){
        this ->data = data;
        this ->right= NULL;
        this->down = NULL;  

    }
};


ListNode* constructLinkedLinkedMatrix(vector<vector<int>> & mat){
    // code here
    int row = mat.size();
    int col = mat[0].size();
    ListNode* head = new Node(mat[0][0]);
    ListNode* temp = head;

    for(int i =1;i<col;i++){
        ListNode* node = new Node(mat[0][i]);
        temp->right = node;
        temp = node;
    }



    // first row already done
    ListNode* point = head;
    temp = head;
    for(int i = 1;i<row;i++){
        ListNode* x = new Node(mat[i][0]);
        temp = point;
        temp->down = x;
        for(int j = 1;j<col;j++){
            x = new Node(mat[i][j]);
            temp->down->right = x;
            temp->right->down = x;
            temp = temp->right;

        }
        point = point ->down;
    }

    return head;
}

int main(){

    vector<vector<int>> mat{
        {1,2},
        {3,4}
    };

    ListNode* head = constructLinkedLinkedMatrix(mat);

    // cout<<head->down->down->right->right->data<<endl;
    cout<<head->data<<endl;
    cout<<head->down->data<<endl;
    cout<<head->down->right->data<<endl;

}