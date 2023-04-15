#include <bits/stdc++.h>
using namespace std;

int mex(int arr[],int x,int n){

    sort(arr,arr+n);

    int largest = arr[n-1];
    int target = largest +1;

    int s=0;
    bool gotit = false;

    while(!gotit){
        if(arr[s] + x == target){
            gotit = true;
        }
        else if( s == n-1){
            s=0;
            target++;
        }
        else{
            s++;
        }
    }

    int ans = target+1;

    return ans;
}

vector<int> atlash(vector<int> d,vector<int> s){

    vector<pair<int,int>> p;
    pair<int,int> p2;
    vector<int> ans;

    for(int i=0; i<d.size(); i++){
        p2 = make_pair(s[i],d[i]);
        p.push_back(p2);
    }

    for(int i=0; i<p.size(); i++){
        for(int j=i; j<p.size(); j++){
            if(p[i].second == 1 && p[j].second == -1 || p[i].second == -1 && p[j].second == 1){
                if(p[i].first > p[j].first){
                    ans.push_back(i);
                    p.erase(p.begin()+i);
                    p.erase(p.begin()+j);
                }
                else if(p[i].first < p[j].first){
                    ans.push_back(j);
                    p.erase(p.begin()+i);
                    p.erase(p.begin()+j);
                }
                else{
                    p.erase(p.begin()+i);
                    p.erase(p.begin()+j);
                }
            }
        }
    }

    return ans;
}

bool checktotal(vector<int> v,int total){

    int maxscore = v[0];
    int score=0;

    for(int i=1; i<v.size(); i++){
        if( v[i] > maxscore){
            maxscore = v[i];
            score++;
        }
    }

    if(score == total){
        return true;
    }
    else{
        return false;
    }
}

int cost(vector<int> n,vector<int> m,vector<int> t){

    int ans=0;
    vector<int> temp;
    int l = n.size()-1;
    int s=0;

    while(s<=l){

        int val = 0;
        for(int i=0; i<n[s]; i++){
            ++val;
            if(val <= m[s]){
                temp.push_back(val);
            }
        }

        int score = t[s];

        if(checktotal(temp,score)){
            ans++;
            temp.clear();
        }
        else{
            temp.clear();
        }

        s++;

    }

    return ans;

}

int main() {

    vector<int> d = {2,3,4};
    vector<int> s = {3,3,3};
    vector<int> t = {1,2,2};

    int ans = cost(d,s,t);

    cout<<ans;

    return 0;
}