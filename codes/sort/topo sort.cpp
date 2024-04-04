#include<bits/stdc++.h>
using namespace std;
#define INF 1e5
vector<pair<int,int>> graph[10];
stack<int> stk;
vector<int> res; //save after topo sort
vector<int> vis(10,0);  //saving if visited
map<string,int> nodeNo;
map<int,string> nodeName;

/*
6 7
A B 2
B C 3
C D 6
A E 1
E F 4
F D 1
E C 2
output:
A -> E -> F -> B -> C -> D

9 10
undershots pants 2
pants belt 1
belt jacket 3
shirt belt 6
shirt tie 4
tie jacket 3
undershots shoes 2
pants shoes 1
socks shoes 4
watch watch 5
output:
watch -> socks -> shirt -> tie -> undershots -> pants -> shoes -> belt -> jacket
*/

void DFS(int node){
    vis[node] = 1;
    for (auto child: graph[node]){
        if (vis[child.first]==0){
            DFS(child.first);
        }
    }
    stk.push(node);
}

void topological_sort(int n){
    for (int i =0; i< n; i++){
        if (vis[i]==0)
            DFS(i);
    }
    while(!stk.empty()){
        int node=stk.top();
        stk.pop();
        res.push_back(node);
    }
}

int main(){
    int node,edge,num=0;
    cin>>node>>edge;
    cout<<"Source : Destination : Weight"<<endl;
    for(int i=0;i<edge;i++){
        string s, d;
        int w;
        cin>>s>>d>>w;
        if(!nodeNo.count(s)){
            nodeNo.insert({s,num});
            num++;
        }
        if(!nodeNo.count(d)){
            nodeNo.insert({d,num});
            num++;
        }
        graph[nodeNo[s]].push_back(make_pair(nodeNo[d],w));
    }
    for(auto &it : nodeNo){
        nodeName[it.second]=it.first;
    }
    topological_sort(node);
    for(int i=0;i<node;i++){
        cout<<nodeName[res[i]]<<" -> ";//<<i<<endl;
    }
    return 0;
}
