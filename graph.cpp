#include <bits/stdc++.h>
using namespace std;

template <typename T>
class graph{
public:
    unordered_map<T,list<T>> g;

    void addedge(T u,T v,bool direction){
        //0 - directed
        //1 - undirected
        g[u].push_back(v);

        if(direction){
            g[v].push_back(u);
        }
    }

    void print(){
        for(auto i : g){
            cout<<i.first<<"->";
            for(auto j : i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};

vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    vector < int > temp[n];

    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        temp[u].push_back(v);
        temp[v].push_back(u);
    }

    vector < vector < int >> adj;

    for(int i=0; i<n; i++){
        adj[i].push_back(i);

        for(int j=0; j<temp[i].size(); j++){
            adj[i].push_back(temp[i][j]);
        }
    }

    return adj;
}


int main(){

//    graph<char> g;
//
//    int n;
//    cout<<"Enter no. of nodes: ";
//    cin>>n;
//
//    int e;
//    cout<<"Enter no. of edges: ";
//    cin>>e;
//
//    for(int i=0; i<e; i++){
//        char u,v;
//        cin>>u>>v;
//        g.addedge(u,v,1);
//    }
//    g.print();

    int n=5;
    vector<int> v(n);

    v = {1,23,4,5,67,5,87,6};


}