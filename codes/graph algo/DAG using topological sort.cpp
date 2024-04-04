#include<bits/stdc++.h>
using namespace std;
/*
            4
   (4)---------------*(5)
    *  \               |
    |    \             |
  1 |      \ 2         | 1
    |        \         |
    |          *       *
    (0)--*(1)--*(2)--*(3)
        2     3     6

6 7
0 1 2
1 2 3
2 3 6
0 4 1
4 5 4
5 3 1
4 2 2
0
output:
0->4->5->1->2->3
cost:
0 2 3 6 1 5
*/

#define INF 1e5
vector<pair<int,int>> graph[10];
stack<int> st;
vector<int> res; //save after topo sort
vector<int> cost(10,INF); //saving cost
vector<int> parent(10,0); //saving cost
vector<int> vis(10,0);  //saving if visited

void DFS(int node){
    vis[node] = 1;
    for (auto child: graph[node]){
        if (vis[child.first]==0){
            DFS(child.first);
        }
    }
    st.push(node);
}

void topological_sort(int n){
    for (int i =0; i< n; i++){
        if (vis[i]==0)
            DFS(i);
    }
}

void relax(int u, int v, int w){
    if (cost[v]>cost[u]+w){
        cost[v]=cost[u]+w;
        parent[v]=u;
    }
}

void DAG(int src,int n){
    topological_sort(n);
    cost[src]=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        res.push_back(node);
        for(auto child:graph[node])
            relax(node, child.first, child.second);
    }
}

int main(){
    cout<<"note: use 0 based graph and max 10 node. or change code"<<endl;
    int node,edge;
    cin>>node>>edge;
    cout<<"Source : Destination : Weight"<<endl;
    for(int i=0;i<edge;i++){
        int s, d, w;
        cin>>s>>d>>w;
        graph[s].push_back(make_pair(d,w));
    }
    int src;
    cin>>src;
    DAG(src,node);
    cout<<"path from "<<src<<endl;
    for(int i=0; i<res.size(); i++){
        cout<<res[i];
        if(i!=res.size()-1)
            cout<<"->";
    }
    cout<<endl;
    cout <<"cost: "<<endl;
    for (int i = 0; i < node; i++){
        if(cost[i]==INF)
            cout<<"INF ";
        else
            cout <<cost[i]<< " ";
    }
    cout<<endl;
    return 0;
}
