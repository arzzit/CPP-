#include <bits/stdc++.h>
using namespace std;

class Node
        {
        public:
            int data;
            Node* left;
            Node* right;

            explicit Node(int data)
            {
                this->data = data;
                this->left = nullptr;
                this->right = nullptr;
            }
        };


Node* createbt(Node* &root){

    int data;
    cout<<"Enter data: "<<endl;
    cin>>data;

    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter left for: "<<data<<endl;
    root->left = createbt(root->left);
    cout<<"Enter right for: "<<data<<endl;
    root->right = createbt(root->right);

    return root;
}

void levelordertraversel(Node* root){

    queue<Node*> q;
    q.push(root);

    q.push(NULL);

    while(!q.empty()){

        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;

            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }

    }
}

void inorder(Node* root){
    if(root == NULL)
        return;

    //LNR
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root == NULL)
        return;

    //LRN
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}

void preorder(Node* root){
    if(root == NULL)
        return;

    //NLR
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

void buildfromlot(Node* &root){

    int data;
    queue<Node*> q;
    cout<<"Enter root data : ";
    cin>>data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        int leftdata;
        cout<<"Enter left data for : "<<temp->data;
        cin>>leftdata;
        if(leftdata!=-1){
            temp->left = new Node(leftdata);
            q.push(temp->left);
        }

        int rightdata;
        cout<<"Enter right data for : "<<temp->data;
        cin>>rightdata;
        if(rightdata!=-1){
            temp->right = new Node(rightdata);
            q.push(temp->right);
        }
    }

}

void del_dnode(node* root,node* dnode){

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == dnode){
            temp = NULL;
            delete(dnode);
            return;
        }

        if(temp->right){
            if(temp->right == dnode){
                temp->right = NULL;
                delete(dnode);
                return;
            }
            else{
                q.push(temp->right);
            }
        }

        if(temp->left){
            if(temp->left == dnode){
                temp->left = NULL;
                delete(dnode);
                return;
            }
            else{
                q.push(temp->left);
            }
        }
    }

}

node* deletion(node* root,int key){

    if(root == NULL){
        return NULL;
    }

    if(root->left == NULL && root->right == NULL){
        if(root->data == key){
            return NULL;
        }
        else{
            return root;
        }
    }

    queue<node*> q;
    q.push(root);

    node* key_node = NULL;
    node* temp = NULL;;

    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(temp->data == key){
            key_node = temp;
        }

        if(temp->right){
            q.push(temp->right);
        }

        if(temp->left){
            q.push(temp->left);
        }
    }

    if(key_node!=NULL){
        int x = temp->data;
        del_dnode(root,temp);
        key_node->data = x;
    }
    return root;
}


int main(){

    Node* root = NULL;

    buildfromlot(root);
    levelordertraversel(root);

    return 0;
}