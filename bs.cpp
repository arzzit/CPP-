
#include <bits/stdc++.h>
using namespace std;

bool sorted(int *arr,int n){

    if(n == 0 || n == 1){
        return true;
    }

    if(arr[0] > arr[1]){
        return false;
    }
    else{
        bool ans = sorted(arr+1,n-1);
        return ans;
    }
}

int sum(int *arr,int n){

    int ans = 0;

    if(n == 1){
        ans = arr[0];
    }
    else if(n == 0){
        return 0;
    }

    ans = arr[0] + sum(arr+1,n-1);

    return ans;
}

bool haikinahi(int *arr,int n,int target){
    if(n == 0){
        return 0;
    }
    else if(n == 1){
        if(arr[0] == target){
            return 1;
        }
    }

    if(arr[0] == target){
        return 1;
    }
    else{
        bool ans = haikinahi(arr+1,n-1,target);
        return ans;
    }
}

int binarysearch(int *arr,int s,int e,int n,int target){

    int ans = 0;
    int mid = s + (e-s)/2;

    if(n == 0){
        return 0;
    }
    else if(n == 1){
        if(arr[0] == target){
            ans = 0;
            return ans;
        }
    }

    if(arr[mid] == target){
        ans = mid + 1;
        return ans;
    }
    else if(arr[mid] > target){
        return binarysearch(arr,s,mid-1,n,target);
    }
    else{
        return binarysearch(arr,mid+1,e,n,target);
    }
}

int main() {

    int arr[8] = {1,2,3,4,5,6,7,8};

    int n = 8;

    int target = 7;

    int s = 0;

    int e = n-1;

    // if(haikinahi(arr,n,target)){
    //     cout<<"hai bhai !";
    // }
    // else{
    //     cout<<"Bhagja bsdk !";
    // }

    int bs = binarysearch(arr,s,e,n,target);

    cout<<bs;

    return 0;
}