#include <bits/stdc++.h>
using namespace std;

class doublyll{
public:
    int data;
    doublyll* prev;
    doublyll* next;

    doublyll(int d){
        this->data = d;
    }

};

void insertathead(doublyll* &head,doublyll* &tail,int d){

    if(head == NULL){
        doublyll* temp = new doublyll(d);
        head = temp;
        tail = temp;
    }else{
        doublyll* temp = new doublyll(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }

}

void insertattail(doublyll* &tail,doublyll* &head,int d){

    if(tail == NULL){
        doublyll* temp = new doublyll(d);
        tail = temp;
        head = temp;
    }
    else{
        doublyll* temp = new doublyll(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }

}

void print(doublyll* &head){
    doublyll* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void insertat(doublyll* &head,doublyll* &tail,int pos,int d){

    if(pos == 1){
        insertathead(head,tail,d);
        return;
    }

    doublyll* temp = head;
    int count = 1;

    while(count < pos - 1){
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL){
        insertattail(tail,head,d);
        return;
    }

    doublyll* atthis = new doublyll(d);

    atthis->next = temp->next;
    temp->next->prev = atthis;
    temp->next = atthis;
    atthis->prev = temp;
}

int main(){

    //    doublyll* first = new doublyll(15);
    doublyll* head = NULL;
    doublyll* tail = NULL;

    insertathead(head,tail,12);

    insertattail(tail,head,10);
    //
    insertat(head,tail,2,5);
    //
    insertat(head,tail,3,9);

    print(head);


    return 0;
}