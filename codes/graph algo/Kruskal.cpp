#include<bits/stdc++.h>
using namespace std;
/*
          2          19
   (1)--------(2)---------(3)
    | \        |         / |  \9
    |   \      |     17/   |   \
  8 |     \    |25   /     |    (4)
    |    14 \  |   /      5|    /
    |         \| /         |   /1
   (7)--------(6)----------(5)/
          21         13

7 11
1 2 2
2 3 19
3 4 9
4 5 1
5 6 13
6 7 21
7 1 8
1 6 14
2 6 25
3 6 17
3 5 5
T={(2,1),(5,3),(5,4),(6,1),(6,5),(7,1),}
Cost= 43
total edges= 6
          2
   (1)--------(2)
    | \                   (3)
    |   \                  |    (4)
  8 |     \                |    /
    |    14 \             5|   /1
    |         \            |  /
   (7)        (6)----------(5)
                     13
*/
priority_queue<pair<int,pair<int,int>>> E;//w,s,d
vector<pair<int,int>> graph[1000];//d,w
vector<int> colour(1000);//node,color

void Sort_All_Edges(int n){
    for(int i=1; i<=n; i++){
        for(int j=0; j<graph[i].size(); j++){
            int w=(-1)*graph[i][j].second;
            int d=graph[i][j].first;
            E.push({w,{i,d}});
        }
    }
}

void makeset(int node){
    colour[node] = node;
}

int findset(int node){
    return colour[node];
}

void unite(int s, int d,int n){
    int colourable=colour[d];
    for(int i=1; i<=n; i++){
        if(colour[i]==colourable)
            colour[i]=colour[s];
    }
}

set<pair<int, int>> T;
int cost=0;
void kruskal(int n, int e){
    for(int i=1; i<=n; i++){
        makeset(i);
    }
    Sort_All_Edges(n);
    while(!E.empty()){
        int w=(-1)*E.top().first;
        auto p=E.top().second;
        E.pop();
        int s=p.first;
        int d=p.second;
        if(findset(s)!=findset(d)){
            T.insert({s,d});
            unite(s,d,n);
            cost+=w;
        }
    }
}

int main()
{
    int node,edge,num=1;
    map<string,int> nodeNo;
    map<int,string> nodeName;
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
        graph[nodeNo[d]].push_back(make_pair(nodeNo[s],w));
    }
    for(auto &it : nodeNo){
        nodeName[it.second]=it.first;
    }
    kruskal(node,edge);
    cout<<"T={";
    for(auto it:T){
        cout<<"("<<nodeName[it.first]<<","<<nodeName[it.second]<<"),";
    }
    cout<<"}"<<endl<<"Cost= "<<cost<<endl<<"total edges= "<<T.size()<<endl;
    return 0;
}

