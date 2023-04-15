#include <bits/stdc++.h>
using namespace std;

class circularll{
public:
    int data;
    circularll* next;

    circularll(int d){
        this->data = d;
        this->next = NULL;
    }

};

void insertathead(circularll* &tail,int d){

    if(tail == NULL){
        circularll* temp = new circularll(d);
        temp=tail;
        temp->next = temp;
    }
    else{
        circularll* temp = new circularll(d);

        tail->next->next = temp->next;
        tail->next = temp;

    }

}

void print(circularll* &tail){

    circularll* temp = tail;

    if(temp == NULL){
        cout<<"Empty list";
    }
    else{
        do{
            cout<<tail->data<<" ";
            tail = tail->next;
        }while(tail != temp);
        cout<<endl;
    }
}

int main(){

    circularll* first = new circularll(9);

    circularll* head = first;
    circularll* tail = first;

    insertathead(tail,3);
    insertathead(tail,4);
    insertathead(tail,8);

    print(tail);

    return 0;

}