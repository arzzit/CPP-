#include <bits/stdc++.h>
using namespace std;

void print_a(int n,int *a){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

int partition(int *arr, int s,int e){

    int pivot = arr[s];
    int count = 0;

    for(int i=s+1 ; i<=e ;i++){
        if(arr[i] <= pivot){
            count++;
        }
    }

    int pivotindex = s + count;

    swap(arr[pivotindex],arr[s]);

    int i=s,j=e;

    while( i < pivotindex && j > pivotindex){

        while( arr[i] <= pivot){

            i++;

        }

        while( arr[j] > pivot){

            j--;

        }

        if( i < pivotindex && j > pivotindex ){
            swap(arr[i++],arr[j--]);
        }
    }

    return pivotindex;

}

void quicksort(int *arr,int s,int e){

    if(s>=e){
        return ;
    }

    int p = partition(arr,s,e);

    quicksort(arr,s,p-1);

    quicksort(arr,p+1,e);
}

int main(){

    int a[7] = {88,2,4,1,888,4,5};

    int n = 7;

    quicksort(a,0,n-1);

    print_a(n,a);

    return 0;
}