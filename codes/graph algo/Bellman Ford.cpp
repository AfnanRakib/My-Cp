#include<bits/stdc++.h>
using namespace std;
/*
input:
6 9
1 2 6
1 3 4
1 4 5
2 5 -1
3 2 -2
4 3 -2
3 5 3
5 6 3
4 6 -1
1
total update done after iteration n-1
0 3 2 1 3 2
No negative cycle
1) cost: 0 , Path: 1
2) cost: 1 , Path: 1->4->3->2
3) cost: 3 , Path: 1->4->3
4) cost: 5 , Path: 1->4
5) cost: 0 , Path: 1->4->3->2->5
6) cost: 3 , Path: 1->4->3->2->5->6

6 7
1 2 5
2 3 1
2 4 2
5 4 -1
4 6 2
6 5 -3
2 5 1
1
total update done after iteration n-1
0 1 1 4 3 3
Negative cycle exists in path: 4 5 6
*/

priority_queue<pair<int, int>> q;
vector<pair<int,int> > g[1000];
vector<int> dist(1000,INT_MAX);
vector<int> p(1000,-1);
vector<int> updateNo(1000,0);
set<int> st;

void initialize_single_source(int n, int s)
{
    for(int i=0;i<n+1;i++){
        dist[i] = INT_MAX;
        p[i] = i;
    }
    dist[s] = 0;
}

void go(int dest){
    if(p[dest]!=dest){
        go(p[dest]);
        cout<<"->";
    }
    cout<<dest;
}
bool relax(int parent,int child,int weight)
{
    if(dist[parent]+weight < dist[child]){
        dist[child]=dist[parent]+weight;
        p[child]=parent;
        return true;
    }
    return false;
}

void bellman(int source,int node)
{
    initialize_single_source(node,source);
    for(int i=0;i<node-1;i++){
        for(int parent=1;parent<=node;parent++){
            for(auto v:g[parent]){
                int child=v.first;
                int weight=v.second;
                if(relax(parent,child,weight))
                    updateNo[child]++;
            }
        }
    }
    cout<<"total update done after iteration n-1"<<endl;
    for(int i=1;i<=node;i++){
        cout<<updateNo[i]<<" ";
    }
    cout<<endl;
    for(int parent=1;parent<=node;parent++){
        for(auto v:g[parent]){
            int child=v.first;
            int weight=v.second;
            if(relax(parent,child,weight)){
                st.insert(child);
                st.insert(parent);
                updateNo[child]=-1;
            }
        }
    }
    if(st.size()==0){
        cout<<"No negative cycle"<<endl;
        for(int i=1;i<=node;i++){
            cout<<i<<") cost: "<<dist[i]<<" , Path: ";
            go(i);
            cout<<endl;
        }
    }
    else{
        cout<<"Negative cycle exists in path: ";
        for(auto &it:st){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int node,edge;
    cin>>node>>edge;
    cout<<"Source : Destination : Weight"<<endl;
    for(int i=1;i<=edge;i++){
        int s, d, w;
        cin>>s>>d>>w;
        g[s].push_back(make_pair(d,w));
    }
    int source;
    cin>>source;
    bellman(source,node);
    return 0;
}

