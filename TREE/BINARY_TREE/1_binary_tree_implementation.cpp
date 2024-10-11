    // create the binary tree and traverse it through reverse or normally also.
    #include<iostream>
    #include<stack>
    #include<queue>
    using namespace std;

    // class to create the tree node
    class node{
        public:
        int data;
        node* left;
        node* right;
        node(int data){
            this -> data = data;
            this->left = NULL;
            this-> right = NULL;

        }
    };



    // create the binary tree.
    node* createtree(node* &root){
        // get data
        cout<<"enter the data"<<endl;
        int data;
        cin>> data;
        if (data == -1){
            return NULL;
        }
        root = new node(data);


        // for the left.
        cout<<"For left "<<endl;
        root->left = createtree(root->left);
        // for the right.
        cout<<"for right "<<endl;
        root -> right = createtree(root->right);
        return root;
    }

    void normal_traversal(node*root){
        // we need queue for it.
        queue<node*> q;
        // add first element in it.
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            node* demo = q.front();
            q.pop();
            if(demo == NULL){
                cout<<endl;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                cout<<demo->data<<" ";
                if (demo-> left != NULL){
                    q.push(demo->left);
                }
                if (demo->right != NULL){
                    q.push(demo->right);
                }            

            }

        }
    }


    void reverse_traversal(node * root){
        // here we use stack for this by inputing the alll queue inside of it
        queue<node*> q;
        stack<node*> st;
        q.push(root);
        q.push(NULL);
        st.push(root);
        st.push(NULL);
        while(!q.empty()){
            // store the first node of queue.
            node*demo = q.front();
            q.pop();
            if (demo == NULL){
                cout<<endl;
                if (!q.empty()){
                    q.push(NULL);
                    st.push(NULL);
                }
            }
            else{
                if (demo->left != NULL){
                    q.push(demo->left);
                    st.push(demo->left);
                }
                if (demo ->right != NULL){
                    q.push(demo->right);
                    st.push(demo->right);
                }
            }
        }

        // print in reverse.
        while(st.top()  == NULL){
            st.pop();
        }
        while(!st.empty()){
            if (st.top() == NULL){
                cout<<endl;
            }
            else{
                cout<<st.top()->data<<" ";
            }
            st.pop();

        }
    }

    int main(){
        node* root = NULL;
        createtree(root);
        cout<<"normal traversal"<<endl;
        normal_traversal(root);

        reverse_traversal(root);




    }