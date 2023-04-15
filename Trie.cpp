#include <bits/stdc++.h>
using namespace std;

class Trienode{
public:
    char data;
    Trienode* arr[26]{};
    bool isterminal;

    explicit Trienode(char ch){
        data = ch;
        isterminal = false;
        for(auto & i : arr){
            i = nullptr;
        }
    }
};

class Trie{
public:
    Trienode* root;

    Trie(){
        root = new Trienode('\0');
    }

    void insertutil(Trienode* root,string word){

        if(word.length() == 0){
            root->isterminal = true;
            cout<<"Inserted"<<endl;
            return;
        }

        int index = word[0] - 'A';
        Trienode* child;

        if(root->arr[index] != nullptr){
            child = root->arr[index];
        }
        else{
            child = new Trienode(word[0]);
            root->arr[index] = child;
        }

        insertutil(child,word.substr(1));
    }

    void insertword(string word){
        insertutil(root,word);
    }

    bool searchutil(Trienode* root,string word){

        if( word.length() == 0 ){
            return root->isterminal;
        }

        int index = word[0] - 'A';
        Trienode* child;

        if(root->arr[index] != nullptr){
            child = root->arr[index];
        }
        else{
            return false;
        }

        return searchutil(child,word.substr(1));
    }

    bool searchword(string word){
        return searchutil(root,word);
    }

    void removeutil(Trienode* root,string word){

        if(word.length() == 0){
            root->isterminal = false;
            cout<<"Removed"<<endl;
            return;
        }

        int index = word[0] - 'A';

        if(root->arr[index] != NULL){
            removeutil(root->arr[index],word.substr(1));
        }
        else{
            cout<<"Exist nahi karta"<<endl;
        }

    }

    void removeword(string word){
        return removeutil(root,word);
    }


};

int main(){

    Trie* first_t = new Trie();

    first_t->insertword("HEY");

    if(first_t->searchword("HEY")){
        cout<<"Yaasss"<<endl;
    }
    else{
        cout<<"Noopp"<<endl;
    }
    first_t->removeword("HEY");

    if(first_t->searchword("HEYI")){
        cout<<"Yaasss";
    }
    else{
        cout<<"Noopp";
    }

    return 0;

}










