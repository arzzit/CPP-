#include <bits/stdc++.h>
using namespace std;

void merge(int *arr,int s,int e){

    int mid = s + (e-s)/2;

    int first = mid - s + 1;
    int second = e - mid;

    int *pehli = new int[first];
    int *dusri = new int[second];

    int mainindex = s;
    for(int i=0 ; i<first ;i++){
        pehli[i] = arr[mainindex++];
    }

    mainindex = mid + 1;
    for(int i=0 ; i<second ;i++){
        dusri[i] = arr[mainindex++];
    }

    int len1=0;
    int len2=0;
    mainindex = s;

    while(len1 < first && len2 < second){

        if(pehli[len1] > dusri[len2]){
            arr[mainindex++] = dusri[len2++];
        }
        else{
            arr[mainindex++] = pehli[len1++];
        }
    }

    while (len1 < first){
        arr[mainindex++] = pehli[len1++];
    }
    while (len2 < second){
        arr[mainindex++] = dusri[len2++];
    }

    delete []pehli;
    delete []dusri;
}

void mergesort(int *arr,int s,int e){

    if(s>=e){
        return;
    }

    int mid = s + (e-s)/2;

    mergesort(arr,s,mid);

    mergesort(arr,mid + 1,e);

    merge(arr,s,e);
}

int main() {

    int a[8] = {10,4,2,5,6,3,8,1};

    int n = 8;

    mergesort(a,0,n-1);

    for(int i=0 ;i<n ;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}