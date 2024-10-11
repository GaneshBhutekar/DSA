#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* down;
    Node(int data){
        this ->data = data;
        this ->right= NULL;
        this->down = NULL;  

    }
};


Node* constructLinkedLinkedMatrix(vector<vector<int>> & mat){
    // code here
    int row = mat.size();
    int col = mat[0].size();
    Node* head = new Node(mat[0][0]);
    Node* temp = head;

    for(int i =1;i<col;i++){
        Node* node = new Node(mat[0][i]);
        temp->right = node;
        temp = node;
    }



    // first row already done
    Node* point = head;
    temp = head;
    for(int i = 1;i<row;i++){
        Node* x = new Node(mat[i][0]);
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

    Node* head = constructLinkedLinkedMatrix(mat);

    // cout<<head->down->down->right->right->data<<endl;
    cout<<head->data<<endl;
    cout<<head->down->data<<endl;
    cout<<head->down->right->data<<endl;

}