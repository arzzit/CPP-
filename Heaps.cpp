#include <bits/stdc++.h>
using namespace std;

class heap{
public:
    int arr[100];
    int size;

    heap(){
        arr[0] =-1;
        size= 0;
    }

    void insert(int d){

        ++size;
        int index = size;
        arr[index] = d;

        while(index > 1){
            int parent = index/2;

            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void print(){
        for(int i=0; i<=size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void deletionfromheap(){

        if( size == 0){
            cout<<"Hai hi  nae bhai kuch"<<endl;
        }

        arr[1] = arr[size];
        size--;
        int i = 1;

        while ( i < size){
            int left = 2*i;
            int right = 2*i +1;

            if( left < size && arr[i] < arr[left]){
                swap(arr[i],arr[left]);
                i = left;
            }
            else if( right < size && arr[i] < arr[right]){
                swap(arr[i],arr[right]);
                i = right;
            }
            else{
                return ;
            }
        }
    }

};

void heapify(int arr[],int i,int n){

    int max = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[left] > arr[max]){
        max = left;
    }

    if(right <= n && arr[right] > arr[max]){
        max = right;
    }

    if(max != i){
        swap(arr[max],arr[i]);
        heapify(arr,max,n);
    }
}

void heapsort(int arr[],int n){

    int size = n;
    while(size > 1){
        swap(arr[1],arr[size]);
        size--;

        heapify(arr,1,size);
    }
}

int main(){

//    heap h;
//    h.insert(22);
//    h.insert(34);
//    h.insert(43);
//    h.insert(77);

//    cout<<"Before : "<<endl;
//    h.print();
//
//    h.deletionfromheap();
//    cout<<"After : "<<endl;
//    h.print();

    int arr[5] = {89,44,53,65,60};
    int n=5;
//    for(int i=n/2; i>=0; i--){
//        heapify(arr,i,n);
//    }

    heapsort(arr,n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

}










