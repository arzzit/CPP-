#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};

void inserthead(Node* &n1,int d){

    Node* temp = new Node(d);
    temp->next = n1;
    n1 = temp;
}

void inserttail(Node* &n1,int d){

    Node* temp = new Node(d);
    n1->next = temp;
    n1 = temp;

}

void print(Node* &head){
    Node* temp = head;

    while(temp!=0){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void insertat(Node* &head,Node* &tail,int pos,int d){

    if(pos == 1){
        inserthead(head,d);
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count < pos - 1){
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL){
        inserttail(tail,d);
        return;
    }

    Node* atthis = new Node(d);

    atthis->next = temp->next;
    temp->next = atthis;
}

void removeat(Node* &head,int pos){

    if(pos == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;

        delete temp;
    }
    else{
        int count = 1;
        Node* curr = head;
        Node* prev = NULL;

        while(count < pos){
            prev = curr;
            curr = curr->next;
            count++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main() {

    Node* n1 = new Node(10);

    print(n1);
    cout<<endl;

    Node* head = n1;
    Node* tail = n1;

    inserthead(head,18);

    print(head);
    cout<<endl;

    inserttail(tail,16);
    inserttail(tail,14);

    print(head);
    cout<<endl;

    insertat(head,2,19);

    print(head);
    cout<<endl;

    insertat(head,5,13);

    removeat(head,1);

    print(head);
    cout<<endl;


    return 0;
}